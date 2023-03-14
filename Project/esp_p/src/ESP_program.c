/***************************************************************************************************************************************************/
/*                                                                    ESP Driver                                                                   */
/* File Name : ESP_program.c																    											       */
/* Author    : Amr Hany														 		    										   */
/* Version	 : 1.1.1 Parse 																	 	    											   */
/* Date      : 29 OCT 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : HAL				 																	    										   */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                             Header Files Inclusions 															   */
/***************************************************************************************************************************************************/ 
/* Libraries */
#include <string.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"	// UART

/* Own Driver Files */
#include "ESP_interface.h"
#include "ESP_config.h"
#include "ESP_private.h"
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                   Functions																	   */
/***************************************************************************************************************************************************/   
/* Initialization */
void HESP_voidInit(void)
{
	u8 Local_u8ValidFlag = HESP_0;
	do
	{
		/* Reset ESP */
		MUART_voidSendDataSynch(HESP_UART_CH,"AT+RST\r\n");
		Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_RESET_TIMEOUT);
	}while(Local_u8ValidFlag == HESP_0);
	
	Local_u8ValidFlag = HESP_0;
	do
	{
		/*Stop Echo*/
		MUART_voidSendDataSynch(HESP_UART_CH,"ATE0\r\n");
		Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_ECHO_TIMEOUT);
	}while(Local_u8ValidFlag == HESP_0);
	
	Local_u8ValidFlag = HESP_0;
	do
	{
		/*Set ESP Station Mode*/
		MUART_voidSendDataSynch(HESP_UART_CH,"AT+CWMODE=1\r\n");
		Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_MODE_TIMEOUT);
	}while(Local_u8ValidFlag == HESP_0);

	/* return HESP_DONE; */
}

/* Connect to WIFI */
void HESP_voidConnectToRouter(const pu8 Copy_pu8SSD, const pu8 Copy_pu8Password)
{
	u8 Local_u8ValidFlag       = HESP_0;
	u8 Local_Command[HESP_100] = {HESP_0};
	sprintf(Local_Command,"AT+CWJAP_CUR=\"%s\",\"%s\"\r\n",Copy_pu8SSD,Copy_pu8Password);
	
	do
	{
		/* Connect to WIFI */
		MUART_voidSendDataSynch(HESP_UART_CH,Local_Command);
		Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_ROUTER_TIMEOUT);
	}while(Local_u8ValidFlag == HESP_0);
	
	/* return HESP_DONE; */
}	

/* Connect to Server & Receive Data From Server */
pu8   HESP_u8ConnectToServerAndReceiveData(const pu8 Copy_pu8Mode, const pu8 Copy_pu8IP, const u8 Copy_u8Port, const pu8 Copy_pu8URL)
{
	u8 Local_u8Result           = HESP_0;
	u8 Local_u8Counter          = HESP_0;
	u8 Local_u8ValidFlag        = HESP_0;
	u8 Local_Command1[HESP_100] = {HESP_0};
	u8 Local_Command2[HESP_100] = {HESP_0};
	u8 Local_Command3[HESP_100] = {HESP_0};
	u8 Local_u8Length           =  strlen(Copy_pu8URL)+HESP_6;
	sprintf(Local_Command1,"AT+CIPSTART=\"%s\",\"%s\",%i\r\n",Copy_pu8Mode,Copy_pu8IP,Copy_u8Port);
	sprintf(Local_Command2,"AT+CIPSEND=%i\r\n",Local_u8Length);
	sprintf(Local_Command3,"GET %s\r\n",Copy_pu8URL);
	
	do
	{
		/* Connect to Server */
		MUART_voidSendDataSynch(HESP_UART_CH,Local_Command1);
		Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_SERVER_TIMEOUT);
		if (Local_u8ValidFlag == HESP_1)
		{
			Local_u8ValidFlag = HESP_0;
			/* Send Length */
			MUART_voidSendDataSynch(HESP_UART_CH,Local_Command2);
			Local_u8ValidFlag = HESP_u8ValidateCmd(HESP_SENDLENGTH_TIMEOUT);
			if (Local_u8ValidFlag == HESP_1)
			{
				Local_u8ValidFlag = HESP_0;
				/* Send URL */
				MUART_voidSendDataSynch(HESP_UART_CH,Local_Command3);
				Local_u8ValidFlag = HESP_u8GetDataValidaton();
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
	}while(Local_u8ValidFlag == HESP_0);

	return HESP_u8Response;
	/* return HESP_DONE; */
}
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                Private Functions                                                                */
/***************************************************************************************************************************************************/
/* Check the Command is Valid */
static u8 HESP_u8ValidateCmd(u32 Copy_u32TimeOut)
{
	u8 Local_u8ValidFlag = HESP_0;
	u8 Local_u8Iteration = HESP_0;
	u8 Local_u8Counter   = HESP_0;
	u8 Local_u8Temp      = HESP_0;
	
	for (Local_u8Iteration=HESP_0; Local_u8Iteration<HESP_100; Local_u8Iteration++)
	{
		HESP_u8Response[Local_u8Iteration] = HESP_0;
	}
	/* Make sure that the MC is not receiving any more data from the ESP */
	while (Local_u8Temp != HESP_255)
	{
		MUART_voidReceiveDataSynch(HESP_UART_CH,&Local_u8Temp,Copy_u32TimeOut);
		HESP_u8Response[Local_u8Counter] = Local_u8Temp;
		Local_u8Counter++;
	}
	/* Deleting last element (255) */
	HESP_u8Response[Local_u8Counter-HESP_1] = HESP_0;
	/* Checks if any of the received data contains the word "OK" meaning the command is done successfully */
	for (Local_u8Iteration=HESP_0; Local_u8Iteration<Local_u8Counter-HESP_1; Local_u8Iteration++)
	{
		if (((HESP_u8Response[Local_u8Iteration]        == 'O') && (HESP_u8Response[Local_u8Iteration+HESP_1] == 'K')) ||
		    ((HESP_u8Response[Local_u8Iteration]        == 'A') && (HESP_u8Response[Local_u8Iteration+HESP_1] == 'L') &&
			 (HESP_u8Response[Local_u8Iteration+HESP_2] == 'R') && (HESP_u8Response[Local_u8Iteration+HESP_3] == 'E') &&
			 (HESP_u8Response[Local_u8Iteration+HESP_4] == 'A') && (HESP_u8Response[Local_u8Iteration+HESP_5] == 'D') &&
			 (HESP_u8Response[Local_u8Iteration+HESP_6] == 'Y')))
		{
			Local_u8ValidFlag = HESP_1;
		}
	}
	
	return Local_u8ValidFlag;
}

static u8 HESP_u8GetDataValidaton(void)
{
	u8 Local_u8ValidFlag   = HESP_0;
	u8 Local_u8SrartRecord = HESP_0;
	u16 Local_u16Iteration  = HESP_0;
	u16 Local_u16Counter    = HESP_0;
	u8 Local_u8Temp        = HESP_0;
	
	for (Local_u16Iteration=HESP_0; Local_u16Iteration<HESP_18000; Local_u16Iteration++)
	{
		HESP_u8Response[Local_u16Iteration] = HESP_0;
	}
	/* Get HEX Code */
	while (Local_u8Temp != HESP_255)
	{
		MUART_voidReceiveDataSynch(HESP_UART_CH,&Local_u8Temp,HESP_REQUEST_TIMEOUT);
		if (Local_u8SrartRecord == HESP_1)
		{
			HESP_u8Response[Local_u16Counter] = Local_u8Temp;
			if ((HESP_u8Response[Local_u16Counter-HESP_2] == 'C') &&
			    (HESP_u8Response[Local_u16Counter-HESP_1] == 'L') &&
				(HESP_u8Response[Local_u16Counter]        == 'O'))
			{
				Local_u8ValidFlag = HESP_1;
				break;
			}
			Local_u16Counter++;
		}
		else
		{
			if (Local_u8Temp == ':')
			{
				Local_u8SrartRecord = HESP_1;
			}
		}
	}
	
	return Local_u8ValidFlag;
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
