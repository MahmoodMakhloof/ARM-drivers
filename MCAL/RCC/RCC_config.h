/*******************************************************************/
/* Author  : Mahmoud Makhlouf                                      */
/* Date    : 15 Aug 2020                                           */
/* Version : V01                                                   */
/*******************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options : RCC_HSE_CRYSTAL
			 RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL */
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL


/* Options : RCC_PLL_IN_HSI_DIV_2
		     RCC_PLL_IN_HSE_DIV_2
		     RCC_PLL_IN_HSE */

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_TYPE RCC_PLL_IN_HSE_DIV_2
#endif

/* Options : 2 ~ 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL 4
#endif


#endif /* RCC_CONFIG_H */