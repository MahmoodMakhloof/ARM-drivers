/*******************************************************************/
/* Author  : Mahmoud Makhlouf                                      */
/* Date    : 15 Aug 2020                                           */
/* Version : V01                                                   */
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"

void RCC_VoidInitSysClock (void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000;
		RCC_CFGR = 0x00000001;

	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;
		RCC_CFGR = 0x00000001;

	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081;
		RCC_CFGR = 0x00000000;

	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if   RCC_PLL_INPUT_TYPE == RCC_PLL_IN_HSI_DIV_2
			RCC_CR   = 0x01000081;
			RCC_CFGR = (RCC_PLL_MUL_VAL << 18 ) + 0x00000002; 

		#elif RCC_PLL_INPUT_TYPE == RCC_PLL_IN_HSE_DIV_2
			#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
				RCC_CR   = 0x01010000;
				RCC_CFGR = (RCC_PLL_MUL_VAL << 18) + 0x00030002;

			#elif RCC_CLOCK_TYPE == RCC_HSE_RC
				RCC_CR   = 0x01050000;
				RCC_CFGR = (RCC_PLL_MUL_VAL << 18) + 0x00030002;

			#else 
				/* Error Message */
			#endif 

		#elif RCC_PLL_INPUT_TYPE == RCC_PLL_IN_HSE
			#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
				RCC_CR   = 0x01010000;
				RCC_CFGR = (RCC_PLL_MUL_VAL << 18) + 0x00010002;

			#elif RCC_CLOCK_TYPE == RCC_HSE_RC
				RCC_CR   = 0x01050000;
				RCC_CFGR = (RCC_PLL_MUL_VAL << 18) + 0x00010002;

			#else 
				/* Error Message */
			#endif 

		#else
			  /* Error Message */

		#endif

	#else
		/* Error Message */

	#endif
}


void RCC_VoidEnableClock (u8 CopyBusId ,u8 CopyPerId)
{
	if(CopyPerId < 32)
	{
		switch (CopyBusId)
		{
			case RCC_APB2: SET_BIT(RCC_APB2ENR,CopyPerId); break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR,CopyPerId); break;
			case RCC_AHB : SET_BIT(RCC_AHBENR ,CopyPerId); break;
			default  :  							       break;
		}

	}

	else
	{
		/* Error Message */
	}
}

void RCC_VoidDisableClock (u8 CopyBusId , u8 CopyPerId)
{
	if(CopyPerId < 32)
	{
		switch (CopyBusId)
		{
			case RCC_APB2: CLR_BIT(RCC_APB2ENR,CopyPerId); break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR,CopyPerId); break;
			case RCC_AHB : CLR_BIT(RCC_AHBENR ,CopyPerId); break;
			default  :  							       break;
		}

	}

	else
	{
		/* Error Message */
	}
}
