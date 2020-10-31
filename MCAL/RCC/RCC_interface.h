/*******************************************************************/
/* Author  : Mahmoud Makhlouf                                      */
/* Date    : 15 Aug 2020                                           */
/* Version : V01                                                   */
/*******************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2

void RCC_VoidInitSysClock (void);
void RCC_VoidEnableClock (u8 CopyBusId ,u8 CopyPerId);
void RCC_VoidDisableClock (u8 CopyBusId , u8 CopyPerId);




#endif /* RCC_INTERFACE_H */