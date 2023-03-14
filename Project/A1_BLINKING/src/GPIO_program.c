/***************************************************************************************************************************************************/
/*											                         GPIO Driver								                		           */
/* File Name : GPIO_program.c 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0		 																 	    											   */
/* Date      : 14 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                             Header Files Inclusions 															   */
/***************************************************************************************************************************************************/ 
/* Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "RCC_interface.h"	// RCC

/* Own Driver Files */
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                   Functions																	   */
/***************************************************************************************************************************************************/
/* Initialization */
void MGPIO_voidInit(void)
{
	/* PORTA Direction */
	GPIOA_CRH = ((CONC(MGPIO_PORTA_PIN15_CNF,MGPIO_PORTA_PIN15_MODE,
					   MGPIO_PORTA_PIN14_CNF,MGPIO_PORTA_PIN14_MODE,
					   MGPIO_PORTA_PIN13_CNF,MGPIO_PORTA_PIN13_MODE,
					   MGPIO_PORTA_PIN12_CNF,MGPIO_PORTA_PIN12_MODE) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTA_PIN11_CNF,MGPIO_PORTA_PIN11_MODE,
					   MGPIO_PORTA_PIN10_CNF,MGPIO_PORTA_PIN10_MODE,
					   MGPIO_PORTA_PIN9_CNF ,MGPIO_PORTA_PIN9_MODE ,
					   MGPIO_PORTA_PIN8_CNF ,MGPIO_PORTA_PIN8_MODE));
	GPIOA_CRL = ((CONC(MGPIO_PORTA_PIN7_CNF ,MGPIO_PORTA_PIN7_MODE ,
					   MGPIO_PORTA_PIN6_CNF ,MGPIO_PORTA_PIN6_MODE ,
					   MGPIO_PORTA_PIN5_CNF ,MGPIO_PORTA_PIN5_MODE ,
					   MGPIO_PORTA_PIN4_CNF ,MGPIO_PORTA_PIN4_MODE ) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTA_PIN3_CNF ,MGPIO_PORTA_PIN3_MODE ,
					   MGPIO_PORTA_PIN2_CNF ,MGPIO_PORTA_PIN2_MODE ,
					   MGPIO_PORTA_PIN1_CNF ,MGPIO_PORTA_PIN1_MODE ,
					   MGPIO_PORTA_PIN0_CNF ,MGPIO_PORTA_PIN0_MODE));
	/* PORTB Direction */
	GPIOB_CRH = ((CONC(MGPIO_PORTB_PIN15_CNF,MGPIO_PORTB_PIN15_MODE,
					   MGPIO_PORTB_PIN14_CNF,MGPIO_PORTB_PIN14_MODE,
					   MGPIO_PORTB_PIN13_CNF,MGPIO_PORTB_PIN13_MODE,
					   MGPIO_PORTB_PIN12_CNF,MGPIO_PORTB_PIN12_MODE) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTB_PIN11_CNF,MGPIO_PORTB_PIN11_MODE,
					   MGPIO_PORTB_PIN10_CNF,MGPIO_PORTB_PIN10_MODE,
					   MGPIO_PORTB_PIN9_CNF ,MGPIO_PORTB_PIN9_MODE ,
					   MGPIO_PORTB_PIN8_CNF ,MGPIO_PORTB_PIN8_MODE));
	GPIOB_CRL = ((CONC(MGPIO_PORTB_PIN7_CNF ,MGPIO_PORTB_PIN7_MODE ,
					   MGPIO_PORTB_PIN6_CNF ,MGPIO_PORTB_PIN6_MODE ,
					   MGPIO_PORTB_PIN5_CNF ,MGPIO_PORTB_PIN5_MODE ,
					   MGPIO_PORTB_PIN4_CNF ,MGPIO_PORTB_PIN4_MODE ) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTB_PIN3_CNF ,MGPIO_PORTB_PIN3_MODE ,
					   MGPIO_PORTB_PIN2_CNF ,MGPIO_PORTB_PIN2_MODE ,
					   MGPIO_PORTB_PIN1_CNF ,MGPIO_PORTB_PIN1_MODE ,
					   MGPIO_PORTB_PIN0_CNF ,MGPIO_PORTB_PIN0_MODE));
	/* PORTC Direction */
	GPIOC_CRH = ((CONC(MGPIO_PORTC_PIN15_CNF,MGPIO_PORTC_PIN15_MODE,
					   MGPIO_PORTC_PIN14_CNF,MGPIO_PORTC_PIN14_MODE,
					   MGPIO_PORTC_PIN13_CNF,MGPIO_PORTC_PIN13_MODE,
					   MGPIO_PORTC_PIN12_CNF,MGPIO_PORTC_PIN12_MODE) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTC_PIN11_CNF,MGPIO_PORTC_PIN11_MODE,
					   MGPIO_PORTC_PIN10_CNF,MGPIO_PORTC_PIN10_MODE,
					   MGPIO_PORTC_PIN9_CNF ,MGPIO_PORTC_PIN9_MODE ,
					   MGPIO_PORTC_PIN8_CNF ,MGPIO_PORTC_PIN8_MODE));
	GPIOC_CRL = ((CONC(MGPIO_PORTC_PIN7_CNF ,MGPIO_PORTC_PIN7_MODE ,
					   MGPIO_PORTC_PIN6_CNF ,MGPIO_PORTC_PIN6_MODE ,
					   MGPIO_PORTC_PIN5_CNF ,MGPIO_PORTC_PIN5_MODE ,
					   MGPIO_PORTC_PIN4_CNF ,MGPIO_PORTC_PIN4_MODE ) << MGPIO_CONC_16 ) |
				  CONC(MGPIO_PORTC_PIN3_CNF ,MGPIO_PORTC_PIN3_MODE ,
					   MGPIO_PORTC_PIN2_CNF ,MGPIO_PORTC_PIN2_MODE ,
					   MGPIO_PORTC_PIN1_CNF ,MGPIO_PORTC_PIN1_MODE ,
					   MGPIO_PORTC_PIN0_CNF ,MGPIO_PORTC_PIN0_MODE));
	/* PORTA Value */
	GPIOA_ODR = ((CONC(MGPIO_PORTA_PIN15_VALUE,MGPIO_PORTA_PIN14_VALUE ,
					   MGPIO_PORTA_PIN13_VALUE,MGPIO_PORTA_PIN12_VALUE ,
					   MGPIO_PORTA_PIN11_VALUE,MGPIO_PORTA_PIN10_VALUE ,
					   MGPIO_PORTA_PIN9_VALUE ,MGPIO_PORTA_PIN8_VALUE  ) << MGPIO_CONC_8 ) |
				  CONC(MGPIO_PORTA_PIN7_VALUE ,MGPIO_PORTA_PIN6_VALUE  ,
					   MGPIO_PORTA_PIN5_VALUE ,MGPIO_PORTA_PIN4_VALUE  ,
					   MGPIO_PORTA_PIN3_VALUE ,MGPIO_PORTA_PIN2_VALUE  ,
					   MGPIO_PORTA_PIN1_VALUE ,MGPIO_PORTA_PIN0_VALUE ));
	/* PORTB Value */
	GPIOB_ODR = ((CONC(MGPIO_PORTB_PIN15_VALUE,MGPIO_PORTB_PIN14_VALUE ,
					   MGPIO_PORTB_PIN13_VALUE,MGPIO_PORTB_PIN12_VALUE ,
					   MGPIO_PORTB_PIN11_VALUE,MGPIO_PORTB_PIN10_VALUE ,
					   MGPIO_PORTB_PIN9_VALUE ,MGPIO_PORTB_PIN8_VALUE  ) << MGPIO_CONC_8 ) |
				  CONC(MGPIO_PORTB_PIN7_VALUE ,MGPIO_PORTB_PIN6_VALUE  ,
					   MGPIO_PORTB_PIN5_VALUE ,MGPIO_PORTB_PIN4_VALUE  ,
					   MGPIO_PORTB_PIN3_VALUE ,MGPIO_PORTB_PIN2_VALUE  ,
					   MGPIO_PORTB_PIN1_VALUE ,MGPIO_PORTB_PIN0_VALUE ));
	/* PORTC Value */
	GPIOC_ODR = ((CONC(MGPIO_PORTC_PIN15_VALUE,MGPIO_PORTC_PIN14_VALUE ,
					   MGPIO_PORTC_PIN13_VALUE,MGPIO_PORTC_PIN12_VALUE ,
					   MGPIO_PORTC_PIN11_VALUE,MGPIO_PORTC_PIN10_VALUE ,
					   MGPIO_PORTC_PIN9_VALUE ,MGPIO_PORTC_PIN8_VALUE  ) << MGPIO_CONC_8 ) |
				  CONC(MGPIO_PORTC_PIN7_VALUE ,MGPIO_PORTC_PIN6_VALUE  ,
					   MGPIO_PORTC_PIN5_VALUE ,MGPIO_PORTC_PIN4_VALUE  ,
					   MGPIO_PORTC_PIN3_VALUE ,MGPIO_PORTC_PIN2_VALUE  ,
					   MGPIO_PORTC_PIN1_VALUE ,MGPIO_PORTC_PIN0_VALUE ));
	/* PORTA Clock */
	#if   MGPIO_PORTA_CLOCK == MGPIO_DISABLE
		MRCC_voidDisableClock(MRCC_APB2,MRCC_IOPA);
	#elif MGPIO_PORTA_CLOCK == MGPIO_ENABLE
		MRCC_voidEnableClock(MRCC_APB2,MRCC_IOPA);
	#else
		#error("Configuration Error :: Wrong MGPIO_PORTA_CLOCK")
	#endif
	/* PORTB Clock */
	#if   MGPIO_PORTB_CLOCK == MGPIO_DISABLE
		MRCC_voidDisableClock(MRCC_APB2,MRCC_IOPB);
	#elif MGPIO_PORTB_CLOCK == MGPIO_ENABLE
		MRCC_voidEnableClock(MRCC_APB2,MRCC_IOPB);
	#else
		#error("Configuration Error :: Wrong MGPIO_PORTB_CLOCK")
	#endif
	/* PORTC Clock */
	#if   MGPIO_PORTC_CLOCK == MGPIO_DISABLE
		MRCC_voidDisableClock(MRCC_APB2,MRCC_IOPC);
	#elif MGPIO_PORTC_CLOCK == MGPIO_ENABLE
		MRCC_voidEnableClock(MRCC_APB2,MRCC_IOPC);
	#else
		#error("Configuration Error :: Wrong MGPIO_PORTC_CLOCK")
	#endif
	/* return MGPIO_DONE; */
}

/* IO Pins */
void MGPIO_voidSetPinDirection(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin, u8 Copy_u8Mode)
{
	if (Copy_u8Mode <= OUTPUT_SPEED_50MHZ_AFPP)
	{
		switch (Copy_Port)
		{
			case PORTA:
				if (Copy_Pin <= PIN7)
				{
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOA_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOA_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOA_CRL,Copy_Pin);
					GIV_4BIT(GPIOA_CRL,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else if( Copy_Pin <= PIN15)
				{
					Copy_Pin -= PIN8;
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOA_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOA_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOA_CRH,Copy_Pin);
					GIV_4BIT(GPIOA_CRH,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else
				{
					/* return MGPIO_WRONG_PIN; */
				}
				break;
			case PORTB:
				if (Copy_Pin <= PIN7)
				{
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOB_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOB_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOB_CRL,Copy_Pin);
					GIV_4BIT(GPIOB_CRL,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else if (Copy_Pin <= PIN15)
				{
					Copy_Pin -= PIN8;
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOB_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOB_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOB_CRH,Copy_Pin);
					GIV_4BIT(GPIOB_CRH,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else
				{
					/* return MGPIO_WRONG_PIN; */
				}
				break;
			case PORTC:
				if (Copy_Pin <= PIN7)
				{
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOC_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOC_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOC_CRL,Copy_Pin);
					GIV_4BIT(GPIOC_CRL,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else if (Copy_Pin <= PIN15)
				{
					Copy_Pin -= PIN8;
					if      (Copy_u8Mode == INPUT_PULL_DOWN)
					{
						SET(GPIOC_BRR,Copy_Pin);
					}
					else if (Copy_u8Mode == INPUT_PULL_UP)
					{
						SET(GPIOC_BSRR,Copy_Pin);
						Copy_u8Mode = INPUT_PULL_DOWN;			// INPUT_PULL_UP = INPUT_PULL_DOWN = 0b1000
					}
					else
					{	/* Do Nothing */	}
					CLR_4BIT(GPIOC_CRH,Copy_Pin);
					GIV_4BIT(GPIOC_CRH,Copy_u8Mode,Copy_Pin);
					/* return MGPIO_DONE; */
				}
				else
				{
					/* return MGPIO_WRONG_PIN; */
				}
				break;
			default   : /* return MGPIO_WRONG_PORT; */	break;
		}
	}
	else
	{
		/* return MGPIO_WRONG_MODE; */
	}
}

void MGPIO_voidLockPinMode(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin)
{
	u32 Local_u32Temporary = MGPIO_INITIAL_VALUE;
	if (Copy_Pin <= PIN15)
	{
		switch (Copy_Port) 
		{
			case PORTA:
				SET_BIT(GPIOA_LCKR,Copy_Pin);
				/* Set LCKK_BIT */
				SET_BIT(GPIOA_LCKR,LCKK_BIT);
				/* Reset LCKK_BIT */
				CLR_BIT(GPIOA_LCKR,LCKK_BIT);
				/* Set LCKK_BIT  */
				SET_BIT(GPIOA_LCKR,LCKK_BIT);
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOA_LCKR;
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOA_LCKR;
				/* return MGPIO_DONE; */
				break ;
			case PORTB:
				SET_BIT(GPIOB_LCKR,Copy_Pin);
				/* Set LCKK_BIT */
				SET_BIT(GPIOB_LCKR,LCKK_BIT);
				/* Reset LCKK_BIT */
				CLR_BIT(GPIOB_LCKR,LCKK_BIT);
				/* Set LCKK_BIT  */
				SET_BIT(GPIOB_LCKR,LCKK_BIT);
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOB_LCKR;
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOB_LCKR;
				/* return MGPIO_DONE; */
				break ;
			case PORTC:
				SET_BIT(GPIOC_LCKR,Copy_Pin);
				/* Set LCKK_BIT */
				SET_BIT(GPIOC_LCKR,LCKK_BIT);
				/* Reset LCKK_BIT */
				CLR_BIT(GPIOC_LCKR,LCKK_BIT);
				/* Set LCKK_BIT  */
				SET_BIT(GPIOC_LCKR,LCKK_BIT);
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOC_LCKR;
				/* Read LCKK_BIT */
				Local_u32Temporary = GPIOC_LCKR;
				/* return MGPIO_DONE; */
				break ;
			default   : /* return MGPIO_WRONG_PORT; */	break;
		}
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
}

void MGPIO_voidSetPinValue(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin, u8 Copy_u8Value)
{
	if (Copy_Pin <= PIN15)
	{
		switch (Copy_Port)
		{
			case PORTA:
				switch (Copy_u8Value)
				{
					case LOW : SET(GPIOA_BRR, Copy_Pin); /* return MGPIO_DONE; */	break;
					case HIGH: SET(GPIOA_BSRR,Copy_Pin); /* return MGPIO_DONE; */	break;
					default  : /* return MGPIO_WRONG_VALUE; */						break;
				}
				break;
			case PORTB:
				switch (Copy_u8Value)
				{
					case LOW : SET(GPIOB_BRR, Copy_Pin); /* return MGPIO_DONE; */	break;
					case HIGH: SET(GPIOB_BSRR,Copy_Pin); /* return MGPIO_DONE; */	break;
					default  : /* return MGPIO_WRONG_VALUE; */						break;
				}
				break;
			case PORTC:
				switch (Copy_u8Value)
				{
					case LOW : SET(GPIOC_BRR, Copy_Pin); /* return MGPIO_DONE; */	break;
					case HIGH: SET(GPIOC_BSRR,Copy_Pin); /* return MGPIO_DONE; */	break;
					default  : /* return MGPIO_WRONG_VALUE; */						break;
				}
				break;
			default   : /* return MGPIO_WRONG_PORT; */								break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
}

void MGPIO_voidSetPin(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin)
{
	if (Copy_Pin <= PIN15)
	{
		switch(Copy_Port)
		{
			case PORTA: SET(GPIOA_BSRR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTB: SET(GPIOB_BSRR,Copy_Pin);	/* return MGPIO_DONE; */	break;
			case PORTC: SET(GPIOC_BSRR,Copy_Pin);	/* return MGPIO_DONE; */	break;
			default   : /* return MGPIO_WRONG_PORT; */							break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
}

void MGPIO_voidResetPin(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin)
{
	if (Copy_Pin <= PIN15)
	{
		switch(Copy_Port)
		{
			case PORTA: SET(GPIOA_BRR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTB: SET(GPIOB_BRR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTC: SET(GPIOC_BRR,Copy_Pin); /* return MGPIO_DONE; */	break;
			default   : /* return MGPIO_WRONG_PORT; */						break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
}

void MGPIO_voidTogglePinValue(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin)
{
	if (Copy_Pin <= PIN15)
	{
		switch(Copy_Port)
		{
			case PORTA: TOG_BIT(GPIOA_ODR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTB: TOG_BIT(GPIOB_ODR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTC: TOG_BIT(GPIOC_ODR,Copy_Pin); /* return MGPIO_DONE; */	break;
			default   : /* return MGPIO_WRONG_PORT; */							break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
}

u8   MGPIO_u8GetPinValue(MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin)
{
	u8 Local_u8Value = MGPIO_INITIAL_VALUE;
	
	if (Copy_Pin <= PIN15)
	{
		switch(Copy_Port)
		{
			case PORTA: Local_u8Value = GET_BIT(GPIOA_IDR,Copy_Pin); /* return MGPIO_DONE; */ 	break;
			case PORTB: Local_u8Value = GET_BIT(GPIOB_IDR,Copy_Pin); /* return MGPIO_DONE; */	break;
			case PORTC: Local_u8Value = GET_BIT(GPIOC_IDR,Copy_Pin); /* return MGPIO_DONE; */ 	break;
			default   : /* return MGPIO_WRONG_PORT; */											break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_PIN; */
	}
	
	return Local_u8Value;
}

/* IO Ports */
void MGPIO_voidSetPortDirection(MGPIO_PORT_Type Copy_Port, u8 Copy_u8Mode)
{
	for (MGPIO_PIN_Type Local_Pin=PIN0; Local_Pin<=PIN15; Local_Pin++)
	{
		MGPIO_voidSetPinDirection(Copy_Port,Local_Pin,Copy_u8Mode);
	}
	/* return MGPIO_DONE; */
}

void MGPIO_voidLockPortMode(MGPIO_PORT_Type Copy_Port)
{
	for (MGPIO_PIN_Type Local_Pin=PIN0; Local_Pin<=PIN15; Local_Pin++)
	{
		MGPIO_voidLockPinMode(Copy_Port,Local_Pin);
	}
	/* return MGPIO_DONE; */
}

void MGPIO_voidSetPortValue(MGPIO_PORT_Type Copy_Port, u16 Copy_u16Value)
{
	if (Copy_u16Value <= HIGH_ALL)
	{
		switch (Copy_Port)
		{
			case PORTA: GPIOA_ODR = Copy_u16Value; /* return MGPIO_DONE; */	break;
			case PORTB: GPIOB_ODR = Copy_u16Value; /* return MGPIO_DONE; */	break;
			case PORTC: GPIOC_ODR = Copy_u16Value; /* return MGPIO_DONE; */	break;
			default   : /* return MGPIO_WRONG_PORT; */						break;
		}	
	}
	else
	{
		/* return MGPIO_WRONG_VALUE; */	
	}
}

void MGPIO_voidTogglePortValue(MGPIO_PORT_Type Copy_Port)
{
	switch (Copy_Port)
	{
		case PORTA: TOG_8BIT(GPIOA_ODR,PIN0); /* return MGPIO_DONE; */	break;
		case PORTB: TOG_8BIT(GPIOB_ODR,PIN0); /* return MGPIO_DONE; */	break;
		case PORTC: TOG_8BIT(GPIOC_ODR,PIN0); /* return MGPIO_DONE; */	break;
		default   : /* return MGPIO_WRONG_PORT; */						break;
	}
}

u16  MGPIO_u16GetPortValue(MGPIO_PORT_Type Copy_Port)
{
	u16 Local_u16Value = MGPIO_INITIAL_VALUE;
	
	switch (Copy_Port)
	{
		case PORTA: Local_u16Value = GPIOA_IDR; /* return MGPIO_DONE; */	break;
		case PORTB: Local_u16Value = GPIOB_IDR; /* return MGPIO_DONE; */	break;
		case PORTC: Local_u16Value = GPIOC_IDR; /* return MGPIO_DONE; */	break;
		default   : /* return MGPIO_WRONG_PORT; */							break;
	}	
		
	return Local_u16Value;
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/