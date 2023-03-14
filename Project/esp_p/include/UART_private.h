/***************************************************************************************************************************************************/
/*                                                                   UART Driver                                                                   */
/* File Name : UART_private.h 																	    											   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 27 SEP 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/***************************************************************************************************************************************************/ 
/*                                                              Registers Definitions 															   */
/* 																	   USART1 																	   */
/* Boundary address : 0x4001 3800 - 0x4001 3BFF															 									       */
/* Bus				: APB2																														   */
/* 																	   USART2 																	   */
/* Boundary address : 0x4000 4400 - 0x4000 47FF																 									   */
/* Bus				: APB1																														   */
/* 																	   USART3 																	   */
/* Boundary address : 0x4000 4800 - 0x4000 4BFF															 									  	   */
/* Bus				: APB1																														   */
/* 																	   USART4 																	   */
/* Boundary address : 0x4000 4C00 - 0x4000 4FFF															 									  	   */
/* Bus				: APB1																														   */
/* 																	   USART5 																	   */
/* Boundary address : 0x4000 5000 - 0x4000 53FF 														 									  	   */
/* Bus				: APB1																														   */
/*                                                                                                                                                 */
/* Register map     : Section 27.6.8 on page 827																								   */ 
/***************************************************************************************************************************************************/ 
/* USART1 Base Address */
#define MUART1_BASE_ADDRESS	0x40013800
/* USART2 Base Address */
#define MUART2_BASE_ADDRESS	0x40004400
/* USART3 Base Address */
#define MUART3_BASE_ADDRESS	0x40004800
/* USART4 Base Address */
#define MUART4_BASE_ADDRESS	0x40004C00
/* USART5 Base Address */
#define MUART5_BASE_ADDRESS	0x40005000

/* USART Registers */
typedef struct
{
	volatile u32 SR  ;				// Status register (USART_SR)	
	volatile u32 DR  ;				// Data register (USART_DR)
	volatile u32 BRR ;				// Baud rate register (USART_BRR)
	volatile u32 CR1 ;				// Control register 1 (USART_CR1) 
	volatile u32 CR2 ;      		// Control register 2 (USART_CR2)
	volatile u32 CR3 ;	    		// Control register 3 (USART_CR3)
	volatile u32 GTPR;				// Guard time and prescaler register (USART_GTPR)			
}MUART_Type;

#define MUART1				((volatile MUART_Type*)MUART1_BASE_ADDRESS)
#define MUART2				((volatile MUART_Type*)MUART2_BASE_ADDRESS)
#define MUART3				((volatile MUART_Type*)MUART3_BASE_ADDRESS)
#define MUART4				((volatile MUART_Type*)MUART4_BASE_ADDRESS)
#define MUART5				((volatile MUART_Type*)MUART5_BASE_ADDRESS)

volatile MUART_Type* MUART[] = 
{
	MUART1,    
	MUART2,    
	MUART3,    
	MUART4,    
	MUART5    
};
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                 Registers Bits 			     												   */
/* UART Registers : Section 27.6 on page 817    																								   */
/***************************************************************************************************************************************************/ 
/* Status register (USART_SR) */
#define CTS_BIT				9		// CTS flag
#define LBD_BIT				8       // LIN break detection flag
#define TXE_BIT				7       // Transmit data register empty
#define TC_BIT				6       // Transmission complete
#define RXNE_BIT			5       // Read data register not empty
#define IDLE_BIT			4       // IDLE line detected
#define ORE_BIT				3       // Overrun error
#define NE_BIT				2       // Noise error flag
#define FE_BIT				1       // Framing error
#define PE_BIT				0       // Parity error

/* Baud rate register (USART_BRR) */
#define DIV_Mantissa11_BIT	15		// DIV_Mantissa[11:0]: mantissa of USARTDIV
#define DIV_Mantissa10_BIT	14
#define DIV_Mantissa9_BIT	13
#define DIV_Mantissa8_BIT	12
#define DIV_Mantissa7_BIT	11
#define DIV_Mantissa6_BIT	10
#define DIV_Mantissa5_BIT	9
#define DIV_Mantissa4_BIT	8
#define DIV_Mantissa3_BIT	7
#define DIV_Mantissa2_BIT	6
#define DIV_Mantissa1_BIT	5
#define DIV_Mantissa0_BIT	4
#define DIV_Fraction3_BIT	3		// DIV_Fraction[3:0]: fraction of USARTDIV
#define DIV_Fraction2_BIT	2
#define DIV_Fraction1_BIT	1
#define DIV_Fraction0_BIT	0

/* Control register 1 (USART_CR1) */ 
#define UE_BIT				13		// USART enable
#define M_BIT				12      // Word length
#define WAKE_BIT			11      // Wakeup method
#define PCE_BIT				10      // Parity control enable
#define PS_BIT				9       // Parity selection
#define PEIE_BIT			8       // PE interrupt enable
#define TXEIE_BIT			7       // TXE interrupt enable
#define TCIE_BIT			6       // Transmission complete interrupt enable
#define RXNEIE_BIT			5       // RXNE interrupt enable
#define IDLEIE_BIT			4       // IDLE interrupt enable
#define TE_BIT				3		// Transmitter enable
#define RE_BIT				2       // Receiver enable
#define RWU_BIT				1       // Receiver wakeup
#define SBK_BIT				0       // Send break

/* Control register 2 (USART_CR2) */
#define LINEN_BIT			14		// LIN mode enable
#define STOP1_BIT			13		// STOP bits 
#define STOP0_BIT			12      // 
#define CLKEN_BIT			11      // Clock enable
#define CPOL_BIT			10      // Clock polarity
#define CPHA_BIT			9       // Clock phase
#define LBCL_BIT			8       // Last bit clock pulse
#define LBDIE_BIT			6       // LIN break detection interrupt enable
#define LBDL_BIT			5       // lin break detection length
#define ADD3_BIT			3		// Address of the USART node
#define ADD2_BIT			2       // 
#define ADD1_BIT			1       // 
#define ADD0_BIT			0       // 

/* Control register 3 (USART_CR3) */
#define CTSIE_BIT			10      // CTS interrupt enable
#define CTSE_BIT			9       // CTS enable
#define RTSE_BIT			8       // RTS enable
#define DMAT_BIT			7       // DMA enable transmitter
#define DMAR_BIT			6       // DMA enable receiver
#define SCEN_BIT			5       // Smartcard mode enable
#define NACK_BIT			4       // Smartcard NACK enable
#define HDSEL_BIT			3		// Half-duplex selection
#define IRLP_BIT			2       // IrDA low-power
#define IREN_BIT			1       // IrDA mode enable
#define EIE_BIT				0       // Error interrupt enable

/* Guard time and prescaler register (USART_GTPR) */			
#define GT7_BIT				15		// Guard time value
#define GT6_BIT				14		// 
#define GT5_BIT				13		// 
#define GT4_BIT				12      // 
#define GT3_BIT				11      // 
#define GT2_BIT				10      // 
#define GT1_BIT				9       // 
#define GT0_BIT				8       // 
#define PSC7_BIT			7       // Prescaler value
#define PSC6_BIT			6       // 
#define PSC5_BIT			5       // 
#define PSC4_BIT			4		// 
#define PSC3_BIT			3		// 
#define PSC2_BIT			2       // 
#define PSC1_BIT			1       // 
#define PSC0_BIT			0       // 
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/  
/*                                                                     Private															       	   */
/***************************************************************************************************************************************************/ 
/* Magic Numbers */
#define MUART_INITIAL_VALUE 0
#define MUART_0			 	0
#define MUART_1			 	1
#define MUART_4			 	4
#define MUART_16		 	16
#define MUART_255		 	255
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                CallBack Functions                                                               */
/***************************************************************************************************************************************************/
#define NULL				((void*)0x00)
static void (*MUART1_CallBack)(u16) = NULL;
static void (*MUART2_CallBack)(u16) = NULL;

/* ISR */
void UART1_IRQHandler(void)
{
	/* Do Nothing */
	
}

void UART2_IRQHandler(void)
{
	/* Do Nothing */
}
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/
/*                                                                  Return Value                                                                   */
/***************************************************************************************************************************************************/
#define MUART_DONE      		0x01 
#define MUART_WRONG_STATE		0x81 
#define MUART_WRONG_WORD_LENGTH	0x82 
#define MUART_WRONG_PARITY		0x83 
#define MUART_WRONG_RT_STATE	0x84 
#define MUART_WRONG_UARTChannel	0x85
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 