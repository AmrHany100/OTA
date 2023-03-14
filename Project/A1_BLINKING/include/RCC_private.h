/***************************************************************************************************************************************************/
/*											               Reset and Clock Control Driver								                           */
/* File Name : RCC_private.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 08 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***************************************************************************************************************************************************/ 
/*                                                              Registers Definitions 															   */
/* Boundary address : 0x4002 1000 - 0x4002 13FF         																						   */
/* Bus				: AHB																														   */
/* Register map     : Section 7.3.11 on page 121																								   */
/***************************************************************************************************************************************************/ 
#define RCC_CR			*((volatile pu32)0x40021000)	// Clock control register (RCC_CR)
#define RCC_CFGR		*((volatile pu32)0x40021004)	// Clock configuration register (RCC_CFGR)
#define RCC_CIR			*((volatile pu32)0x40021008) 	// Clock interrupt register (RCC_CIR)
#define RCC_APB2RSTR	*((volatile pu32)0x4002100C) 	// APB2 peripheral reset register (RCC_APB2RSTR)
#define RCC_APB1RSTR	*((volatile pu32)0x40021010) 	// APB1 peripheral reset register (RCC_APB1RSTR)
#define RCC_AHBENR		*((volatile pu32)0x40021014) 	// AHB peripheral clock enable register (RCC_AHBENR)
#define RCC_APB2ENR		*((volatile pu32)0x40021018) 	// APB2 peripheral clock enable register (RCC_APB2ENR)
#define RCC_APB1ENR		*((volatile pu32)0x4002101C) 	// APB1 peripheral clock enable register (RCC_APB1ENR)
#define RCC_BDCR		*((volatile pu32)0x40021020) 	// Backup domain control register (RCC_BDCR)
#define RCC_CSR			*((volatile pu32)0x40021024) 	// Control/status register (RCC_CSR)
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                                 Registers Bits 			     												   */
/* RCC Registers: Section 7.3 Page 99           																								   */
/***************************************************************************************************************************************************/ 
/* Clock control register (RCC_CR) */
#define PLLRDY_BIT		25	// PLL clock ready flag Set by hardware to indicate that the PLL is locked | 0: PLL unlocked | 1: PLL locked
#define PLLON_BIT		24	// PLL enable | 0: PLL OFF | 1: PLL ON
#define CSSON_BIT		19	// Clock security system enable (Clock detector) | 0: OFF | 1: ON (ON if the HSE oscillator is ready,OFF if not)
#define HSEBYP_BIT		18	// External high-speed clock bypass | 0: external 4-16 MHz oscillator not bypassed | 1: bypassed with external clock
#define HSERDY_BIT		17	// External high-speed clock ready flag Set by hardware | 0: HSE oscillator not ready | 1: HSE oscillator ready
#define HSEON_BIT		16	// HSE clock enable | 0: HSE oscillator OFF | 1: HSE oscillator ON
#define HSICAL7_BIT		15	// HSICAL[7:0]: Internal high-speed clock calibration, These bits are initialized automatically at startup						
#define HSICAL6_BIT		14					
#define HSICAL5_BIT		13		
#define HSICAL4_BIT		12		
#define HSICAL3_BIT		11					
#define HSICAL2_BIT		10					
#define HSICAL1_BIT		9		
#define HSICAL0_BIT		8	
#define HSITRIM4_BIT	7	// HSITRIM[4:0]: Internal high-speed clock trimming, These bits provide an additional user-programmable trimming value
#define HSITRIM3_BIT	6   // that is added to the	HSICAL[7:0] bits, It can be programmed to adjust to variations in voltage and temperature
#define HSITRIM2_BIT	5   // that influence the frequency of the internal HSI RC
#define HSITRIM1_BIT	4   // The default value is 16, which, when added to the HSICAL value, should trim the HSI to 8MHz ± 1%. The trimming step
#define	HSITRIM0_BIT	3   // (Fhsitrim) is around 40 kHz between two consecutive HSICAL steps
#define HSIRDY_BIT		1	// Internal high-speed clock ready flag Set by hardware | 0: internal 8 MHz RC oscillator not ready | 1: sready
#define HSION_BIT		0	// Internal high-speed clock enable | 0: internal 8 MHz RC oscillator OFF | 1: internal 8 MHz RC oscillator ON

/* Clock configuration register (RCC_CFGR) */
#define MCO2_BIT		26	// MCO[2:0]: Microcontroller clock output | does not exceed 50 MHz (the maximum IO speed)
#define MCO1_BIT		25	// 0xx: No clock           | 100: System clock (SYSCLK) selected  | 101: HSI clock selected
#define MCO0_BIT		24	// 110: HSE clock selected | 111: PLL clock divided by 2 selected
#define USBPRE_BIT		22	// USB prescaler
#define PLLMUL3_BIT		21	// PLLMUL[3:0]: PLL multiplication factor, The PLL output frequency must not exceed 72 MHz
#define PLLMUL2_BIT		20	// 0000: PLL input clock x 2  | 0001: PLL input clock x 3  | 0010: PLL input clock x 4  | 0011: PLL input clock x 5
#define PLLMUL1_BIT		19	// 0100: PLL input clock x 6  | 0101: PLL input clock x 7  | 0110: PLL input clock x 8  | 0111: PLL input clock x 9
#define PLLMUL0_BIT		18	// 1000: PLL input clock x 10 | 1001: PLL input clock x 11 | 1010: PLL input clock x 12 | 1011: PLL input clock x 13
							// 1100: PLL input clock x 14 | 1101: PLL input clock x 15 | 1110: PLL input clock x 16 | 1111: PLL input clock x 16
#define PLLXTPRE_BIT	17	// HSE divider for PLL entry | 0: HSE clock not divided | 1: HSE clock divided by 2
#define PLLSRC_BIT		16	// PLL entry clock source | 0: HSI oscillator clock / 2 selected | 1: HSE oscillator clock selected	
#define ADCPRE1_BIT		15	// ADCPRE[1:0]: ADC prescaler		
#define ADCPRE0_BIT		14	// 00: PCLK2 divided by 2  | 01: PCLK2 divided by 4  | 10: PCLK2 divided by 6  | 11: PCLK2 divided by 8
#define PPRE22_BIT		13	// PPRE2[2:0]: APB high-speed prescaler (APB2)	
#define PPRE21_BIT		12	// 0xx: HCLK not divided  | 100: HCLK divided by 2 | 101: HCLK divided by 4	
#define PPRE20_BIT		11	// 101: HCLK divided by 8 | 111: HCLK divided by 16
#define PPRE12_BIT		10	// PPRE1[2:0]: APB low-speed prescaler (APB1) | These bits to not exceed 36 MHz on this domain 	
#define PPRE11_BIT		9	// 0xx: HCLK not divided  | 100: HCLK divided by 2 | 101: HCLK divided by 4	
#define PPRE10_BIT		8	// 101: HCLK divided by 8 | 111: HCLK divided by 16
#define HPRE3_BIT		7	// HPRE:[3:0]: AHB prescaler			
#define HPRE2_BIT		6	// 0xxx: HCLK not divided    | 1000: HCLK divided by 2  | 1001: HCLK divided by 4   | 1010: HCLK divided by 8		
#define HPRE1_BIT		5	// 1011: HCLK divided by 16  | 1100: HCLK divided by 64 | 1101: HCLK divided by 128 | 1110: HCLK divided by 256
#define HPRE0_BIT		4	// 1111: HCLK divided by 512
#define SWS1_BIT		3	// SWS[1:0]: System clock switch status, Indicate which clock source is used as system clock			
#define SWS0_BIT		2	// 00: HSI oscillator | 01: HSE oscillator | 10: PLL | 11: not applicable			
#define SW1_BIT			1	// SW[1:0]: System clock switch, Set and cleared by software to select SYSCLK source		
#define SW0_BIT			0	// 00: HSI selected | 01: HSE selected | 10: PLL selected| 11: not allowed
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/* RCC Registers: Section 7.3 Page 99           																								   */
/***************************************************************************************************************************************************/ 
/* Magic Numbers */
#define MRCC_INITIAL_VALUE 			0
#define	MRCC_0		 				0
#define	MRCC_4		 				4
#define	MRCC_15		 				15
#define	MRCC_16		 				16
#define	MRCC_CONC_8 				8
#define	MRCC_CONC_16 				16
#define	MRCC_CONC_24 				14
#define MRCC_0x00000000				0x00000000
#define MRCC_0x00000001				0x00000001
#define MRCC_0x00000002				0x00000002
#define MRCC_0x00000081				0x00000081
#define MRCC_0x00010000				0x00010000
#define MRCC_0x00010002				0x00010002
#define MRCC_0x00030002				0x00030002
#define MRCC_0x00050000				0x00050000
#define MRCC_0x01000081				0x01000081
#define MRCC_0x01010000				0x01010000
#define MRCC_0x01050000				0x01050000

/* Clock Types */
#define MRCC_HSE_CRYSTAL			0
#define MRCC_HSE_RC					1
#define MRCC_HSI					2
#define MRCC_PLL					3

/* Bypass */
#define RCC_BYBASS_OFF				0
#define RCC_BYBASS_ON				1

/* PLL Input Options */	
#define MRCC_PLL_IN_HSI_DIV_2		0
#define MRCC_PLL_IN_HSE_DIV_2		1
#define MRCC_PLL_IN_HSE				2

/* PLL multiplication factor */
#define	MRCC_PLL_INPUT_CLOCK_X2		0b0000
#define	MRCC_PLL_INPUT_CLOCK_X3		0b0001
#define	MRCC_PLL_INPUT_CLOCK_X4		0b0010
#define	MRCC_PLL_INPUT_CLOCK_X5		0b0011
#define	MRCC_PLL_INPUT_CLOCK_X6		0b0100
#define	MRCC_PLL_INPUT_CLOCK_X7		0b0101
#define	MRCC_PLL_INPUT_CLOCK_X8		0b0110
#define	MRCC_PLL_INPUT_CLOCK_X9		0b0111
#define	MRCC_PLL_INPUT_CLOCK_X10	0b1000
#define	MRCC_PLL_INPUT_CLOCK_X11	0b1001
#define	MRCC_PLL_INPUT_CLOCK_X12	0b1010
#define	MRCC_PLL_INPUT_CLOCK_X13	0b1011
#define	MRCC_PLL_INPUT_CLOCK_X14	0b1100
#define	MRCC_PLL_INPUT_CLOCK_X15	0b1101
#define	MRCC_PLL_INPUT_CLOCK_X16	0b1110

/* States */
#define MRCC_DISABLE				0 
#define MRCC_ENABLE 				1

/* Output on MCO Pin */
#define MRCC_NO_CLOCK				0
#define MRCC_SYSTEM_CLOCK			1
#define MRCC_HSI_CLOCK				2
#define MRCC_HSE_CLOCK				3
#define MRCC_PLL_DIV_2_CLOCK		4

/* Prescaller */
#define MRCC_PRESCALLER_1			0
#define MRCC_PRESCALLER_2			1
#define MRCC_PRESCALLER_4			2
#define MRCC_PRESCALLER_6			3
#define MRCC_PRESCALLER_8			4
#define MRCC_PRESCALLER_16			5
#define MRCC_PRESCALLER_64			6
#define MRCC_PRESCALLER_128			7
#define MRCC_PRESCALLER_256			8
#define MRCC_PRESCALLER_512			9
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define MRCC_DONE      				0x01 
#define MRCC_WRONG_BUS   			0x81        
#define MRCC_WRONG_PER    			0x82 
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 