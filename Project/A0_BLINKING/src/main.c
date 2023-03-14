/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

void main(void)
{
	/* Initialize the RCC to HSE */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2,MRCC_IOPA  );	// PORTA
	
	/* GPIO */
	MGPIO_voidSetPinDirection(PORTA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	
	/* STK */
	MSTK_voidInit();

	while(1)
	{
		MGPIO_voidSetPinValue(PORTA,PIN0,LOW);
		MSTK_voidSetBusyWait(1000,MSTK_TIME_MS);
		MGPIO_voidSetPinValue(PORTA,PIN0,HIGH);
		MSTK_voidSetBusyWait(1000,MSTK_TIME_MS);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
