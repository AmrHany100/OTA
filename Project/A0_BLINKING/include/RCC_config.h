/***************************************************************************************************************************************************/
/*											               Reset and Clock Control Driver								                           */
/* File Name : RCC_config.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 08 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/***************************************************************************************************************************************************/ 
/*                                                                 Configuration															       */
/* RCC Registers: Section 7.3 Page 99																											   */
/***************************************************************************************************************************************************/ 
/* MRCC_CLOCK_TYPE:	MRCC_HSE_CRYSTAL
					MRCC_HSE_RC
					MRCC_HSI
					MRCC_PLL		 */
#define MRCC_CLOCK_TYPE		MRCC_HSE_CRYSTAL

/* MRCC_BYPASS:	RCC_BYBASS_OFF
				RCC_BYBASS_ON  */
/* Note: Select value only if you have  PLL as input clock source */				
#if MRCC_CLOCK_TYPE == MRCC_PLL
	#define MRCC_BYPASS			MRCC_BYBASS_OFF
#endif

/* MRCC_PLL_INPUT:	MRCC_PLL_IN_HSI_DIV_2
					MRCC_PLL_IN_HSE_DIV_2
					MRCC_PLL_IN_HSE		  */
/* Note: Select value only if you have  PLL as input clock source */
#if MRCC_CLOCK_TYPE == MRCC_PLL
	#deffine MRCC_PLL_INPUT		MRCC_PLL_IN_HSE_DIV_2
#endif

/* MRCC_PLL_MUL_VAL:	MRCC_PLL_INPUT_CLOCK_X2	
						MRCC_PLL_INPUT_CLOCK_X3	
						MRCC_PLL_INPUT_CLOCK_X4	
						MRCC_PLL_INPUT_CLOCK_X5	
						MRCC_PLL_INPUT_CLOCK_X6	
						MRCC_PLL_INPUT_CLOCK_X7	
						MRCC_PLL_INPUT_CLOCK_X8	
						MRCC_PLL_INPUT_CLOCK_X9	
						MRCC_PLL_INPUT_CLOCK_X10
						MRCC_PLL_INPUT_CLOCK_X11
						MRCC_PLL_INPUT_CLOCK_X12
						MRCC_PLL_INPUT_CLOCK_X13
						MRCC_PLL_INPUT_CLOCK_X14
						MRCC_PLL_INPUT_CLOCK_X15
						MRCC_PLL_INPUT_CLOCK_X16 */
/* Note: Select value only if you have PLL as input clock source */
#if MRCC_CLOCK_TYPE == MRCC_PLL
	#define MRCC_PLL_MUL_VAL	MRCC_PLL_INPUT_CLOCK_X4
#endif

/* MRCC_CLOCK_TYPE: -16 : 15 */
/* Note: Select value only if you have HSI as input clock source */
#if ((MRCC_CLOCK_TYPE == MRCC_HSI) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_DIV_2))
	#define MRCC_HSI_TRIMMING	0
#endif

/* MRCC_CSS:	MRCC_DISABLE
				MRCC_ENABLE  */
/* Note: Select value only if you have HSE as input clock source */
#if ((MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL)     || (MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL) || \
     (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE))
	#define MRCC_CSS			MRCC_DISABLE
#endif

/* MRCC_MCO_PIN:	MRCC_NO_CLOCK		
                    MRCC_SYSTEM_CLOCK	
                    MRCC_HSI_CLOCK		
                    MRCC_HSE_CLOCK		
                    MRCC_PLL_DIV_2_CLOCK */
#define MRCC_MCO_PIN		MRCC_NO_CLOCK

/* MRCC_ADC_PRESCALLER:	MRCC_PRESCALLER_2
						MRCC_PRESCALLER_4
						MRCC_PRESCALLER_6
						MRCC_PRESCALLER_8 */
#define MRCC_ADC_PRESCALLER		MRCC_PRESCALLER_2

/* MRCC_APB2_PRESCALLER:	MRCC_PRESCALLER_1
							MRCC_PRESCALLER_2
							MRCC_PRESCALLER_4
							MRCC_PRESCALLER_8
							MRCC_PRESCALLER_16 */
#define MRCC_APB2_PRESCALLER	MRCC_PRESCALLER_1

/* MRCC_APB1_PRESCALLER:	MRCC_PRESCALLER_1
							MRCC_PRESCALLER_2
							MRCC_PRESCALLER_4
							MRCC_PRESCALLER_8
							MRCC_PRESCALLER_16 */
#define MRCC_APB1_PRESCALLER	MRCC_PRESCALLER_1

/* MRCC_AHB_PRESCALLER:	MRCC_PRESCALLER_1
						MRCC_PRESCALLER_2
						MRCC_PRESCALLER_4
						MRCC_PRESCALLER_8
						MRCC_PRESCALLER_16
						MRCC_PRESCALLER_64		
						MRCC_PRESCALLER_128		
						MRCC_PRESCALLER_256		
						MRCC_PRESCALLER_512 */
#define MRCC_AHB_PRESCALLER	MRCC_PRESCALLER_1
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                	   Errors                                                                	   */
/***************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|													Errors				  | Return Value											  			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|													RCC_DONE (No-Errors)  |		0x01															  |*/
/*|                                                 RCC_WRONG_BUS		  | 	0x81                                                			  |*/
/*|                                                 RCC_WRONG_PER         | 	0x82                                                			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/***************************************************************************************************************************************************/ 
#endif
/***************************************************************************************************************************************************/ 