/***************************************************************************************************************************************************/
/*											                         GPIO Driver								                		           */
/* File Name : GPIO_config.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0		 																 	    											   */
/* Date      : 14 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/***************************************************************************************************************************************************/ 
/*                                                                 Configuration															       */
/* GPIO Registers : Section 9.2 Page 171 																										   */
/***************************************************************************************************************************************************/ 
/* MGPIO_PORTx_CLOCK:	MGPIO_DISABLE
						MGPIO_ENABLE  */
#define MGPIO_PORTA_CLOCK		MGPIO_DISABLE
#define MGPIO_PORTB_CLOCK       MGPIO_DISABLE
#define MGPIO_PORTC_CLOCK       MGPIO_DISABLE

/* MGPIO_PORTx_PINx_MODE Opitions:				INPUT
												OUTPUT_SPEED_10MHZ
												OUTPUT_SPEED_2MHZ
												OUTPUT_SPEED_50MHZ
											
   MGPIO_PORTx_PINx_CNF Opitions for Output:	PUSHPULL		
												OPENDRAIN	
												AFPUSHPULL
												AFOPENDRAIN
											
   MGPIO_PORTx_PINx_CNF Opitions for Input:		ANALOG	
												FLOATING	
												PUSHDOWN	
												PUSHUP	
												
   MGPIO_PORTx_PINx_VALUE Options:				HIGH
												LOW					*/
/* Note: If MGPIO_PORTx_PINx_MODE: INPUT and MGPIO_PORTx_PINx_CNF: INPUT_PUSHDOWN, MGPIO_PORTx_PINx_VALUE must be: LOW
	   and if MGPIO_PORTx_PINx_MODE: INPUT and MGPIO_PORTx_PINx_CNF: INPUT_PUSHUP, MGPIO_PORTx_PINx_VALUE must be: HIGH */

/* PORTA - PIN0 */
#define MGPIO_PORTA_PIN0_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN0_CNF   	PUSHPULL
#define MGPIO_PORTA_PIN0_VALUE 	HIGH

/* PORTA - PIN1 */
#define MGPIO_PORTA_PIN1_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN1_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN1_VALUE	HIGH

/* PORTA - PIN2 */
#define MGPIO_PORTA_PIN2_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN2_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN2_VALUE	HIGH

/* PORTA - PIN3 */
#define MGPIO_PORTA_PIN3_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN3_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN3_VALUE	HIGH

/* PORTA - PIN4 */
#define MGPIO_PORTA_PIN4_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN4_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN4_VALUE	HIGH

/* PORTA - PIN5 */
#define MGPIO_PORTA_PIN5_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN5_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN5_VALUE	HIGH

/* PORTA - PIN6 */
#define MGPIO_PORTA_PIN6_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN6_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN6_VALUE	HIGH

/* PORTA - PIN7 */
#define MGPIO_PORTA_PIN7_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN7_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN7_VALUE	HIGH

/* PORTA - PIN8 */
#define MGPIO_PORTA_PIN8_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN8_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN8_VALUE	HIGH

/* PORTA - PIN9 */
#define MGPIO_PORTA_PIN9_MODE  	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN9_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN9_VALUE	HIGH

/* PORTA - PIN10 */
#define MGPIO_PORTA_PIN10_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN10_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN10_VALUE	HIGH
	
/* PORTA - PIN11 */	
#define MGPIO_PORTA_PIN11_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN11_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN11_VALUE	HIGH

/* PORTA - PIN12 */
#define MGPIO_PORTA_PIN12_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN12_CNF 	PUSHPULL
#define MGPIO_PORTA_PIN12_VALUE	HIGH

/* PORTA - PIN13 */
#define MGPIO_PORTA_PIN13_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN13_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN13_VALUE	HIGH

/* PORTA - PIN14 */
#define MGPIO_PORTA_PIN14_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN14_CNF	PUSHPULL
#define MGPIO_PORTA_PIN14_VALUE	HIGH

/* PORTA - PIN15 */
#define MGPIO_PORTA_PIN15_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTA_PIN15_CNF  	PUSHPULL
#define MGPIO_PORTA_PIN15_VALUE	HIGH

/* PORTB - PIN0 */
#define MGPIO_PORTB_PIN0_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN0_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN0_VALUE	HIGH

/* PORTB - PIN1 */
#define MGPIO_PORTB_PIN1_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN1_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN1_VALUE	HIGH

/* PORTB - PIN2 */
#define MGPIO_PORTB_PIN2_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN2_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN2_VALUE	HIGH

/* PORTB - PIN3 */
#define MGPIO_PORTB_PIN3_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN3_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN3_VALUE	HIGH

/* PORTB - PIN4 */
#define MGPIO_PORTB_PIN4_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN4_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN4_VALUE	HIGH

/* PORTB - PIN5 */
#define MGPIO_PORTB_PIN5_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN5_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN5_VALUE	HIGH

/* PORTB - PIN6 */
#define MGPIO_PORTB_PIN6_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN6_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN6_VALUE	HIGH

/* PORTB - PIN7 */
#define MGPIO_PORTB_PIN7_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN7_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN7_VALUE	HIGH

/* PORTB - PIN8 */
#define MGPIO_PORTB_PIN8_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN8_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN8_VALUE	HIGH

/* PORTB - PIN9 */
#define MGPIO_PORTB_PIN9_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN9_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN9_VALUE	HIGH

/* PORTB - PIN10 */
#define MGPIO_PORTB_PIN10_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN10_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN10_VALUE	HIGH

/* PORTB - PIN11 */
#define MGPIO_PORTB_PIN11_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN11_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN11_VALUE	HIGH

/* PORTB - PIN12 */
#define MGPIO_PORTB_PIN12_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN12_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN12_VALUE	HIGH

/* PORTB - PIN13 */
#define MGPIO_PORTB_PIN13_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN13_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN13_VALUE	HIGH

/* PORTB - PIN14 */
#define MGPIO_PORTB_PIN14_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN14_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN14_VALUE	HIGH

/* PORTB - PIN15 */	
#define MGPIO_PORTB_PIN15_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTB_PIN15_CNF  	PUSHPULL
#define MGPIO_PORTB_PIN15_VALUE	HIGH

/* PORTC - PIN0 */
#define MGPIO_PORTC_PIN0_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN0_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN0_VALUE	HIGH

/* PORTC - PIN1 */
#define MGPIO_PORTC_PIN1_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN1_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN1_VALUE	HIGH

/* PORTC - PIN2 */
#define MGPIO_PORTC_PIN2_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN2_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN2_VALUE	HIGH
								
/* PORTC - PIN3 */            	
#define MGPIO_PORTC_PIN3_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN3_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN3_VALUE	HIGH
								
/* PORTC - PIN4 */            	
#define MGPIO_PORTC_PIN4_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN4_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN4_VALUE	HIGH
								
/* PORTC - PIN5 */            	
#define MGPIO_PORTC_PIN5_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN5_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN5_VALUE	HIGH
								
/* PORTC - PIN6 */            	
#define MGPIO_PORTC_PIN6_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN6_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN6_VALUE	HIGH
								
/* PORTC - PIN7 */            	
#define MGPIO_PORTC_PIN7_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN7_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN7_VALUE	HIGH
								
/* PORTC - PIN8 */            	
#define MGPIO_PORTC_PIN8_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN8_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN8_VALUE	HIGH
								
/* PORTC - PIN9 */            	
#define MGPIO_PORTC_PIN9_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN9_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN9_VALUE	HIGH

/* PORTC - PIN10 */
#define MGPIO_PORTC_PIN10_MODE	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN10_CNF   PUSHPULL
#define MGPIO_PORTC_PIN10_VALUE	HIGH
                                
/* PORTC - PIN11 */             
#define MGPIO_PORTC_PIN11_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN11_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN11_VALUE	HIGH
                                
/* PORTC - PIN12 */             
#define MGPIO_PORTC_PIN12_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN12_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN12_VALUE	HIGH
								
/* PORTC - PIN13 */            	
#define MGPIO_PORTC_PIN13_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN13_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN13_VALUE	HIGH
								
/* PORTC - PIN14 */            	
#define MGPIO_PORTC_PIN14_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN14_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN14_VALUE	HIGH
								
/* PORTC - PIN15 */            	
#define MGPIO_PORTC_PIN15_MODE 	OUTPUT_SPEED_2MHZ
#define MGPIO_PORTC_PIN15_CNF  	PUSHPULL
#define MGPIO_PORTC_PIN15_VALUE	HIGH
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                	   Errors                                                                	   */
/***************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												   Errors				  | Return Value														  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*|												   MGPIO_DONE (No-Errors) | 	0x01															  |*/
/*|                                                MGPIO_WRONG_PORT 	  | 	0x81			                                                  |*/
/*|                                                MGPIO_WRONG_PIN        | 	0x82			                                                  |*/
/*|                                                MGPIO_WRONG_MODE		  | 	0x84			                                                  |*/
/*|                                                MGPIO_WRONG_VALUE      | 	0x88			                                                  |*/
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
/***************************************************************************************************************************************************/ 
                                
#endif                          
/***************************************************************************************************************************************************/ 