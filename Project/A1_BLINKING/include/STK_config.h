/***************************************************************************************************************************************************/
/*                                                              SysTick Timer Driver                                                               */
/* File Name : STK_config.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 2.0.0																		 	    											   */
/* Date      : 11 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef STK_CONFIG_H
#define STK_CONFIG_H

/***************************************************************************************************************************************************/ 
/*                                                                 Configuration															       */
/* STK Registers : Section 4.5.1 Page 151 [Programming Manual]         																			   */
/***************************************************************************************************************************************************/
/* MSTK_CLKSOURCE: 	MSTK_AHB_DIV_8
					MSTK_AHB	   */
#define MSTK_CLKSOURCE	MSTK_AHB_DIV_8

/* MSTK_STATE: 	MSTK_DISABLE
				MSTK_ENABLE  */
#define MSTK_STATE		MSTK_DISABLE

/* MSTK_INTERRUPT: 	MSTK_DISABLE
					MSTK_ENABLE  */
#define MSTK_INTERRUPT	MSTK_DISABLE

/* AHP Clock */
#define MSTK_AHP_CLK	8000000
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                      Info                                                                       */
/***************************************************************************************************************************************************/
/*                                                            Interval Modes Functions                                                             */
/* MSTK_voidSetIntervalSingle  : At under-flow -> Disable STK Interrupt - Stop Timer - Load Zero to STK_LOAD                                       */
/* MSTK_voidSetIntervalPeriodic: At under-flow ->           xx          -     xx     -         xx                                                  */
/* MSTK_voidSetIntervalSpecial : At under-flow -> Disable STK Interrupt -     xx     - Load Zero to STK_LOAD                                       */
/* MSTK_voidStart              : Doesn't use interrupt and Loads Maximum Value to STK_LOAD (0xFFFFFF)                                              */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                	   Errors                                                                	   */
/***************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|													Errors				  | Return Value											  			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|													MSTK_DONE (No-Errors) |		0x01															  |*/
/*|                                                 MSTK_WRONG_CLKSOURCE  | 	0x81                                                			  |*/
/*|                                                 MSTK_WRONG_TIME_UNIT  | 	0x82                                                			  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/***************************************************************************************************************************************************/ 

#endif
/***************************************************************************************************************************************************/ 