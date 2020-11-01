/**************************************************/
/* Author  : Mahmoud Makhlouf  					  */
/* Date    : 12 Aug 2020  						  */
/* Version : v01                                  */
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_ON(u8 port,u8 pin)
{
   switch(port)
   {
	   case GPIOA : MGPIO_VidSetPinValue(GPIOA,pin,GPIO_HIGH); break;
	   
	   case GPIOB : MGPIO_VidSetPinValue(GPIOB,pin,GPIO_HIGH); break;
	   
	   case GPIOC : MGPIO_VidSetPinValue(GPIOC,pin,GPIO_HIGH); break;
	   
   }	   
}
void LED_OFF(u8 port,u8 pin)
{
	switch(port)
   {
	   case GPIOA : MGPIO_VidSetPinValue(GPIOA,pin,GPIO_LOW); break;
	   
	   case GPIOB : MGPIO_VidSetPinValue(GPIOB,pin,GPIO_LOW); break;
	   
	   case GPIOC : MGPIO_VidSetPinValue(GPIOC,pin,GPIO_LOW); break;
	   
   }	   
}
void LED_TOG(u8 port,u8 pin)
{
	switch(port)
   {
	   case GPIOA : MGPIO_VidSetPinValue(GPIOA,pin); break;
	   
	   case GPIOB : MGPIO_VidSetPinValue(GPIOB,pin); break;
	   
	   case GPIOC : MGPIO_VidSetPinValue(GPIOC,pin); break;
	   
   }	   
}