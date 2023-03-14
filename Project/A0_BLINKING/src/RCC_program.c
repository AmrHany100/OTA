/***************************************************************************************************************************************************/
/*											               Reset and Clock Control Driver								                           */
/* File Name : RCC_program.c 																	    											   */
/* Author    : Amr Hany															 	    										   */
/* Version	 : 1.0.0																		 	    											   */
/* Date      : 08 AUG 2020 																	 	    											   */
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
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/ 
/*                                                                    Functions                                                                    */
/***************************************************************************************************************************************************/ 
/* Initialization */
void MRCC_voidInitSysClock(void)
{
	/* Clear Registers */
	RCC_CR   = MRCC_0;
	RCC_CFGR = MRCC_0;
	
	/* Choosing Clock */
	#if   MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL
		/* Enable HSE with no bypass */
		SET_BIT(RCC_CR,HSEON_BIT); 		
		//CLR_BIT(RCC_CR,HSEBYP_BIT);		
		/*  Waiting till Ready */
		//while(!(GET_BIT(RCC_CR,HSERDY_BIT)));
		/* Choosing HSE */
		//CLR_BIT(RCC_CFGR,SW1_BIT);
		SET_BIT(RCC_CFGR,SW0_BIT);	
		
	#elif MRCC_CLOCK_TYPE == MRCC_HSE_RC		
		/* Enable HSE with bypass */
		SET_BIT(RCC_CR,HSEON_BIT); 		
		SET_BIT(RCC_CR,HSEBYP_BIT);		
		/*  Waiting till Ready */
		//while(!(GET_BIT(RCC_CR,HSERDY_BIT)));
		/* Choosing HSE */
		//CLR_BIT(RCC_CFGR,SW1_BIT);
		SET_BIT(RCC_CFGR,SW0_BIT);	
		
	#elif	MRCC_CLOCK_TYPE == MRCC_HSI	
		/* Enable HSI + Trimming = 0 */
		SET_BIT(RCC_CR,HSION_BIT);
		SET_BIT(RCC_CR,HSITRIM4_BIT);
		/*  Waiting till Ready */
		//while(!(GET_BIT(RCC_CR,HSIRDY_BIT)));		
		/* Choosing HSI */
		//CLR_BIT(RCC_CFGR,SW1_BIT);
		//CLR_BIT(RCC_CFGR,SW0_BIT);	
		
	#elif	MRCC_CLOCK_TYPE == MRCC_PLL	
	`	/* PLL multiplication factor */
		#if MRCC_PLL_MUL_VAL <= MRCC_PLL_INPUT_CLOCK_X16)
			/* Clear the bits (PLLMULx_BIT) */	
			//CLR_BIT(RCC_CFGR,PLLMUL0_BIT);
			//CLR_BIT(RCC_CFGR,PLLMUL1_BIT);
			//CLR_BIT(RCC_CFGR,PLLMUL2_BIT);
			//CLR_BIT(RCC_CFGR,PLLMUL3_BIT);
			/* Load the value */
			GIV_BIT(RCC_CFGR,MRCC_PLL_MUL_VAL,PLLMUL0_BIT);
		#else
			#error("Configuration Error :: Wrong MRCC_PLL_MUL_VAL")
		#endif	
		/* PLL entry clock source */
		#if	  MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_DIV_2
			/* Enable HSI + Trimming = 0 */
			SET_BIT(RCC_CR,HSION_BIT);	
			SET_BIT(RCC_CR,HSITRIM4_BIT);
			/* PPL Input: HSI/2 */
			//CLR_BIT(RCC_CFGR,PLLSRC_BIT);							
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2
			/* Enable HSE */
			SET_BIT(RCC_CR,HSEON_BIT);
			/* PPL Input: HSE/2 */
			SET_BIT(RCC_CFGR,PLLSRC_BIT);
			/* Enable prescaller by 2 */
			SET_BIT(RCC_CFGR,PLLXTPRE_BIT);	
			/* Bypass */
			#if   MRCC_BYPASS == MRCC_BYBASS_OFF
				//CLR_BIT(RCC_CR,HSEBYP_BIT);
			#elif MRCC_BYPASS == MRCC_BYBASS_ON
				SET_BIT(RCC_CR,HSEBYP_BIT);
			#else
				#error("Configuration Error :: Wrong MRCC_BYPASS")	
			#endif
		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE	
			/* Enable HSE */
			SET_BIT(RCC_CR,HSEON_BIT); 	
			/* PPL Input: HSE */
			SET_BIT(RCC_CFGR,PLLSRC_BIT);
			/* Disable prescaller by 2 */
			//CLR_BIT(RCC_CFGR,PLLXTPRE_BIT);
			/* Bypass */			
			#if   MRCC_BYPASS == MRCC_BYBASS_OFF
				//CLR_BIT(RCC_CR,HSEBYP_BIT);
			#elif MRCC_BYPASS == MRCC_BYBASS_ON
				SET_BIT(RCC_CR,HSEBYP_BIT);
			#else
				#error("Configuration Error :: Wrong MRCC_BYPASS")	
			#endif
		#else
			#error("Configuration Error :: Wrong MRCC_PLL_INPUT")
		#endif
		/*  Waiting till Ready */
		//while(!(GET_BIT(RCC_CR,PLLRDY_BIT)));
		/* Enable PLL */
		SET_BIT(RCC_CR,PLLON_BIT); 
		/* Choosing PLL */     
		SET_BIT(RCC_CFGR,SW1_BIT);
		//CLR_BIT(RCC_CFGR,SW0_BIT);
		
	#else
		#error("Configuration Error :: Wrong MRCC_CLOCK_TYPE")
	#endif

	/* Output on MCO Pin */
	#if   MRCC_MCO_PIN == MRCC_NO_CLOCK 
		//CLR_BIT(RCC_CFGR,MCO2_BIT);
	#elif MRCC_MCO_PIN == MRCC_SYSTEM_CLOCK
		SET_BIT(RCC_CFGR,MCO2_BIT);
		//CLR_BIT(RCC_CFGR,MCO1_BIT);
		//CLR_BIT(RCC_CFGR,MCO0_BIT);
	#elif MRCC_MCO_PIN == MRCC_HSI_CLOCK
		/* Enable HSI + Trimming = 0 */
		SET_BIT(RCC_CR,HSION_BIT);
		SET_BIT(RCC_CR,HSITRIM4_BIT);
		SET_BIT(RCC_CFGR,MCO2_BIT);
		//CLR_BIT(RCC_CFGR,MCO1_BIT);
		SET_BIT(RCC_CFGR,MCO0_BIT);
    #elif MRCC_MCO_PIN == MRCC_HSE_CLOCK
		/* Enable HSE */
		SET_BIT(RCC_CR,HSEON_BIT);
		SET_BIT(RCC_CFGR,MCO2_BIT);
		SET_BIT(RCC_CFGR,MCO1_BIT);
		//CLR_BIT(RCC_CFGR,MCO0_BIT);
	#elif MRCC_MCO_PIN == MRCC_PLL_CLOCK
		SET_BIT(RCC_CFGR,MCO2_BIT);
		SET_BIT(RCC_CFGR,MCO1_BIT);
		SET_BIT(RCC_CFGR,MCO0_BIT);
		#error("Configuration Error :: Wrong MRCC_MCO_PIN")
	#endif
	
	/* Set the Trimming (HSI) */
	#if ((MRCC_CLOCK_TYPE == MRCC_HSI) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_DIV_2))
		#if ((MRCC_HSI_TRIMMING >= -MRCC_16) && (MRCC_HSI_TRIMMING <= MRCC_15))
			/* Clear the bits (HSITRIMx_BIT) */
			CLR_BIT(RCC_CR,HSITRIM4_BIT);
			//CLR_BIT(RCC_CR,HSITRIM3_BIT);
			//CLR_BIT(RCC_CR,HSITRIM2_BIT);
			//CLR_BIT(RCC_CR,HSITRIM1_BIT);
			//CLR_BIT(RCC_CR,HSITRIM0_BIT);
			GIV_BIT(RCC_CR,MRCC_HSI_TRIMMING+MRCC_16,HSITRIM0_BIT);
		#else
			#error("Configuration Error :: Wrong MRCC_HSI_TRIMMING")
		#endif
	#else
		/* Do Nothing */
	#endif
	
	/* Clock Security System (HSE) */ 
	#if ((MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL)     || (MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL) || \
         (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE))
		#if   MRCC_CSS == MRCC_ENABLE 
			SET_BIT(RCC_CR,CSSON_BIT);
		#elif MRCC_CSS == MRCC_DISABLE
			//CLR_BIT(RCC_CR,CSSON_BIT);
		#else
			#error("Configuration Error :: Wrong MRCC_CSS")
		#endif
	#else
		/* Do Nothing */
	#endif
	
	/* ADC Prescaller */
	#if   MRCC_ADC_PRESCALLER == MRCC_PRESCALLER_2 
		//CLR_BIT(RCC_CFGR,ADCPRE1_BIT);
		//CLR_BIT(RCC_CFGR,ADCPRE0_BIT);
	#elif MRCC_ADC_PRESCALLER == MRCC_PRESCALLER_4
		//CLR_BIT(RCC_CFGR,ADCPRE1_BIT);
		SET_BIT(RCC_CFGR,ADCPRE0_BIT);
	#elif MRCC_ADC_PRESCALLER == MRCC_PRESCALLER_6
		SET_BIT(RCC_CFGR,ADCPRE1_BIT);
		//CLR_BIT(RCC_CFGR,ADCPRE0_BIT);
	#elif MRCC_ADC_PRESCALLER == MRCC_PRESCALLER_8
		SET_BIT(RCC_CFGR,ADCPRE1_BIT);
		SET_BIT(RCC_CFGR,ADCPRE0_BIT);
	#else
		#error("Configuration Error :: Wrong MRCC_ADC_PRESCALLER")
	#endif
	
	/* APB2 Prescaller */
	#if   MRCC_APB2_PRESCALLER == MRCC_PRESCALLER_1
		//CLR_BIT(RCC_CFGR,PPRE22_BIT);
	#elif MRCC_APB2_PRESCALLER == MRCC_PRESCALLER_2
		SET_BIT(RCC_CFGR,PPRE22_BIT);
		//CLR_BIT(RCC_CFGR,PPRE21_BIT);
		//CLR_BIT(RCC_CFGR,PPRE20_BIT);
	#elif MRCC_APB2_PRESCALLER == MRCC_PRESCALLER_4
		SET_BIT(RCC_CFGR,PPRE22_BIT);
		//CLR_BIT(RCC_CFGR,PPRE21_BIT);
		SET_BIT(RCC_CFGR,PPRE20_BIT);
	#elif MRCC_APB2_PRESCALLER == MRCC_PRESCALLER_8
		SET_BIT(RCC_CFGR,PPRE22_BIT);
		SET_BIT(RCC_CFGR,PPRE21_BIT);
		//CLR_BIT(RCC_CFGR,PPRE20_BIT);
	#elif MRCC_APB2_PRESCALLER == MRCC_PRESCALLER_16
		SET_BIT(RCC_CFGR,PPRE22_BIT);
		SET_BIT(RCC_CFGR,PPRE21_BIT);
		SET_BIT(RCC_CFGR,PPRE20_BIT);
	#else
		#error("Configuration Error :: Wrong MRCC_APB2_PRESCALLER")
	#endif
	
	/* APB1 Prescaller */
	#if   MRCC_APB1_PRESCALLER == MRCC_PRESCALLER_1
		//CLR_BIT(RCC_CFGR,PPRE12_BIT);
	#elif MRCC_APB1_PRESCALLER == MRCC_PRESCALLER_2
		SET_BIT(RCC_CFGR,PPRE12_BIT);
		//CLR_BIT(RCC_CFGR,PPRE11_BIT);
		//CLR_BIT(RCC_CFGR,PPRE10_BIT);
	#elif MRCC_APB1_PRESCALLER == MRCC_PRESCALLER_4
		SET_BIT(RCC_CFGR,PPRE12_BIT);
		//CLR_BIT(RCC_CFGR,PPRE11_BIT);
		SET_BIT(RCC_CFGR,PPRE10_BIT);
	#elif MRCC_APB1_PRESCALLER == MRCC_PRESCALLER_8
		SET_BIT(RCC_CFGR,PPRE12_BIT);
		SET_BIT(RCC_CFGR,PPRE11_BIT);
		//CLR_BIT(RCC_CFGR,PPRE10_BIT);
	#elif MRCC_APB1_PRESCALLER == MRCC_PRESCALLER_16
		SET_BIT(RCC_CFGR,PPRE12_BIT);
		SET_BIT(RCC_CFGR,PPRE11_BIT);
		SET_BIT(RCC_CFGR,PPRE10_BIT);
	#else
		#error("Configuration Error :: Wrong MRCC_APB1_PRESCALLER")
	#endif
	
	/* AHB Prescaller */
	#if   MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_1
		//CLR_BIT(RCC_CFGR,HPRE3_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_2
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		//CLR_BIT(RCC_CFGR,HPRE2_BIT);
		//CLR_BIT(RCC_CFGR,HPRE1_BIT);
		//CLR_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_4
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		//CLR_BIT(RCC_CFGR,HPRE2_BIT);
		//CLR_BIT(RCC_CFGR,HPRE1_BIT);
		SET_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_8
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		//CLR_BIT(RCC_CFGR,HPRE2_BIT);
		SET_BIT(RCC_CFGR,HPRE1_BIT);
		//CLR_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_16
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		//CLR_BIT(RCC_CFGR,HPRE2_BIT);
		SET_BIT(RCC_CFGR,HPRE1_BIT);
		SET_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_64
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		SET_BIT(RCC_CFGR,HPRE2_BIT);
		//CLR_BIT(RCC_CFGR,HPRE1_BIT);
		//CLR_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_128
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		SET_BIT(RCC_CFGR,HPRE2_BIT);
		//CLR_BIT(RCC_CFGR,HPRE1_BIT);
		SET_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_256
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		SET_BIT(RCC_CFGR,HPRE2_BIT);
		SET_BIT(RCC_CFGR,HPRE1_BIT);
		//CLR_BIT(RCC_CFGR,HPRE0_BIT);
	#elif MRCC_AHB_PRESCALLER == MRCC_PRESCALLER_512
		SET_BIT(RCC_CFGR,HPRE3_BIT);
		SET_BIT(RCC_CFGR,HPRE2_BIT);
		SET_BIT(RCC_CFGR,HPRE1_BIT);
		SET_BIT(RCC_CFGR,HPRE0_BIT);
	#else
		#error("Configuration Error :: Wrong MRCC_AHB_PRESCALLER")
	#endif
	
	/* return MRCC_WRONG_PER; */
}


/* Clock Control to Peripherals */
void MRCC_voidEnableClock(MRCC_BusId_Type Copy_BusId, MRCC_PerId_Type Copy_PerId)
{
	if (Copy_PerId <= MRCC_DAC)
	{
		switch (Copy_BusId)
		{
			case MRCC_AHB  : SET_BIT(RCC_AHBENR, Copy_PerId);	/* return MRCC_DONE; */	break;
			case MRCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_PerId);	/* return MRCC_DONE; */	break;
			case MRCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_PerId);	/* return MRCC_DONE; */	break;
			default       : /* return RCC_WRONG_BUS; */				 					break;
		}
	}
	
	else
	{
		/* return MRCC_WRONG_PER; */
	}
}

void MRCC_voidDisableClock(MRCC_BusId_Type Copy_BusId, MRCC_PerId_Type Copy_PerId)
{
	if (Copy_PerId <= MRCC_DAC)
	{
		switch (Copy_BusId)
		{
			case MRCC_AHB : CLR_BIT(RCC_AHBENR, Copy_PerId);	/* return MRCC_DONE; */	break;
			case MRCC_APB1:	CLR_BIT(RCC_APB1ENR,Copy_PerId);	/* return MRCC_DONE; */	break;
			case MRCC_APB2: CLR_BIT(RCC_APB2ENR,Copy_PerId);	/* return MRCC_DONE; */	break;
			default       : /* return RCC_WRONG_BUS; */				 					break;
		}
	}
	
	else
	{
		/* return MRCC_WRONG_PER; */
	}
}
/***************************************************************************************************************************************************/ 

/***************************************************************************************************************************************************/