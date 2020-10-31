/*******************************************************************/
/* Author  : Mahmoud Makhlouf                                      */
/* Date    : 15 Aug 2020                                           */
/* Version : V01                                                   */
/*******************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)      VAR |=  (1 << BIT)
#define CLR_BIT(VAR,BIT)      VAR &= ~(1 << BIT)
#define TOG_BIT(VAR,BIT)      VAR ^=  (1 << BIT)
#define GET_BIT(VAR,BIT)    ( VAR     >>    BIT) & 1
#define SET_PRT(VAR,VAL)      VAR  =        VAL

#endif /* BIT_MATH_H */