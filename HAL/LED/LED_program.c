/******************************************************************/
/* Author  : Mahmoud Makhlouf                                     */
/* Date    : 16 Aug 2020                                          */
/* Version : V01                                                  */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

void LED_VoidON(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	#if   LED_ACTIVE_STATE == ACTIVE_LOW
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,LOW );

	#elif LED_ACTIVE_STATE == ACTIVE_HIGH
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,HIGH);

	#else
		/* Error Message */
	#endif
}

void LED_voidOFF(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	#if   LED_ACTIVE_STATE == ACTIVE_LOW
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,HIGH);

	#elif LED_ACTIVE_STATE == ACTIVE_HIGH
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,LOW );

	#else
		/* Error Message */
	#endif
}

void LED_VoidTOGGLE(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	#if   LED_ACTIVE_STATE == ACTIVE_LOW
		static u8 u8PinState = HIGH;
		u8PinState = ~ u8PinState;
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,u8PinState);

	#elif LED_ACTIVE_STATE == ACTIVE_HIGH
		static u8 u8PinState = LOW;
		u8PinState = ~ u8PinState;
		GPIO_SetPinVal(Copy_u8Port,Copy_u8Pin,u8PinState);

	#else
		/* Error Message */
	#endif
}

