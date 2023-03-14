/***************************************************************************************************************************************************/
/*                                                                   UART Driver                                                                   */
/* File Name : UART_config.c 																	    											   */
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

/* Configuration */
#include "UART_config.h"
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                 Configuration															       */
/* UART Registers : Section 27.6 on page 817    																								   */
/***************************************************************************************************************************************************/
const MUART_config_Type MUART_Config[MUART_MAX_CH] = 
{
	{UART_ENABLE , DATA_8BIT, NO_PARITY, ENABLE_BOTH, 0x45},
	{UART_DISABLE, DATA_8BIT, NO_PARITY, ENABLE_BOTH, 0x341},
	{UART_DISABLE, DATA_8BIT, NO_PARITY, ENABLE_BOTH, 0x341}
};
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                      Info                                                                       */
/***************************************************************************************************************************************************/
/* BaudRate = fCK/(16*UARTDIV) then UARTDIV = fCK/(16*BaudRate) 												                                   */
/* EX: BaudRate = 9600 and Fck = 8000000 then UARTDIV = 8000000/(16*9600) = 52.0833 							                                   */
/*     DIV_Mantissa = 52 = 0x34 and DIV_Fraction = 0.083*16 = 1 = 0x1 											                                   */
/*     Baud rate register (USART_BRR) = 0x341		(DIV_Mantissa[11:0] - DIV_Fraction[3:0])					                                   */
/* More Examples: Section 27.3.4 on page 789 - 799					   											                                   */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                	   Errors                                                                	   */
/***************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												  Errors				  | Return Value											  			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												  MSTK_DONE (No-Errors)   |		0x01															  |*/
/*|                                               MUART_WRONG_STATE	      | 	0x81                                                			  |*/
/*|                                               MUART_WRONG_WORD_LENGTH | 	0x82                                                			  |*/
/*|                                               MUART_WRONG_PARITY	  | 	0x83                                                			  |*/
/*|                                               MUART_WRONG_RT_STATE    | 	0x84                                                			  |*/
/*|                                               MUART_WRONG_UARTChannel | 	0x85                                                			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
