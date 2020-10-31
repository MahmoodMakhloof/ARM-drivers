/******************************************************************/
/* Author      : Mahmoud Makhlouf                                 */
/* Date        : 15 Aug 2020                                      */
/* Version     : V02                                              */
/* Description : Speed up GPIO driver and add Lock_pin function   */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

void GPIO_SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	if (Copy_u8Pin <=7) /* CONTROL LOW */
	{
		switch (Copy_u8Port)
		{
			case GPIOA:
				GPIOA_CRL &= ~(0b1111      << Copy_u8Pin * 4); /* RST PIN */
				GPIOA_CRL |=  (Copy_u8Mode << Copy_u8Pin * 4);
				break;
			case GPIOB:
				GPIOB_CRL &= ~(0b1111      << Copy_u8Pin * 4); /* RST PIN */
				GPIOB_CRL |=  (Copy_u8Mode << Copy_u8Pin * 4);
				break;
			case GPIOC:
				GPIOC_CRL &= ~(0b1111      << Copy_u8Pin * 4); /* RST PIN */
				GPIOC_CRL |=  (Copy_u8Mode << Copy_u8Pin * 4);
				break;
			default   :
				break;
		}
	}

	else if (Copy_u8Pin <=15) /* CONTROL HIGH */
	{
		switch (Copy_u8Port)
		{
			case GPIOA:
				GPIOA_CRH &= ~(0b1111      << (Copy_u8Pin-8) * 4); /* RST PIN */
				GPIOA_CRH |=  (Copy_u8Mode << (Copy_u8Pin-8) * 4);
				break;
			case GPIOB:
				GPIOB_CRH &= ~(0b1111      << (Copy_u8Pin-8) * 4); /* RST PIN */
				GPIOB_CRH |=  (Copy_u8Mode << (Copy_u8Pin-8) * 4);
				break;
			case GPIOC:
				GPIOC_CRH &= ~(0b1111      << (Copy_u8Pin-8) * 4); /* RST PIN */
				GPIOC_CRH |=  (Copy_u8Mode << (Copy_u8Pin-8) * 4);
				break;
			default   :
				break;
		}
	}

	else
	{
		/* Error Message */
	}
}



void GPIO_SetPin_Val (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if      (Copy_u8Val == HIGH)
				GPIOA_BSRR = 1 << Copy_u8Pin;
			else if (Copy_u8Val == LOW )
				GPIOA_BRR  = 1 << Copy_u8Pin;
			else
			{
				/* Error Message */	
			}
			break;

		case GPIOB:
			if      (Copy_u8Val == HIGH)
				GPIOB_BSRR = 1 << Copy_u8Pin;
			else if (Copy_u8Val == LOW )
				GPIOB_BRR  = 1 << Copy_u8Pin;
			else
			{
				/* Error Message */
			}
		    break;
		case GPIOC:
			if      (Copy_u8Val == HIGH)
				GPIOC_BSRR = 1 << Copy_u8Pin;
			else if (Copy_u8Val == LOW )
				GPIOC_BRR  = 1 << Copy_u8Pin;
			else
			{
				/* Error Message */
			}
		    break;

		default   :
			break;
	}
}

u8 GPIO_GetPin_Val (u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 ResultPin = 0;
	switch(Copy_u8Port)
	{
		case GPIOA:
			ResultPin = GET_BIT(GPIOA_IDR,Copy_u8Pin);
		    break;	

		case GPIOB:
			ResultPin = GET_BIT(GPIOB_IDR,Copy_u8Pin);
		    break;
		case GPIOC:
			ResultPin = GET_BIT(GPIOC_IDR,Copy_u8Pin);
		    break;

		default   :
			break;
	}

	return ResultPin;
}


void GPIO_SetPort (u8 Copy_u8Port,u16 Copy_u16Val)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			GPIOA_ODR = Copy_u16Val;
			break;
		case GPIOB:
			GPIOB_ODR = Copy_u16Val;
		    break;
		case GPIOC:
			GPIOC_ODR = Copy_u16Val;
		    break;
		default   :
			break;
	}

}

void GPIO_SetHalfPort (u8 Copy_u8HalfPort,u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		case PORTA_FIRST_HALF:
			GPIOA_ODR &= 0xFF00;
			GPIOA_ODR |= (Copy_u8Val << 0);
			break;
		case PORTA_SECOND_HALF:
			GPIOA_ODR &= 0x00FF;
			GPIOA_ODR |= (Copy_u8Val << 8);
		    break;
		case PORTB_FIRST_HALF:
			GPIOB_ODR &= 0xFF00;
			GPIOB_ODR |= (Copy_u8Val << 0);
		    break;
		case PORTB_SECOND_HALF:
			GPIOB_ODR &= 0x00FF;
			GPIOB_ODR |= (Copy_u8Val << 8);
		    break;
		default   :
			break;
	}

}

void GPIO_LockPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			SET_BIT(GPIOA_LCKR,Copy_u8Pin);
			break;
		case GPIOB:
			SET_BIT(GPIOB_LCKR,Copy_u8Pin);
		    break;
		case GPIOC:
			SET_BIT(GPIOC_LCKR,Copy_u8Pin);
		    break;
		default   :
			break;
	}
}