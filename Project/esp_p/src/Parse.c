/***************************************************************************************************************************************************/
/* File Name : Parse.c 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 27 OCT 2020 																	 	    											   */
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
#include "FPEC_interface.h"	// FPEC
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                 Global Variables                                                                */
/***************************************************************************************************************************************************/
u32 Global_u32Address   = 0x08000000;
u16 Global_u16Data[100] = {0};
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                    Functions                                                                    */
/***************************************************************************************************************************************************/
u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 u8Result;
	if ((Copy_u8Asci >= 48) && (Copy_u8Asci <= 57))
	{
		u8Result = Copy_u8Asci - 48;
	}
	else
	{
		u8Result = Copy_u8Asci - 55;
	}
	return u8Result;
}

void ParseData(pu8 Copy_pu8BufData)
{
	u8 DigitLow,DigitHigh,CC,i;
	u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	u8 DataCounter = 0;

	/* Get Character Count */
	DigitHigh = AsciToHex (Copy_pu8BufData[1]);
	DigitLow  = AsciToHex (Copy_pu8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = AsciToHex (Copy_pu8BufData[3]);
	DataDigit1 = AsciToHex (Copy_pu8BufData[4]);
	DataDigit2 = AsciToHex (Copy_pu8BufData[5]);
	DataDigit3 = AsciToHex (Copy_pu8BufData[6]);

	/* Clear Low Part of Address */
	Global_u32Address = Global_u32Address & 0xFFFF0000;
	Global_u32Address = Global_u32Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = AsciToHex (Copy_pu8BufData[4*i+9 ]);
		DataDigit1 = AsciToHex (Copy_pu8BufData[4*i+10]);
		DataDigit2 = AsciToHex (Copy_pu8BufData[4*i+11]);
		DataDigit3 = AsciToHex (Copy_pu8BufData[4*i+12]);

		Global_u16Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		DataCounter++;
	}

	MFPEC_voidWriteArea(Global_u32Address,Global_u16Data,CC/2);
}

void ParseUpperAddress(pu8 Copy_pu8BufData)
{
	u8 Local_u8Digit0, Local_u8Digit1, Local_u8Digit2, Local_u8Digit3;
	/* Get Address */
	u32 Local_u32Address;
	Local_u8Digit0    = AsciToHex(Copy_pu8BufData[12]);
	Local_u8Digit1    = AsciToHex(Copy_pu8BufData[11]);
	Local_u8Digit2    = AsciToHex(Copy_pu8BufData[10]);
	Local_u8Digit3    = AsciToHex(Copy_pu8BufData[9]);
	Local_u32Address  = Local_u8Digit0 | (Local_u8Digit1 << 4) | (Local_u8Digit2 << 8) | (Local_u8Digit3 << 12);
	Global_u32Address = (Local_u32Address << 16);
}

void Parser_voidParseRecord(pu8 Copy_pu8BufData)
{
	switch (Copy_pu8BufData[8])
	{
		case '0': ParseData(Copy_pu8BufData); 			break;
		case '4': ParseUpperAddress(Copy_pu8BufData); 	break;
	}
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
