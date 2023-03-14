/***************************************************************************************************************************************************/
/*                                                                    ESP Driver                                                                   */
/* File Name : ESP_config.h																	    										           */
/* Author    : Amr Hany														 		    										   */
/* Version	 : 1.1.1 AKA OTA																 	    											   */
/* Date      : 29 OCT 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : HAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef ESP_CONFIG_H
#define ESP_CONFIG_H

/***************************************************************************************************************************************************/ 
/*                                                                 Configuration															       */
/***************************************************************************************************************************************************/ 
/* HESP_UART_CH:	UART1
					UART2
					UART3 */
#define HESP_UART_CH			UART1

/* define recieving timout for each command that if it exceeded it means no more data */
/* It varies depending on the router and server and also Clock freq, you'll need to try it */
#define HESP_ECHO_TIMEOUT		100
#define HESP_RESET_TIMEOUT		150
#define HESP_MODE_TIMEOUT		150
#define HESP_ROUTER_TIMEOUT		1100000
#define HESP_SERVER_TIMEOUT		300000
#define HESP_SENDLENGTH_TIMEOUT	200
#define HESP_REQUEST_TIMEOUT	2000000
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                      Info                                                                       */
/***************************************************************************************************************************************************/
/*                                                                   AT Commands                                                                   */
/* \r = Enter        																															   */
/* \n = Ctrl+j       																															   */
/* Test                        -> AT\r\n                                                                                                           */
/* Turn off echo               -> ATE0\r\n                                                                                                         */
/* Turn on echo                -> ATE1\r\n                                                                                                         */
/* Reset                       -> AT+RST\r\n                                                                                                       */
/* Module Station              -> AT+CWMODE=1\r\n                                                                                                  */
/* Module Access Point         -> AT+CWMODE=2\r\n                                                                                                  */
/* Module Access Point         -> AT+CWMODE=3\r\n                                                                                                  */
/* Connect to WIFI Network     -> AT+CWJAP_CUR="SSD","Password"\r\n                                                                                */
/* Set Server IP Mode(TCP/UDP) -> AT+CIPSTART="TCP","IP",Port\r\n                                                                                  */
/* Send Data                   -> AT+CIPSEND=<length>\r\n                                                                                          */
/* Get Status File             -> GET url\r\n                                                                                                      */
/***************************************************************************************************************************************************/  

/***************************************************************************************************************************************************/ 
/*                                                                	   Errors                                                                	   */
/***************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												    Errors				  | Return Value											  			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												    HESP_DONE (No-Errors) |		0x01															  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/***************************************************************************************************************************************************/ 

#endif
/***************************************************************************************************************************************************/
