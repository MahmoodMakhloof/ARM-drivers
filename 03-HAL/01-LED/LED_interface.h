/**************************************************/
/* Author  : Mahmoud Makhlouf  					  */
/* Date    : 12 Aug 2020  						  */
/* Version : v01                                  */
/**************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "GPIO_interface.h"

void LED_ON(u8 port,u8 pin);
void LED_OFF(u8 port,u8 pin);
void LED_TOG(u8 port,u8 pin);


#endif