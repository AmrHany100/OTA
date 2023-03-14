/**************************************************************************/
/* OTA - Final Project - ARM Programming Diploma Online 2020 - IMT School */
/* Author     : Amr Hany                                     */
/* Supervisor : Eng. Ahmed Assaf                                          */
/**************************************************************************/

/**************************************************************************/
/* Site: http://ota.ueuo.com/                                             */
/**************************************************************************/

/**************************************************************************/
/*                        Header Files Inclusions                         */
/**************************************************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "RCC_interface.h"		// RCC
#include "GPIO_interface.h"		// GPIO
#include "UART_interface.h"		// UART
//#include "STK_interface.h"		// STK
#include "FPEC_interface.h"		// FPEC
/* HAL */
#include "ESP_interface.h"		// ESP
/**************************************************************************/

/**************************************************************************/
/*                            Global Variables                            */
/**************************************************************************/
pu8  Global_DataFromESP;
u8   Global_u8DataToParser[50];
u8   Global_u8CopyFlag      = 0;
u8   Global_u8Index         = 0;
u16  Global_u16Counter       = 0;
u8   Global_u8i             = 0;
u8   Global_FirstRecordFlag = 1;
/* New Type */
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;
/**************************************************************************/

/**************************************************************************/
/*                          Functions Declaration                         */
/**************************************************************************/
/* Parse */
void Parser_voidParseRecord(pu8 Copy_pu8BufData);
/**************************************************************************/

/**************************************************************************/
/*                                Functions                               */
/**************************************************************************/
void voidJumbToApp(void)
{
	#define SCB_VTOR   *((volatile u32*)0xE000ED08)
	/* Relocate the vector table */
	SCB_VTOR = 0x08003000;
	/* Jump to application */
	addr_to_call = *(Function_t*)(0x08003004);
	addr_to_call();
}

/* APP - Main */
void main(void)
{
	/* RCC Initialization */
	MRCC_voidInitSysClock();

	/* Enable Clock for */
	MRCC_voidEnableClock(MRCC_APB2,MRCC_IOPA  );	// PORTA
	MRCC_voidEnableClock(MRCC_APB2,MRCC_USART1);	// UART1
	MRCC_voidEnableClock(MRCC_AHB ,MRCC_FLITF );	// FPEC

	/* GPIO */
	MGPIO_voidSetPinDirection(PORTA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);	// TX
	MGPIO_voidSetPinDirection(PORTA,PIN10,INPUT_FLOATING        );	// RX

	/* UARTs Initialization */
	MUART_voidInit();

	/* ESP */
	HESP_voidInit();
	HESP_voidConnectToRouter("Fierro","0101010100");
	Global_DataFromESP = HESP_u8ConnectToServerAndReceiveData("TCP","162.253.155.226",80,"http://ota.ueuo.com/program.txt");

	/* Change Clock Type To HSI for BL */
	MRCC_voidChangeClockTypeToHSI();
	/* STK */
	//MSTK_voidInit();
	//MSTK_voidSetIntervalSingle(15000,MSTK_TIME_MS,voidJumbToApp);
	while(1)
	{
		if ((Global_DataFromESP[Global_u16Counter] == '\r') &&
			(Global_DataFromESP[Global_u16Counter+1] == '\n') &&
			(Global_DataFromESP[Global_u16Counter+2] == '+' ) &&
			(Global_DataFromESP[Global_u16Counter+3] == 'I' ))
		{
			Global_u8CopyFlag = 1;
			Global_u16Counter++;
		}
		else if (Global_u8CopyFlag == 1)
		{
			if (Global_DataFromESP[Global_u16Counter] == ':')
			{
				Global_u8CopyFlag = 0;
			}
			else
			{
				Global_u8CopyFlag = 1;
			}
			Global_u16Counter++;
		}
		else if ((Global_DataFromESP[Global_u16Counter] == 'C') && (Global_DataFromESP[Global_u16Counter+1] == 'L') && (Global_DataFromESP[Global_u16Counter+2] == 'O'))
		{
			voidJumbToApp();
		}
		else if (Global_u8CopyFlag == 0)
		{
			/* Get Data */
			Global_u8DataToParser[Global_u8Index] = Global_DataFromESP[Global_u16Counter];
			Global_u16Counter++;

			/* Stop timer till processing the data */
			//MSTK_voidStopInterval();

			/* '\n' indicate the end of the record */
			if (Global_u8DataToParser[Global_u8Index] == '\n')
			{
				/* With the coming of the first record will erase the App section */
				if (Global_FirstRecordFlag)
				{
					MFPEC_voidEraseAppArea();
					Global_FirstRecordFlag = 0;
				}
				/* Parse Record */
				Parser_voidParseRecord(Global_u8DataToParser);
				/* Initialize the index for the new record */
				Global_u8Index = 0;
				for (Global_u8i=0; Global_u8i<50; Global_u8i++)
				{
					Global_u8DataToParser[Global_u8i] = 0;
				}
			}
			else
			{
				Global_u8Index++;
			}
			//MSTK_voidSetIntervalSingle(15000,MSTK_TIME_MS,voidJumbToApp);
		}
		else
		{
			/* Do Noting */
		}
	}
}
/**************************************************************************/
