/***************************************************************************************************************************************************/
/*											               Reset and Clock Control Driver								                           */
/* File Name : RCC_interface.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 08 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef RCC_INRERFACE_H
#define RCC_INRERFACE_H

/***************************************************************************************************************************************************/ 
/*                                                                  Macros/Enums																   */
/***************************************************************************************************************************************************/ 
typedef enum
{
	MRCC_AHB ,
	MRCC_APB1,
	MRCC_APB2
}MRCC_BusId_Type;

typedef enum
{
	MRCC_DMA1	= 0 ,	// AHB Per
	MRCC_DMA2	= 1 ,
	MRCC_SRAM	= 2 ,
	MRCC_FLITF	= 4 ,
	MRCC_CRC	= 6 ,
	MRCC_FSMC	= 8 ,
	MRCC_SDIO	= 10,
	MRCC_AFIO	= 0 ,	// APB2 Per
	MRCC_IOPA	= 2	,
	MRCC_IOPB		,	
	MRCC_IOPC       ,
	MRCC_IOPD       ,
	MRCC_IOPE       ,
	MRCC_IOPF	    ,
	MRCC_IOPG		,
	MRCC_ADC1       ,
	MRCC_ADC2       ,
	MRCC_TIM1       ,
	MRCC_SPI1       ,
	MRCC_TIM8       ,
	MRCC_USART1     ,
	MRCC_ADC3       ,
	MRCC_TIM9	= 19,
	MRCC_TIM10		,
	MRCC_TIM11		,
	MRCC_TIM2	= 0 ,	// APB1 Per
	MRCC_TIM3       ,
	MRCC_TIM4       ,
	MRCC_TIM5       ,
	MRCC_TIM6       ,
	MRCC_TIM7       ,
	MRCC_TIM12      ,
	MRCC_TIM13      ,
	MRCC_TIM14      ,
	MRCC_WWD	= 11,
	MRCC_SPI2	= 14,
	MRCC_SPI3		,
	MRCC_USART2	= 17,
	MRCC_USART3		,
	MRCC_UART4      ,
	MRCC_UART5      ,
	MRCC_I2C1       ,
	MRCC_I2C2       ,
	MRCC_USB        ,
	MRCC_CAN	= 25,
	MRCC_BKP	= 27,
	MRCC_PWR        ,
	MRCC_DAC        
}MRCC_PerId_Type;
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                              Functions Declaration															   */
/***************************************************************************************************************************************************/ 
/* Initialization */
void MRCC_voidInitSysClock (void);
/* Clock Control to Peripherals */
void MRCC_voidEnableClock  (MRCC_BusId_Type Copy_BusId, MRCC_PerId_Type Copy_PerId);
void MRCC_voidDisableClock (MRCC_BusId_Type Copy_BusId, MRCC_PerId_Type Copy_PerId);
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 