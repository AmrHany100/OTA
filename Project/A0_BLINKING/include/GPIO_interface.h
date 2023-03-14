/***************************************************************************************************************************************************/
/*											                         GPIO Driver								                		           */
/* File Name : GPIO_interface.h 																	    										   */
/* Author    : Amr Hany														 	    											   */
/* Version	 : 1.0.0		 																 	    											   */
/* Date      : 14 AUG 2020 																	 	    											   */
/* MC        : STM32F10x [ARM]																 	    											   */
/* Layer     : MCAL				 																	    										   */
/***************************************************************************************************************************************************/
#ifndef GPIO_INRERFACE_H
#define GPIO_INRERFACE_H

/***************************************************************************************************************************************************/ 
/*                                                                  Macros/Enums																   */
/***************************************************************************************************************************************************/ 
/* Ports */
typedef enum 
{
	PORTA,
	PORTB,
	PORTC
}MGPIO_PORT_Type;

typedef enum	
{	
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}MGPIO_PIN_Type;

/* Pin Mode Options  */ 								// Configuration mode 
#define OUTPUT_SPEED_10MHZ_PP		0b0001		// General purpose output 	 | Push-pull  | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_OD		0b0101  	// General purpose output 	 | Open-drain | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_AFPP		0b1001  	// Alternate Function output | Push-pull  | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_AFOD		0b1101  	// Alternate Function output | Open-drain | Speed: 10MHz
		
#define OUTPUT_SPEED_2MHZ_PP		0b0010  	// General purpose output 	 | Push-pull  | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_OD		0b0110  	// General purpose output 	 | Open-drain | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_AFPP		0b1010  	// Alternate Function output | Push-pull  | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_AFOD		0b1110  	// Alternate Function output | Open-drain | Speed:  2MHz
		
#define OUTPUT_SPEED_50MHZ_PP		0b0011  	// General purpose output 	 | Push-pull  | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_OD		0b0111  	// General purpose output 	 | Open-drain | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_AFPP		0b1011  	// Alternate Function output | Push-pull  | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_AFOD		0b1111  	// Alternate Function output | Open-drain | Speed: 50MHz
		
#define	INPUT_ANALOG				0b0000		// Input | Analog							
#define	INPUT_FLOATING				0b0100  	// Input | Input floating							
#define	INPUT_PULL_DOWN				0b1000  	// Input | Input pull-down		
#define	INPUT_PULL_UP				0b1100	  	// Input | Input pull-up   | *INPUT_PULL_UP = 0b1000 but for switching let = 0b1100

/* Port Mode Options (unused) *//* 								// Configuration mode 
#define OUTPUT_SPEED_10MHZ_PP_ALL	0x11111111	// General purpose output 	 | Push-pull  | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_OD_ALL	0x55555555  // General purpose output 	 | Open-drain | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_AFPP_ALL	0x99999999  // Alternate Function output | Push-pull  | Speed: 10MHz
#define OUTPUT_SPEED_10MHZ_AFOD_ALL	0xDDDDDDDD  // Alternate Function output | Open-drain | Speed: 10MHz

#define OUTPUT_SPEED_2MHZ_PP_ALL	0x22222222  // General purpose output 	 | Push-pull  | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_OD_ALL	0x66666666  // General purpose output 	 | Open-drain | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_AFPP_ALL	0xAAAAAAAA  // Alternate Function output | Push-pull  | Speed:  2MHz
#define OUTPUT_SPEED_2MHZ_AFOD_ALL	0xEEEEEEEE  // Alternate Function output | Open-drain | Speed:  2MHz

#define OUTPUT_SPEED_50MHZ_PP_ALL	0x33333333  // General purpose output 	 | Push-pull  | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_OD_ALL	0x77777777  // General purpose output 	 | Open-drain | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_AFPP_ALL	0xBBBBBBBB  // Alternate Function output | Push-pull  | Speed: 50MHz
#define OUTPUT_SPEED_50MHZ_AFOD_ALL	0xFFFFFFFF  // Alternate Function output | Open-drain | Speed: 50MHz

#define	INPUT_ANALOG_ALL			0x00000000	// Input | Analog						
#define	INPUT_FLOATING_ALL			0x44444444  // Input | Input floating							
#define	INPUT_PULL_DOWN_ALL			0x88888888  // Input | Input pull-down			
#define	INPUT_PULL_UP_ALL			0xCCCCCCCC  // Input | Input pull-up   | *INPUT_PULL_UP_ALL = 0x88888888 but for switching let = 0xCCCCCCCC*/

/* Pin Value Options */	
#define LOW							0
#define HIGH						1

/* Port Value Options */		
#define LOW_ALL						0x0000
#define HIGH_ALL					0xFFFF
/***************************************************************************************************************************************************/

/***************************************************************************************************************************************************/ 
/*                                                              Functions Declaration															   */
/***************************************************************************************************************************************************/
/* Initialization */
void MGPIO_voidInit             (void);

/* IO Pins */
void MGPIO_voidSetPinDirection  (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin, u8 Copy_u8Mode);
void MGPIO_voidLockPinMode      (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin);
void MGPIO_voidSetPinValue      (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin, u8 Copy_u8Value);
void MGPIO_voidSetPin           (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin);
void MGPIO_voidResetPin         (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin);
void MGPIO_voidTogglePinValue   (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin);
u8   MGPIO_u8GetPinValue        (MGPIO_PORT_Type Copy_Port, MGPIO_PIN_Type Copy_Pin);

/* IO Ports */
void MGPIO_voidSetPortDirection (MGPIO_PORT_Type Copy_Port, u8 Copy_u8Mode);
void MGPIO_voidLockPortMode     (MGPIO_PORT_Type Copy_Port);
void MGPIO_voidSetPortValue     (MGPIO_PORT_Type Copy_Port, u16 Copy_u16Value);
void MGPIO_voidTogglePortValue  (MGPIO_PORT_Type Copy_Port);
u16  MGPIO_u16GetPortValue      (MGPIO_PORT_Type Copy_Port);
/***************************************************************************************************************************************************/

#endif
/***************************************************************************************************************************************************/ 