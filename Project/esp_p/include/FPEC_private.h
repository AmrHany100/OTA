/***************************************************************************************************************************************************/
/*                                                                   FPEC Driver                                                                   */
/* File Name : FPEC_private.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 20 OCT 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

/***************************************************************************************************************************************************/ 
/*                                                              Registers Definitions 															   */
/* Boundary address : 0x4002 2000 - 0x4002 23FF															 									  	   */
/* Bus				: AHB																														   */
/* Register map     : Section 3.9 on page 29 {Flash Memory MC}																					   */ 
/***************************************************************************************************************************************************/ 
/* FPEC Base Address */
#define MFPEC_BASE_ADDRESS	0x40022000

/* FPEC Registers */
typedef struct
{
	volatile ACR     ;		// Flash access control register (FLASH_ACR)
	volatile KEYR    ;		// FPEC key register (FLASH_KEYR)
	volatile OPTKEYR ;		// Flash OPTKEY register (FLASH_OPTKEYR)
	volatile SR      ;		// Flash status register (FLASH_SR) 
	volatile CR      ;		// Flash control register (FLASH_CR)
	volatile AR      ;		// Flash address register (FLASH_AR)
	volatile RESERVED;		// Reserved
	volatile OBR     ;		// Option byte register (FLASH_OBR)
	volatile WRPR    ;		// Write protection register (FLASH_WRPR)		
}MFPEC_Type;

#define MFPEC				((volatile MFPEC_Type*)MFPEC_BASE_ADDRESS)
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                 Registers Bits 			     												   */
/* FPEC Registers : Section 3 on page 23 {Flash Memory MC}																					   	   */
/***************************************************************************************************************************************************/ 
/* Flash status register (FLASH_SR) */
#define EOP_BIT				5	// End of operatione      
#define WRPRTERR_BIT		4	// Write protection error 
#define PGERR_BIT			2	// Programming error      
#define BSY_BIT				0  	// Busy			          

/* Flash control register (FLASH_CR) */
#define EOPIE_BIT			12	// End of operation interrupt enable                                                       
#define ERRIE_BIT			10	// Error interrupt enable
#define OPTWRE_BIT			9	// Option bytes write enable                                                    
#define LOCK_BIT			7	// Lock                         
#define STRT_BIT			6	// Start                                                    
#define OPTER_BIT			5	// Option byte erase                                                                                            
#define OPTPG_BIT			4   // Option byte programming          
#define MER_BIT				2 	// Mass erase                             
#define PER_BIT				1	// Page erase                                                                                                                                   
#define PG_BIT				0	// Programming 
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/***************************************************************************************************************************************************/ 
/* Magic Numbers */
#define MFPEC_INITIAL_VALUE	0
#define MFPEC_0			 	0
#define MFPEC_1			 	1
#define MFPEC_2			 	2
#define MFPEC_1024			1024

/* Lock Keys */
#define MFPEC_KEY1    		0x45670123
#define MFPEC_KEY2    		0xCDEF89AB
#define MFPEC_MRDPRT_KEY    0x00A5 

/* MFPEC_FLASH_SIZE_KB > MFPEC_APP_FIRST_PAGE */
#if MFPEC_FLASH_SIZE_KB < MFPEC_APP_FIRST_PAGE
	#error("Configuration Error :: Wrong MFPEC_APP_FIRST_PAGE")
#endif
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                CallBack Functions                                                               */
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define MFPEC_DONE  		0x01
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 