/***************************************************************************************************************************************************/
/*                                                                    ESP Driver                                                                   */
/* File Name : ESP_private.h 																	    											   */
/* Author    : Amr Hany														 		    										   */
/* Version	 : 1.1.1 Parse 																	 	    											   */
/* Date      : 29 OCT 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : HAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef ESP_PRIVATE_H
#define ESP_PRIVATE_H

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/***************************************************************************************************************************************************/ 
/* Magic Numbers */
#define HESP_INITIAL_VALUE	0
#define HESP_0				0
#define HESP_1  			1
#define HESP_2  			2
#define HESP_3  			3
#define HESP_4  			4
#define HESP_5  			5
#define HESP_6  			6
#define HESP_43  			43
#define HESP_100			100
#define HESP_255			255
#define HESP_18000			18000
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                 Global Variables                                                                */
/***************************************************************************************************************************************************/
static u8 HESP_u8Response[HESP_18000];
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                          Private Functions Declaration                                                          */
/***************************************************************************************************************************************************/
/* Check the Command is Valid */
static u8 HESP_u8ValidateCmd      (u32 Copy_u32TimeOut);
static u8 HESP_u8GetDataValidaton (void);
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define HESP_DONE			0X01
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/
