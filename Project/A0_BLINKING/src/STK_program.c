/***************************************************************************************************************************************************/
/*                                                              SysTick Timer Driver                                                               */
/* File Name : STK_program.c 																	    											   */
/* Aurthor   : Amr Hany														 	    											   */
/* Version	 : 2.0.0																		 	    											   */
/* Date      : 11 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                             Header Files Inclusions 															   */
/***************************************************************************************************************************************************/ 
/* Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Own Driver Files */
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                    Functions                                                                    */
/***************************************************************************************************************************************************/
/* Initialization */
void MSTK_voidInit(void)
{
	/* Apply Clock Source */ 
	#if   MSTK_CLKSOURCE == MSTK_AHB_DIV_8
		CLR_BIT(MSTK->CTRL,CLKSOURCE_BIT);
		MSTK_u32Clk = MSTK_AHP_CLK / MSTK_8;
	#elif MSTK_CLKSOURCE == MSTK_AHB
		SET_BIT(MSTK->CTRL,CLKSOURCE_BIT);
		MSTK_u32Clk = MSTK_AHP_CLK;
	#else
		#error("Configuration Error :: Wrong MSTK_CLKSOURCE")
	#endif
	
	/* SysTick State */ 
	#if   MSTK_STATE == MSTK_DISABLE
		CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	#elif MSTK_STATE == MSTK_ENABLE
		SET_BIT(MSTK->CTRL,ENABLE_BIT);
	#else
		#error("Configuration Error :: Wrong MSTK_STATE")
	#endif
	
	/* SysTick Interrupt State */  
	#if   MSTK_INTERRUPT == MSTK_DISABLE
		CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	#elif MSTK_INTERRUPT == MSTK_ENABLE
		SET_BIT(MSTK->CTRL,ENABLE_BIT);
	#else
		#error("Configuration Error :: Wrong MSTK_INTERRUPT")
	#endif
	
	/* return MSTK_DONE; */
}

/* Select Clock Source */
void MSTK_voidSelectCLKSOurce(MSTK_CLKSource_Type Copy_CLKSource)
{
	switch (Copy_CLKSource)
	{
		case MSTK_AHB_DIV_8: 
			CLR_BIT(MSTK->CTRL,CLKSOURCE_BIT);
			MSTK_u32Clk = MSTK_AHP_CLK / MSTK_8; 
			/* return MSTK_DONE; */	
			break;		 
		case MSTK_AHB      : 
			SET_BIT(MSTK->CTRL,CLKSOURCE_BIT); 
			MSTK_u32Clk = MSTK_AHP_CLK;
			/* return MSTK_DONE; */	
			break;	 	 
		default            : /* return MSTK_WRONG_CLKSOURCE; */	break;
	}
}

/* Read Clock Source */
MSTK_CLKSource_Type MSTK_ReadCLKSOurce(void)
{
	MSTK_CLKSource_Type Local_CLKSource = GET_BIT(MSTK->CTRL,CLKSOURCE_BIT);
	return Local_CLKSource;
}

/* Synchronous */
void MSTK_voidSetBusyWait(u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit)
{
	u32 Local_u32Load = MSTK_INITIAL_VALUE;
	/* Restart Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	MSTK->VAL = MSTK_0;
	/* Calculation and Load Ticks to STK_LOAD register */
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: 
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;
		case MSTK_TIME_US:
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */	break;
	}
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Wait till flag is raised when timer counted to 0 */
	while(!(GET_BIT(MSTK->CTRL,COUNTFLAG_BIT)));
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Load Zero to STK_LOAD */
	MSTK->LOAD = MSTK_0;
	MSTK->VAL  = MSTK_0;	
}
	
/* Asynchronous */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void))
{
	u32 Local_u32Load = MSTK_INITIAL_VALUE;
	/* Restart Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	MSTK->VAL  = MSTK_0;
	/* Calculation and Load Ticks to STK_LOAD register */
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: 
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;
		case MSTK_TIME_US:
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */	break;
	}
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Set Mode to Single */
	MSTK_u8IntervalMode = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL,TICKINT_BIT);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void))
{
	u32 Local_u32Load = MSTK_INITIAL_VALUE;
	/* Restart Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	MSTK->VAL  = MSTK_0;
	/* Calculation and Load Ticks to STK_LOAD register */
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: 
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;
		case MSTK_TIME_US:
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */	break;
	}
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Set Mode to Single */
	MSTK_u8IntervalMode = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL,TICKINT_BIT);
}

void MSTK_voidSetIntervalSpecial(u32 Copy_u32Time, MSTK_TimeUnit_Type Copy_Unit, void (*Copy_ptr)(void))
{
	u32 Local_u32Load = MSTK_INITIAL_VALUE;
	/* Restart Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	MSTK->VAL  = MSTK_0;
	/* Calculation and Load Ticks to STK_LOAD register */
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: 
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;
		case MSTK_TIME_US:
			Local_u32Load = Copy_u32Time*(MSTK_u32Clk/MSTK_1000000);
			MSTK->LOAD     = Local_u32Load;
			/* return MSTK_DONE; */	
			break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */	break;
	}
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Set Mode to Single */
	MSTK_u8IntervalMode = MSTK_SPECIAL_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL,TICKINT_BIT);
}

void MSTK_voidPauseInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL,TICKINT_BIT);
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
}

void MSTK_voidResumeInterval(void)
{
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL,TICKINT_BIT);
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);	
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL,TICKINT_BIT);
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Load Zero to STK_LOAD */
	MSTK->LOAD = MSTK_0;
	MSTK->VAL  = MSTK_0;
}

void MSTK_voidStart(void)
{
	/* Load Maximum Value to STK_LOAD */
	MSTK->LOAD = MSTK_0xFFFFFF;
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
}

void MSTK_voidPause(void)
{
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
}

void MSTK_voidResume(void)
{
	/* Start Timer */
	SET_BIT(MSTK->CTRL,ENABLE_BIT);	
}

void MSTK_voidStop(void)
{
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
	/* Load Zero to STK_LOAD */
	MSTK->LOAD = MSTK_0;
	MSTK->VAL  = MSTK_0;
}

/* Get Time Value */
u32  MSTK_u32GetElapsedTime(MSTK_TimeUnit_Type Copy_Unit)
{
	u32 Local_u32TicksValue  = MSTK->LOAD - MSTK->VAL;
	u32 Local_u32ElapsedTime = MSTK_INITIAL_VALUE;
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: Local_u32ElapsedTime = Local_u32TicksValue/(MSTK_u32Clk/MSTK_1000);		/* return MSTK_DONE; */	break;
		case MSTK_TIME_US: Local_u32ElapsedTime = Local_u32TicksValue/(MSTK_u32Clk/MSTK_1000000);	/* return MSTK_DONE; */	break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */																break;
	}
	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(MSTK_TimeUnit_Type Copy_Unit)
{
	u32 Local_u32TicksValue    = MSTK->VAL;
	u32 Local_u32RemainingTime = MSTK_INITIAL_VALUE;
	switch (Copy_Unit)
	{
		case MSTK_TIME_MS: Local_u32RemainingTime = Local_u32TicksValue/(MSTK_u32Clk/MSTK_1000);	/* return MSTK_DONE; */	break;
		case MSTK_TIME_US: Local_u32RemainingTime = Local_u32TicksValue/(MSTK_u32Clk/MSTK_1000000);	/* return MSTK_DONE; */	break;  
		default          : /* return MSTK_WRONG_TIME_UNIT; */																break;
	}
	return Local_u32RemainingTime;
}

/* Interrupt */
void MSTK_voidEnableInterrupt(void)
{
	SET_BIT(MSTK->CTRL,ENABLE_BIT);
}
void MSTK_voidDisableInterrupt(void)
{
	CLR_BIT(MSTK->CTRL,ENABLE_BIT);
}
void MSTK_voidClearInterruptFlag(void)
{
	u8 Local_u8InterruptFlag = GET_BIT(MSTK->CTRL,COUNTFLAG_BIT);
}
u8   MSTK_u8ReadInterruptFlag(void)							/* This Function Clears Interrupt Flag */
{
	u8 Local_u8InterruptFlag = GET_BIT(MSTK->CTRL,COUNTFLAG_BIT); 
	return Local_u8InterruptFlag;
}
void MSTK_voidSetCallBack(void (*Copy_ptr)(void))
{
	MSTK_CallBack = Copy_ptr;
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/