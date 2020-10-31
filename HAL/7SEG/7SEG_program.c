/******************************************************************/
/* Name    : Mahmoud Makhlouf                                     */
/* Date    : 16 Aug 2020                                          */
/* Version : V01                                                  */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "7SEG_private.h"
#include "7SEG_interface.h"
#include "7SEG_config.h"


void _7SEG_Display (u8 Copy_u8HalfPort , u8 Copy_u8Val)
{
	GPIO_SetHalfPort(Copy_u8HalfPort , Numbers[Copy_u8Val]);
}