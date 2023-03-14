/***************************************************************************************************************************************************/
/*                                                              SysTick Timer Driver                                                               */
/* File Name : STK_private.h 																	    											   */
/* Auhor     : Amr Hany														 	    											   */
/* Version	 : 2.0.0																		 	    											   */
/* Date      : 11 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/***************************************************************************************************************************************************/ 
/*                                                              Registers Definitions 															   */
/* Address		   : 0xE000E010-0xE000E01F																					   					   */
/* Core peripheral : System timer																							   					   */
/* Register map    : Table 49 on page 154 [Programming Manual]																   					   */  
/***************************************************************************************************************************************************/ 
/* STK Base Address */
#define MSTK_BASE_ADDRESS	0xE000E010

/* STK Register */
typedef struct
{
	volatile u32 CTRL ;				// SysTick control and status register (STK_CTRL)
	volatile u32 LOAD ;				// SysTick reload value register (STK_LOAD)
	volatile u32 VAL  ;				// SysTick current value register (STK_VAL)
	volatile u32 CALIB;				// SysTick calibration value register (STK_CALIB)
}MSTK_Type;

#define MSTK					((volatile MSTK_Type*)MSTK_BASE_ADDRESS)
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                 Registers Bits 			     												   */
/* STK Registers : Section 4.5.1 Page 151 [Programming Manual]         																			   */
/***************************************************************************************************************************************************/ 
/* SysTick control and status register (STK_CTRL) */
#define COUNTFLAG_BIT			16	// Returns 1 if timer counted to 0 since last time this was read
#define CLKSOURCE_BIT			2	// Clock source selection | 0: AHB/8 | 1: Processor clock (AHB)
#define TICKINT_BIT				1	// SysTick exception request enable | 0: Disabled | 1: Counting down to zero
#define ENABLE_BIT				0	// Counter enable | 0: Counter disabled | 1: Counter enabled
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/***************************************************************************************************************************************************/ 
/* Magic Numbers */
#define MSTK_INITIAL_VALUE 		0
#define MSTK_0     				0
#define MSTK_8     				8 
#define MSTK_1000     			1000 
#define MSTK_1000000     		1000000
#define MSTK_0xFFFFFF     		0xFFFFFF

/* States */
#define MSTK_DISABLE			0
#define MSTK_ENABLE 			1

/* Interval Modes */
#define MSTK_SINGLE_INTERVAL	0
#define MSTK_PERIOD_INTERVAL	1
#define MSTK_SPECIAL_INTERVAL	2
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                 Global Variables                                                                */
/***************************************************************************************************************************************************/
static u8  MSTK_u8IntervalMode;		// Define Variable for interval mode
static u32 MSTK_u32Clk;
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                CallBack Functions                                                               */
/***************************************************************************************************************************************************/
#define NULL				((void*)0x00)
static void (*MSTK_CallBack)(void) = NULL;

/* ISR */
void SysTick_Handler(void)
{
	u8 Local_u8Temporary = MSTK_INITIAL_VALUE;
	
	if      (MSTK_u8IntervalMode == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL,TICKINT_BIT);
		/* Stop Timer */
		CLR_BIT(MSTK->CTRL,ENABLE_BIT);
		/* Load Zero to STK_LOAD */
		MSTK->LOAD = MSTK_0;
		MSTK->VAL  = MSTK_0;
	}
	else if (MSTK_u8IntervalMode == MSTK_SPECIAL_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL,TICKINT_BIT);
		/* Restart Timer */
		MSTK->LOAD = MSTK_0;
	}
	else
	{
		/* Do Nothing */
	}
	
	/* Callback Notification */
	if (MSTK_CallBack != NULL)
	{
		(*MSTK_CallBack)();
	}
	else
	{
		/* Do Nothing */
	}
	
	/* Clear Interrupt Flag */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,COUNTFLAG_BIT);
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define MSTK_DONE      			0x01 
#define MSTK_WRONG_CLKSOURCE	0x81 
#define MSTK_WRONG_TIME_UNIT	0x82
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 