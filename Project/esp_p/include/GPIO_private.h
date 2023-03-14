/***************************************************************************************************************************************************/
/*											                         GPIO Driver								                		           */
/* File Name : GPIO_private.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0		 																 	    											   */
/* Date      : 14 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/***************************************************************************************************************************************************/ 
/*                                                              Registers Definitions 															   */
/* Boundary address : GPIO Port A : 0x4001 0800 - 0x4001 0BFF																					   */
/*					  GPIO Port B : 0x4001 0C00 - 0x4001 0FFF																					   */
/*					  GPIO Port C : 0x4001 1000 - 0x4001 13FF																					   */
/* Bus				: APB2																														   */
/* Register map     : Section 9.5 on page 194																									   */
/***************************************************************************************************************************************************/ 
/* GPIO Base Address */
#define GPIOA_BASE_ADDRESS	0x40010800	
#define GPIOB_BASE_ADDRESS	0x40010C00
#define GPIOC_BASE_ADDRESS	0x40011000

/* GPIO PORT A Registers */
#define GPIOA_CRL			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x00))	// Port configuration register low (GPIOA_CRL)
#define GPIOA_CRH			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x04))	// Port configuration register high (GPIOA_CRH)
#define GPIOA_IDR			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x08))	// Port input data register (GPIOA_IDR)
#define GPIOA_ODR			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x0C))	// Port output data register (GPIOA_ODR)
#define GPIOA_BSRR			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x10))	// Port bit set/reset register (GPIOA_BSRR)
#define GPIOA_BRR			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x14))	// Port bit reset register (GPIOA_BRR)
#define GPIOA_LCKR			*((volatile pu32)(GPIOA_BASE_ADDRESS + 0x18))	// Port configuration lock register (GPIOA_LCKR)

/* GPIO PORT B Registers */
#define GPIOB_CRL			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x00))	// Port configuration register low (GPIOB_CRL)
#define GPIOB_CRH			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x04)) 	// Port configuration register high (GPIOB_CRH)
#define GPIOB_IDR			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x08))	// Port input data register (GPIOB_IDR)
#define GPIOB_ODR			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x0C)) 	// Port output data register (GPIOB_ODR)
#define GPIOB_BSRR			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x10)) 	// Port bit set/reset register (GPIOB_BSRR)
#define GPIOB_BRR			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x14)) 	// Port bit reset register (GPIOB_BRR)
#define GPIOB_LCKR			*((volatile pu32)(GPIOB_BASE_ADDRESS + 0x18)) 	// Port configuration lock register (GPIOB_LCKR)

/* GPIO PORT C Registers */
#define GPIOC_CRL			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x00))	// Port configuration register low (GPIOC_CRL)
#define GPIOC_CRH			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x04)) 	// Port configuration register high (GPIOC_CRH)
#define GPIOC_IDR			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x08)) 	// Port input data register (GPIOC_IDR)
#define GPIOC_ODR			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x0C)) 	// Port output data register (GPIOC_ODR)
#define GPIOC_BSRR			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x10)) 	// Port bit set/reset register (GPIOC_BSRR)
#define GPIOC_BRR			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x14)) 	// Port bit reset register (GPIOC_BRR)
#define GPIOC_LCKR			*((volatile pu32)(GPIOC_BASE_ADDRESS + 0x18)) 	// Port configuration lock register (GPIOC_LCKR)
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                 Registers Bits 			     												   */
/* GPIO Registers : Section 9.2 Page 171           																								   */
/***************************************************************************************************************************************************/ 
/* Port configuration register low (GPIOx_CRL) & Port configuration register high (GPIOx_CRH)
Port bit configuration table
--------------------------------------------------------------------------------
| Configuration mode 				     | 	CNF1 |  CNF0 | MODE1 | MODE0 | ODR |
--------------------------------------------------------------------------------
| General purpose output    (Push-pull)  |   0   |   0   |  0/1  |  0/1  |  -  |
| General purpose output    (Open-drain) |   0   |   1   |  0/1  |  0/1  |  -  |
| Alternate Function output (Push-pull)  |   1   |   0   |  0/1  |  0/1  |  -  |
| Alternate Function output (Open-drain) |   1   |   1   |  0/1  |  0/1  |  -  |
| Input 					(Analog)     |   0   |   0   |   0   |   0   |  -  |
| Input 					(floating)   |   0   |   1   |   0   |   0   |  -  |
| Input 					(pull-down)  |   1   |   0   |   0   |   0   |  0  |
| Input 				    (pull-up)    |   1   |   0   |   0   |   0   |  1  |
--------------------------------------------------------------------------------
Output MODE bits
--------------------------------------------
| MODE [1:0] | Meaning  				   |
--------------------------------------------
|     00     | Reserved					   |
|     01     | Maximum output speed 10 MHz |		
|     10     | Maximum output speed 2 MHz  |	
|     11     | Maximum output speed 50 MHz |	
--------------------------------------------
[Page: 161] */

/* Port configuration lock register (GPIOx_LCKR) */
#define LCKK_BIT			16	
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/***************************************************************************************************************************************************/
/* Magic Numbers */
#define MGPIO_INITIAL_VALUE 0
#define	MGPIO_CONC_8 		8
#define	MGPIO_CONC_16 		16
#define MGPIO_0X00010000	0x00010000

/* Clock States */
#define MGPIO_DISABLE		0
#define MGPIO_ENABLE		1

/* Modes */
#define INPUT				00
#define OUTPUT_SPEED_10MHZ	01
#define OUTPUT_SPEED_2MHZ	10
#define OUTPUT_SPEED_50MHZ	11

/* Output Configuration */
#define PUSHPULL			00
#define OPENDRAIN			01
#define AFPUSHPULL			10
#define AFOPENDRAIN			11

/* Input Configuration */
#define ANALOG				00
#define FLOATING			01
#define PUSHDOWN			10
#define PUSHUP				10

/* Note: If GPIO_PORTx_PINx_MODE: INPUT and GPIO_PORTx_PINx_CNF: INPUT_PUSHDOWN, GPIO_PORTx_PINx_VALUE must be: LOW.
	   and if GPIO_PORTx_PINx_MODE: INPUT and GPIO_PORTx_PINx_CNF: INPUT_PUSHUP, GPIO_PORTx_PINx_VALUE must be: HIGH. */
	   
/* PORTA - PIN0 */
#if   (GPIO_PORTA_PIN0_MODE == INPUT) &&(GPIO_PORTA_PIN0_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN0_VALUE LOW
#elif (GPIO_PORTA_PIN0_MODE == INPUT) &&(GPIO_PORTA_PIN0_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN0_VALUE HIGH
#endif

/* PORTA - PIN1 */
#if   (GPIO_PORTA_PIN1_MODE == INPUT) &&(GPIO_PORTA_PIN1_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN1_VALUE LOW
#elif (GPIO_PORTA_PIN1_MODE == INPUT) &&(GPIO_PORTA_PIN1_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN1_VALUE HIGH
#endif

/* PORTA - PIN2 */
#if   (GPIO_PORTA_PIN2_MODE == INPUT) &&(GPIO_PORTA_PIN2_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN2_VALUE LOW
#elif (GPIO_PORTA_PIN2_MODE == INPUT) &&(GPIO_PORTA_PIN2_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN2_VALUE HIGH
#endif

/* PORTA - PIN3 */
#if   (GPIO_PORTA_PIN3_MODE == INPUT) &&(GPIO_PORTA_PIN3_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN3_VALUE LOW
#elif (GPIO_PORTA_PIN3_MODE == INPUT) &&(GPIO_PORTA_PIN3_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN3_VALUE HIGH
#endif

/* PORTA - PIN4 */
#if   (GPIO_PORTA_PIN4_MODE == INPUT) &&(GPIO_PORTA_PIN4_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN4_VALUE LOW
#elif (GPIO_PORTA_PIN4_MODE == INPUT) &&(GPIO_PORTA_PIN4_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN4_VALUE HIGH
#endif

/* PORTA - PIN5 */
#if   (GPIO_PORTA_PIN5_MODE == INPUT) &&(GPIO_PORTA_PIN5_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN5_VALUE LOW
#elif (GPIO_PORTA_PIN5_MODE == INPUT) &&(GPIO_PORTA_PIN5_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN5_VALUE HIGH
#endif

/* PORTA - PIN6 */
#if   (GPIO_PORTA_PIN6_MODE == INPUT) &&(GPIO_PORTA_PIN6_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN6_VALUE LOW
#elif (GPIO_PORTA_PIN6_MODE == INPUT) &&(GPIO_PORTA_PIN6_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN6_VALUE HIGH
#endif

/* PORTA - PIN7 */
#if   (GPIO_PORTA_PIN7_MODE == INPUT) &&(GPIO_PORTA_PIN7_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN7_VALUE LOW
#elif (GPIO_PORTA_PIN7_MODE == INPUT) &&(GPIO_PORTA_PIN7_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN7_VALUE HIGH
#endif

/* PORTA - PIN8 */
#if   (GPIO_PORTA_PIN8_MODE == INPUT) &&(GPIO_PORTA_PIN8_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN8_VALUE LOW
#elif (GPIO_PORTA_PIN8_MODE == INPUT) &&(GPIO_PORTA_PIN8_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN8_VALUE HIGH
#endif

/* PORTA - PIN9 */
#if   (GPIO_PORTA_PIN9_MODE == INPUT) &&(GPIO_PORTA_PIN9_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN9_VALUE LOW
#elif (GPIO_PORTA_PIN9_MODE == INPUT) &&(GPIO_PORTA_PIN9_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN9_VALUE HIGH
#endif

/* PORTA - PIN10 */
#if   (GPIO_PORTA_PIN10_MODE == INPUT) &&(GPIO_PORTA_PIN10_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN10_VALUE LOW
#elif (GPIO_PORTA_PIN10_MODE == INPUT) &&(GPIO_PORTA_PIN10_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN10_VALUE HIGH
#endif

/* PORTA - PIN11 */
#if   (GPIO_PORTA_PIN11_MODE == INPUT) &&(GPIO_PORTA_PIN11_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN11_VALUE LOW
#elif (GPIO_PORTA_PIN11_MODE == INPUT) &&(GPIO_PORTA_PIN11_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN11_VALUE HIGH
#endif

/* PORTA - PIN12 */
#if   (GPIO_PORTA_PIN12_MODE == INPUT) &&(GPIO_PORTA_PIN12_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN12_VALUE LOW
#elif (GPIO_PORTA_PIN12_MODE == INPUT) &&(GPIO_PORTA_PIN12_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN12_VALUE HIGH
#endif

/* PORTA - PIN13 */
#if   (GPIO_PORTA_PIN13_MODE == INPUT) &&(GPIO_PORTA_PIN13_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN13_VALUE LOW
#elif (GPIO_PORTA_PIN13_MODE == INPUT) &&(GPIO_PORTA_PIN13_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN13_VALUE HIGH
#endif

/* PORTA - PIN14 */
#if   (GPIO_PORTA_PIN14_MODE == INPUT) &&(GPIO_PORTA_PIN14_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN14_VALUE LOW
#elif (GPIO_PORTA_PIN14_MODE == INPUT) &&(GPIO_PORTA_PIN14_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN14_VALUE HIGH
#endif

/* PORTA - PIN15 */
#if   (GPIO_PORTA_PIN15_MODE == INPUT) &&(GPIO_PORTA_PIN15_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTA_PIN15_VALUE LOW
#elif (GPIO_PORTA_PIN15_MODE == INPUT) &&(GPIO_PORTA_PIN15_CNF == INPUT_PUSHUP)
	#define GPIO_PORTA_PIN15_VALUE HIGH
#endif

/* PORTB - PIN0 */
#if   (GPIO_PORTB_PIN0_MODE == INPUT) &&(GPIO_PORTB_PIN0_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN0_VALUE LOW
#elif (GPIO_PORTB_PIN0_MODE == INPUT) &&(GPIO_PORTB_PIN0_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN0_VALUE HIGH
#endif

/* PORTB - PIN1 */
#if   (GPIO_PORTB_PIN1_MODE == INPUT) &&(GPIO_PORTB_PIN1_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN1_VALUE LOW
#elif (GPIO_PORTB_PIN1_MODE == INPUT) &&(GPIO_PORTB_PIN1_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN1_VALUE HIGH
#endif

/* PORTB - PIN2 */
#if   (GPIO_PORTB_PIN2_MODE == INPUT) &&(GPIO_PORTB_PIN2_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN2_VALUE LOW
#elif (GPIO_PORTB_PIN2_MODE == INPUT) &&(GPIO_PORTB_PIN2_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN2_VALUE HIGH
#endif

/* PORTB - PIN3 */
#if   (GPIO_PORTB_PIN3_MODE == INPUT) &&(GPIO_PORTB_PIN3_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN3_VALUE LOW
#elif (GPIO_PORTB_PIN3_MODE == INPUT) &&(GPIO_PORTB_PIN3_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN3_VALUE HIGH
#endif

/* PORTB - PIN4 */
#if   (GPIO_PORTB_PIN4_MODE == INPUT) &&(GPIO_PORTB_PIN4_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN4_VALUE LOW
#elif (GPIO_PORTB_PIN4_MODE == INPUT) &&(GPIO_PORTB_PIN4_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN4_VALUE HIGH
#endif

/* PORTB - PIN5 */
#if   (GPIO_PORTB_PIN5_MODE == INPUT) &&(GPIO_PORTB_PIN5_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN5_VALUE LOW
#elif (GPIO_PORTB_PIN5_MODE == INPUT) &&(GPIO_PORTB_PIN5_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN5_VALUE HIGH
#endif

/* PORTB - PIN6 */
#if   (GPIO_PORTB_PIN6_MODE == INPUT) &&(GPIO_PORTB_PIN6_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN6_VALUE LOW
#elif (GPIO_PORTB_PIN6_MODE == INPUT) &&(GPIO_PORTB_PIN6_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN6_VALUE HIGH
#endif

/* PORTB - PIN7 */
#if   (GPIO_PORTB_PIN7_MODE == INPUT) &&(GPIO_PORTB_PIN7_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN7_VALUE LOW
#elif (GPIO_PORTB_PIN7_MODE == INPUT) &&(GPIO_PORTB_PIN7_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN7_VALUE HIGH
#endif

/* PORTB - PIN8 */
#if   (GPIO_PORTB_PIN8_MODE == INPUT) &&(GPIO_PORTB_PIN8_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN8_VALUE LOW
#elif (GPIO_PORTB_PIN8_MODE == INPUT) &&(GPIO_PORTB_PIN8_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN8_VALUE HIGH
#endif

/* PORTB - PIN9 */
#if   (GPIO_PORTB_PIN9_MODE == INPUT) &&(GPIO_PORTB_PIN9_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN9_VALUE LOW
#elif (GPIO_PORTB_PIN9_MODE == INPUT) &&(GPIO_PORTB_PIN9_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN9_VALUE HIGH
#endif

/* PORTB - PIN10 */
#if   (GPIO_PORTB_PIN10_MODE == INPUT) &&(GPIO_PORTB_PIN10_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN10_VALUE LOW
#elif (GPIO_PORTB_PIN10_MODE == INPUT) &&(GPIO_PORTB_PIN10_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN10_VALUE HIGH
#endif

/* PORTB - PIN11 */
#if   (GPIO_PORTB_PIN11_MODE == INPUT) &&(GPIO_PORTB_PIN11_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN11_VALUE LOW
#elif (GPIO_PORTB_PIN11_MODE == INPUT) &&(GPIO_PORTB_PIN11_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN11_VALUE HIGH
#endif

/* PORTB - PIN12 */
#if   (GPIO_PORTB_PIN12_MODE == INPUT) &&(GPIO_PORTB_PIN12_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN12_VALUE LOW
#elif (GPIO_PORTB_PIN12_MODE == INPUT) &&(GPIO_PORTB_PIN12_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN12_VALUE HIGH
#endif

/* PORTB - PIN13 */
#if   (GPIO_PORTB_PIN13_MODE == INPUT) &&(GPIO_PORTB_PIN13_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN13_VALUE LOW
#elif (GPIO_PORTB_PIN13_MODE == INPUT) &&(GPIO_PORTB_PIN13_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN13_VALUE HIGH
#endif

/* PORTB - PIN14 */
#if   (GPIO_PORTB_PIN14_MODE == INPUT) &&(GPIO_PORTB_PIN14_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN14_VALUE LOW
#elif (GPIO_PORTB_PIN14_MODE == INPUT) &&(GPIO_PORTB_PIN14_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN14_VALUE HIGH
#endif

/* PORTB - PIN15 */
#if   (GPIO_PORTB_PIN15_MODE == INPUT) &&(GPIO_PORTB_PIN15_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTB_PIN15_VALUE LOW
#elif (GPIO_PORTB_PIN15_MODE == INPUT) &&(GPIO_PORTB_PIN15_CNF == INPUT_PUSHUP)
	#define GPIO_PORTB_PIN15_VALUE HIGH
#endif

/* PORTC - PIN0 */
#if   (GPIO_PORTC_PIN0_MODE == INPUT) &&(GPIO_PORTC_PIN0_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN0_VALUE LOW
#elif (GPIO_PORTC_PIN0_MODE == INPUT) &&(GPIO_PORTC_PIN0_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN0_VALUE HIGH
#endif

/* PORTC - PIN1 */
#if   (GPIO_PORTC_PIN1_MODE == INPUT) &&(GPIO_PORTC_PIN1_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN1_VALUE LOW
#elif (GPIO_PORTC_PIN1_MODE == INPUT) &&(GPIO_PORTC_PIN1_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN1_VALUE HIGH
#endif

/* PORTC - PIN2 */
#if   (GPIO_PORTC_PIN2_MODE == INPUT) &&(GPIO_PORTC_PIN2_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN2_VALUE LOW
#elif (GPIO_PORTC_PIN2_MODE == INPUT) &&(GPIO_PORTC_PIN2_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN2_VALUE HIGH
#endif

/* PORTC - PIN3 */
#if   (GPIO_PORTC_PIN3_MODE == INPUT) &&(GPIO_PORTC_PIN3_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN3_VALUE LOW
#elif (GPIO_PORTC_PIN3_MODE == INPUT) &&(GPIO_PORTC_PIN3_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN3_VALUE HIGH
#endif

/* PORTC - PIN4 */
#if   (GPIO_PORTC_PIN4_MODE == INPUT) &&(GPIO_PORTC_PIN4_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN4_VALUE LOW
#elif (GPIO_PORTC_PIN4_MODE == INPUT) &&(GPIO_PORTC_PIN4_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN4_VALUE HIGH
#endif

/* PORTC - PIN5 */
#if   (GPIO_PORTC_PIN5_MODE == INPUT) &&(GPIO_PORTC_PIN5_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN5_VALUE LOW
#elif (GPIO_PORTC_PIN5_MODE == INPUT) &&(GPIO_PORTC_PIN5_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN5_VALUE HIGH
#endif

/* PORTC - PIN6 */
#if   (GPIO_PORTC_PIN6_MODE == INPUT) &&(GPIO_PORTC_PIN6_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN6_VALUE LOW
#elif (GPIO_PORTC_PIN6_MODE == INPUT) &&(GPIO_PORTC_PIN6_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN6_VALUE HIGH
#endif

/* PORTC - PIN7 */
#if   (GPIO_PORTC_PIN7_MODE == INPUT) &&(GPIO_PORTC_PIN7_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN7_VALUE LOW
#elif (GPIO_PORTC_PIN7_MODE == INPUT) &&(GPIO_PORTC_PIN7_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN7_VALUE HIGH
#endif

/* PORTC - PIN8 */
#if   (GPIO_PORTC_PIN8_MODE == INPUT) &&(GPIO_PORTC_PIN8_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN8_VALUE LOW
#elif (GPIO_PORTC_PIN8_MODE == INPUT) &&(GPIO_PORTC_PIN8_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN8_VALUE HIGH
#endif

/* PORTC - PIN9 */
#if   (GPIO_PORTC_PIN9_MODE == INPUT) &&(GPIO_PORTC_PIN9_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN9_VALUE LOW
#elif (GPIO_PORTC_PIN9_MODE == INPUT) &&(GPIO_PORTC_PIN9_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN9_VALUE HIGH
#endif

/* PORTC - PIN10 */
#if   (GPIO_PORTC_PIN10_MODE == INPUT) &&(GPIO_PORTC_PIN10_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN10_VALUE LOW
#elif (GPIO_PORTC_PIN10_MODE == INPUT) &&(GPIO_PORTC_PIN10_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN10_VALUE HIGH
#endif

/* PORTC - PIN11 */
#if   (GPIO_PORTC_PIN11_MODE == INPUT) &&(GPIO_PORTC_PIN11_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN11_VALUE LOW
#elif (GPIO_PORTC_PIN11_MODE == INPUT) &&(GPIO_PORTC_PIN11_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN11_VALUE HIGH
#endif

/* PORTC - PIN12 */
#if   (GPIO_PORTC_PIN12_MODE == INPUT) &&(GPIO_PORTC_PIN12_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN12_VALUE LOW
#elif (GPIO_PORTC_PIN12_MODE == INPUT) &&(GPIO_PORTC_PIN12_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN12_VALUE HIGH
#endif

/* PORTC - PIN13 */
#if   (GPIO_PORTC_PIN13_MODE == INPUT) &&(GPIO_PORTC_PIN13_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN13_VALUE LOW
#elif (GPIO_PORTC_PIN13_MODE == INPUT) &&(GPIO_PORTC_PIN13_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN13_VALUE HIGH
#endif

/* PORTC - PIN14 */
#if   (GPIO_PORTC_PIN14_MODE == INPUT) &&(GPIO_PORTC_PIN14_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN14_VALUE LOW
#elif (GPIO_PORTC_PIN14_MODE == INPUT) &&(GPIO_PORTC_PIN14_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN14_VALUE HIGH
#endif

/* PORTC - PIN15 */
#if   (GPIO_PORTC_PIN15_MODE == INPUT) &&(GPIO_PORTC_PIN15_CNF == INPUT_PUSHDOWN)
	#define GPIO_PORTC_PIN15_VALUE LOW
#elif (GPIO_PORTC_PIN15_MODE == INPUT) &&(GPIO_PORTC_PIN15_CNF == INPUT_PUSHUP)
	#define GPIO_PORTC_PIN15_VALUE HIGH
#endif
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define MGPIO_DONE      	0x01 
#define MGPIO_WRONG_PORT   	0x81        
#define MGPIO_WRONG_PIN    	0x82 
#define MGPIO_WRONG_MODE	0x84 
#define MGPIO_WRONG_VALUE	0x88
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 