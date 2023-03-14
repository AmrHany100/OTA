/***************************************************************************************************************************************************/
/*                                                                   FPEC Driver                                                                   */
/* File Name : FPEC_program.c 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 20 OCT 2020 																	 	    											   */
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
#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                    Functions                                                                    */
/***************************************************************************************************************************************************/
void MFPEC_voidErasePage(u8 Copy_u8PageNumber)
{
	/* Wait Busy Flag */
	while(GET_BIT(MFPEC->SR,BSY_BIT));
	/* Check if FPEC is locked or not */
	if (GET_BIT(MFPEC->CR,LOCK_BIT))
	{
		MFPEC->KEYR = MFPEC_KEY1;
		MFPEC->KEYR = MFPEC_KEY2;
	}
	else
	{
		/* Do Nothing */
	}
	/* Enable Erase Operation for Page */
	SET_BIT(MFPEC->CR,PER_BIT);
	/* Write Page address */
	MFPEC->AR = (u32)(Copy_u8PageNumber * MFPEC_1024) + MFPEC_FLASH_ORIGIN_ADDRESS;
	/* Start Operation (Erase) */
	SET_BIT(MFPEC->CR,STRT_BIT);
	/* Wait Busy Flag */
	while(GET_BIT(MFPEC->SR,BSY_BIT));
	/* End of Operation */
	SET_BIT(MFPEC->SR,EOP_BIT);
	/* Disable Erase Operation for Page */
	CLR_BIT(MFPEC->CR,PER_BIT);
}

void MFPEC_voidEraseAppArea(void)
{
	u8 Local_u8Counter = MFPEC_INITIAL_VALUE;
	for (Local_u8Counter=MFPEC_APP_FIRST_PAGE; Local_u8Counter<MFPEC_FLASH_SIZE_KB; Local_u8Counter++)
	{
		MFPEC_voidErasePage(Local_u8Counter);
	}
}

void MFPEC_voidMassErase(void)
{
	/* Check if FPEC is locked or not */
	if (GET_BIT(MFPEC->CR,LOCK_BIT))
	{
		MFPEC->KEYR = MFPEC_KEY1;
		MFPEC->KEYR = MFPEC_KEY2;
	}
	else
	{
		/* Do Nothing */
	}
	/* Enable Mass Erase */
	SET_BIT(MFPEC->CR,MER_BIT);
	/* Start Operation (Erase) */
	SET_BIT(MFPEC->CR,STRT_BIT);
	/* Wait Busy Flag */
	while(GET_BIT(MFPEC->SR,BSY_BIT));
}

void MFPEC_voidWriteArea(u32 Copy_u32Address, u16 *Copy_u16Data, u16 Copy_u16Length)
{
	u8 Local_u8Counter = MFPEC_INITIAL_VALUE; 
	/* Wait Busy Flag */
	while(GET_BIT(MFPEC->SR,BSY_BIT));
	/* Check if FPEC is locked or not */
	if (GET_BIT(MFPEC->CR,LOCK_BIT))
	{
		MFPEC->KEYR = MFPEC_KEY1;
		MFPEC->KEYR = MFPEC_KEY2;
	}
	else
	{
		/* Do Nothing */
	}
	for (Local_u8Counter=MFPEC_0; Local_u8Counter<Copy_u16Length; Local_u8Counter++)
	{
		/* Enable Programming */
		SET_BIT(MFPEC->CR,PG_BIT);
		/* Write byte at the desired place */
		*((volatile pu16)Copy_u32Address) = Copy_u16Data[Local_u8Counter];
		/* Shift to the next address */
		Copy_u32Address += MFPEC_2;
		/* Wait Busy Flag */
		while(GET_BIT(MFPEC->SR,BSY_BIT));
		/* End of Operation */
		SET_BIT(MFPEC->SR,EOP_BIT);
		/* Disable Programming */
		CLR_BIT(MFPEC->CR,PG_BIT);
	}
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
