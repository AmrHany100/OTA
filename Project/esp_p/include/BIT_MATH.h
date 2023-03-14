/***************************************************************************************************************************************************/
/*										 	                       Bit Math Library										 	                       */
/* File Name : BIT_MATH.h 																				 	  									   */
/* Aurthor   : Amr Hany																	 	  									   */
/* Date      : 29 JUL 2020 																				 	  									   */
/* Version	 : 1.1.1																					 	  									   */
/* MC        : STM32F10x [ARM]										 	    											   						   */
/* Layer     : LIB				 																												   */
/***************************************************************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Bit Math for 1 bit */
#define SET_BIT(VAR,BITNO) 						(VAR) |=  (   1   << (BITNO))
#define CLR_BIT(VAR,BITNO) 						(VAR) &= ~(   1   << (BITNO))
#define TOG_BIT(VAR,BITNO) 						(VAR) ^=  (   1   << (BITNO))
#define GIV_BIT(VAR,GVAR,BITNO) 				(VAR) |=  ((GVAR) << (BITNO))
#define GET_BIT(VAR,BITNO) 						(((VAR) >> (BITNO)) & 0x01)

/* SET 1 bit only and CLR others */
#define SET(VAR,BITNO)	 						(VAR)  =  (1 << (BITNO))

/* Bit Math for 4 bit */
#define SET_4BIT(VAR,BITNO) 					(VAR) |=  ((0b1111) << (BITNO * 4))
#define CLR_4BIT(VAR,BITNO) 					(VAR) &= ~((0b1111) << (BITNO * 4))
#define TOG_4BIT(VAR,BITNO) 					(VAR) ^=  ((0b1111) << (BITNO * 4))
#define GIV_4BIT(VAR,GVAR,BITNO) 				(VAR) |=  (( GVAR ) << (BITNO * 4))

/* Bit Math for 8 bit */
#define TOG_8BIT(VAR,BITNO) 					(VAR) ^=  ((0xFF) << (BITNO))

/* Concatenate */ 
/* Note: It can Conc more than 8-bit but it takes only 8 Numbers, Parameters can more than 1 digit (0 or 00 or 101) */
#define CONC(X7,X6,X5,X4,X3,X2,X1,X0) 			CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0)
#define CONC_HELPER(X7,X6,X5,X4,X3,X2,X1,X0)	0b##X7##X6##X5##X4##X3##X2##X1##X0

#endif
/*********************************************************************************************************/