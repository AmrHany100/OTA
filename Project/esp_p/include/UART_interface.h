/***************************************************************************************************************************************************/
/*                                                                   UART Driver                                                                   */
/* File Name : UART_interface.h 																	    										   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 27 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef UART_INRERFACE_H
#define UART_INRERFACE_H

/***************************************************************************************************************************************************/ 
/*                                                                  Macros/Enums																   */
/***************************************************************************************************************************************************/ 
typedef enum
{
	UART1,
	UART2,
	UART3,
	MAX_UARTS
}MUART_CH_Type;
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                              Functions Declaration															   */
/***************************************************************************************************************************************************/
/* Initialization */
void MUART_voidInit                           (void);

/* Configure Baud Rate */
void MUART_voidSetUARTDIV                     (MUART_CH_Type Copy_UARTChannel, u16 Copy_u16UARTDIV);

/* Send Data Synchronous */                    
void MUART_voidSendDataSynch                  (MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data);

/* Receive Data Synchronous */                
void MUART_voidReceiveDataSynch               (MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data, u32 Copy_u32TimeOut);

/* Receive Data Synchronous with Data Length */
void MUART_voidReceiveDataSynchWithDataLength (MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data, u8 Copy_u8DataLength);

/* Receive Data Synchronous Conditional */
u8   MUART_u8ReceiveDataConditional           (MUART_CH_Type Copy_UARTChannel, pu8 Copy_pu8Data);
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 