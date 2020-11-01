/**************************************************************************************/
/*  Author    : OsamaMahmoud                                                          */
/*  Date      : 14/8/2020                                                             */
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_private.h"



void Display(u8 Port,u8 Num)
{
	DIO_voidSetPort(Port,data[Num]);
}