/***************************************************/
/*  Name    : Mahmoud Makhlouf                     */
/*  Date    : 29 Aug 2020                          */
/*  Version : v01                                  */
/***************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_VoidInit(void);
void MEXTI_VoidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);
void MEXTI_VoidEnableEXTI(u8 Copy_u8EXTILine);
void MEXTI_VoidDisableEXTI(u8 Copy_u8EXTILine);
void MEXTI_VoidSoftwareTrigger(u8 Copy_u8EXTILine);
void MEXTI_VoidSetCallBack(void (*prt) (void));


#define EXTI_LINE_0   0
#define EXTI_LINE_1   1
#define EXTI_LINE_2   2
#define EXTI_LINE_3   3
#define EXTI_LINE_4   4
#define EXTI_LINE_5   5
#define EXTI_LINE_6   6
#define EXTI_LINE_7   7
#define EXTI_LINE_8   8
#define EXTI_LINE_9   9
#define EXTI_LINE_10  10
#define EXTI_LINE_11  11
#define EXTI_LINE_12  12
#define EXTI_LINE_13  13
#define EXTI_LINE_14  14
#define EXTI_LINE_15  15


#define RISING_EDGE   0
#define FALLING_EDGE  1
#define ON_CHANGE     2


#endif /* EXTI_INTERFACE_H */