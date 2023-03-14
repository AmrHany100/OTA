/***************************************************************************************************************************************************/
/*                                                              SysTick Timer Driver                                                               */
/* File Name : STK_interface.h 																	    										  	   */
/* Auhor     : Amr Hany														 	    											   */
/* Version	 : 2.0.0																		 	    											   */
/* Date      : 11 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef STK_INRERFACE_H
#define STK_INRERFACE_H

/***************************************************************************************************************************************************/ 
/*                                                                  Macros/Enums																   */
/***************************************************************************************************************************************************/ 
typedef enum
{
	MSTK_AHB_DIV_8,
	MSTK_AHB			
}MSTK_CLKSource_Type;

typedef enum 
{
	MSTK_TIME_MS,
	MSTK_TIME_US
}MSTK_TimeUnit_Type;
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                              Functions Declaration															   */
/***************************************************************************************************************************************************/
/* Initialization */
void                MSTK_voidInit                (void);
/* Select Clock Source */
void                MSTK_voidSelectCLKSOurce     (u8 Copy_u8CLKSOurce);
/* Read Clock Source */
MSTK_CLKSource_Type MSTK_ReadCLKSOurce           (void);
/* Synchronous */
void                MSTK_voidSetBusyWait         (u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit);
/* Asynchronous */
void                MSTK_voidSetIntervalSingle   (u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void));
void                MSTK_voidSetIntervalPeriodic (u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void));
void                MSTK_voidSetIntervalSpecial  (u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void));
void                MSTK_voidPauseInterval       (void);
void                MSTK_voidResumeInterval      (void);
void                MSTK_voidStopInterval        (void);
void                MSTK_voidStart               (void);							/* Load Maximum Value */
void                MSTK_voidPause               (void);
void                MSTK_voidResume              (void);
void                MSTK_voidStop                (void);
/* Get Time Value */
u32                 MSTK_u32GetElapsedTime       (MSTK_TimeUnit_Type Copy_Unit);
u32                 MSTK_u32GetRemainingTime     (MSTK_TimeUnit_Type Copy_Unit);
/* Interrupt */
void                MSTK_voidEnableInterrupt	 (void);
void                MSTK_voidDisableInterrupt    (void);
void                MSTK_voidClearInterruptFlag  (void);
u8                  MSTK_u8ReadInterruptFlag     (void);							/* This Function Clears Interrupt Flag */
void                MSTK_voidSetCallBack         (void (*Copy_ptr)(void));
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 