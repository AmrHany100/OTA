/***************************************************************************************************************************************************/
/*                                                                   UART Driver                                                                   */
/* File Name : UART_program.c 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 27 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                             Header Files Inclusions 															   */
/***************************************************************************************************************************************************/ 
/* Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GPIO_interface.h"	// GPIO

/* Own Driver Files */
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                 Global Variables                                                                */
/***************************************************************************************************************************************************/
extern const MUART_config_Type MUART_Config[MUART_MAX_CH];
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                    Functions                                                                    */
/***************************************************************************************************************************************************/
/* Initialization */
void MUART_voidInit(void)
{
	MUART_CH_Type Local_Counter = MUART_INITIAL_VALUE;
	for (Local_Counter=UART1; Local_Counter<MAX_UARTS; Local_Counter++)
	{
		if      (MUART_Config[Local_Counter].UART_State == UART_ENABLE)
		{
			/* Clear Control Registers */
			MUART[Local_Counter]->CR1 = MUART_0;
			MUART[Local_Counter]->CR2 = MUART_0;
			MUART[Local_Counter]->CR3 = MUART_0;
			/* Configure Word Length */
			switch (MUART_Config[Local_Counter].WordLength)
			{
				case DATA_8BIT:
					//CLR_BIT(MUART[Local_Counter]->CR1,M_BIT);	
					/* return MUART_DONE; */	
					break;
				case DATA_9BIT:
					SET_BIT(MUART[Local_Counter]->CR1,M_BIT);		
					/* return MUART_DONE; */	
					break;
				default       : 
					/* return MUART_WRONG_WORD_LENGTH; */ 						
					break;
			}
			/* Configure Parity */
			switch (MUART_Config[Local_Counter].ParityMode)
			{
				case NO_PARITY  :
					//CLR_BIT(MUART[Local_Counter]->CR1,PCE_BIT); 
					/* return MUART_DONE; */	
					break;
				case EVEN_PARITY:
					SET_BIT(MUART[Local_Counter]->CR1,PCE_BIT);	
					//CLR_BIT(MUART[Local_Counter]->CR1,PS_BIT); 	
					/* return MUART_DONE; */	
					break;
				case ODD_PARITY :
					SET_BIT(MUART[Local_Counter]->CR1,PCE_BIT);	
					SET_BIT(MUART[Local_Counter]->CR1,PS_BIT); 	
					/* return MUART_DONE; */
				default         : 
					/* return MUART_WRONG_PARITY; */ 							
					break;
			}
			/* Configure RT State */
			switch (MUART_Config[Local_Counter].RTControl)
			{
				case ENABLE_RECEIVER   :
					//CLR_BIT(MUART[Local_Counter]->CR1,TE_BIT); 
					SET_BIT(MUART[Local_Counter]->CR1,RE_BIT); 
					/* return MUART_DONE; */	
					break;
				case ENABLE_TRANSMITTER:
					SET_BIT(MUART[Local_Counter]->CR1,TE_BIT); 
					//CLR_BIT(MUART[Local_Counter]->CR1,RE_BIT);  	
					/* return MUART_DONE; */	
					break;
				case ENABLE_BOTH       :
					SET_BIT(MUART[Local_Counter]->CR1,TE_BIT); 
					SET_BIT(MUART[Local_Counter]->CR1,RE_BIT);	
					/* return MUART_DONE; */
				default                : 
					/* return MUART_WRONG_RT_STATE; */ 							
					break;
			}
			/* Configure Baud Rate */
			MUART[Local_Counter]->BRR  = MUART_Config[Local_Counter].u32UARTDIV;   
			/* Enable Module */
			SET_BIT(MUART[Local_Counter]->CR1,UE_BIT); 
			/* Initialize Status Register */
			MUART[Local_Counter]->SR = MUART_0;;
		}
		else if (MUART_Config[Local_Counter].UART_State == UART_ENABLE)
		{
			/* Clear Control Registers */
			MUART[Local_Counter]->CR1 = MUART_0;
			MUART[Local_Counter]->CR2 = MUART_0;
			MUART[Local_Counter]->CR3 = MUART_0;
			/* return MUART_DONE; */
		}
		else 
		{
			/* return MUART_WRONG_STATE; */
		}
	}
}

/* Configure Baud Rate */
void MUART_voidSetUARTDIV(MUART_CH_Type Copy_UARTChannel, u16 Copy_u16UARTDIV)
{
	if (Copy_UARTChannel < MAX_UARTS)
	{
		MUART[Copy_UARTChannel]->BRR  = Copy_u16UARTDIV; 
		/* return MUART_DONE; */
	}
	else
	{
		/* return MUART_WRONG_UARTChannel; */
	}
}

/* Send Data Synchronous */
void MUART_voidSendDataSynch(MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data)
{
	if (Copy_UARTChannel < MAX_UARTS)
	{	
		while (*Copy_pu8Data)
		{
			MUART[Copy_UARTChannel]->DR = *Copy_pu8Data;
			while(GET_BIT(MUART[Copy_UARTChannel]->SR,TC_BIT) == MUART_0);
			Copy_pu8Data++;
		}
		/* return MUART_DONE; */
	}
	else
	{
		/* return MUART_WRONG_UARTChannel; */
	}
}

/* Receive Data Synchronous */
void MUART_voidReceiveDataSynch(MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data, u32 Copy_u32TimeOut)
{
	u32 Local_u32TimeOutCounter = MUART_0;
	*Copy_pu8Data               = MUART_0;
	
	if (Copy_UARTChannel < MAX_UARTS)
	{	
		while (GET_BIT(MUART[Copy_UARTChannel]->SR,RXNE_BIT) == MUART_0)
		{
			Local_u32TimeOutCounter++;
			if (Local_u32TimeOutCounter == Copy_u32TimeOut)
			{
				*Copy_pu8Data = MUART_255;
				break;
			}
		}
		if (*Copy_pu8Data == MUART_0)
		{
			*Copy_pu8Data = MUART[Copy_UARTChannel]->DR;
		}
		else
		{
			/* Do Nothing */
		}
		/* return MUART_DONE; */
	}
	else
	{
		/* return MUART_WRONG_UARTChannel; */
	}
}

/* Receive Data Synchronous with Data Length */
void MUART_voidReceiveDataSynchWithDataLength(MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data, u8 Copy_u8DataLength)
{
	if (Copy_UARTChannel < MAX_UARTS)
	{	
		while (Copy_u8DataLength--)
		{
			while(GET_BIT(MUART[Copy_UARTChannel]->SR,RXNE_BIT) == MUART_0);
			*Copy_pu8Data = MUART[Copy_UARTChannel]->DR;
			Copy_pu8Data++;
		}
		/* return MUART_DONE; */
	}
	else
	{
		/* return MUART_WRONG_UARTChannel; */
	}
}

/* Receive Data Synchronous Conditional */
u8   MUART_u8ReceiveDataConditional(MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data)
{
	u8 Local_u8ErrorCode = MUART_1;
	if (GET_BIT(MUART[Copy_UARTChannel]->SR,RXNE_BIT) == MUART_1)
	{
		*Copy_pu8Data = MUART[Copy_UARTChannel]->DR;
	}
	else
	{
		Local_u8ErrorCode = MUART_0;
	}

	return Local_u8ErrorCode;
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/