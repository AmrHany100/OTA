/***************************************************************************************************************************************************/
/*                                                                    ESP Driver                                                                   */
/* File Name : ESP_interface.h 																	    											   */
/* Author    : Amr Hany														 		    										   */
/* Version	 : 1.1.1 Parse 																	 	    											   */
/* Date      : 29 OCT 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : HAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef ESP_INRERFACE_H
#define ESP_INRERFACE_H

/***************************************************************************************************************************************************/ 
/*                                                                  Macros/Enums																   */
/***************************************************************************************************************************************************/ 
/* Nothing Here */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                              Functions Declaration															   */
/***************************************************************************************************************************************************/  
/* Initialization */
void HESP_voidInit                        (void);

/* Connect to WIFI */
void HESP_voidConnectToRouter             (const pu8 Copy_pu8SSD, const pu8 Copy_pu8Password);

/* Connect to Server & Receive Data From Server */
pu8  HESP_u8ConnectToServerAndReceiveData (const pu8 Copy_pu8Mode, const pu8 Copy_pu8IP, const u8 Copy_u8Port, const pu8 Copy_pu8URL);
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 
