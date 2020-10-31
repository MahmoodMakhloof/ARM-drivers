/******************************************************************/
/* Author      : Mahmoud Makhlouf                                 */
/* Date        : 15 Aug 2020                                      */
/* Version     : V02                                              */
/* Description : Speed up GPIO driver and add Lock_pin function   */
/******************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2


#define LOW   0
#define HIGH  1


/* Modes */
/* For input */
#define ANALOG_INPUT             0b0000
#define FLOATING_INPUT           0b0100
#define PULL_UP_PULL_DOWN_INPUT  0b1000


/* For output */
/* For 10MHZ  */
#define GP_10MHZ_OUTPUT_PP       0b0001
#define GP_10MHZ_OUTPUT_OD       0b0101
#define AF_10MHZ_OUTPUT_PP       0b1001
#define AF_10MHZ_OUTPUT_OD       0b1101

/* For 2MHZ  */
#define GP_2MHZ_OUTPUT_PP        0b0010
#define GP_2MHZ_OUTPUT_OD        0b0110
#define AF_2MHZ_OUTPUT_PP        0b1010
#define AF_2MHZ_OUTPUT_OD        0b1110

/* For 50MHZ  */
#define GP_50MHZ_OUTPUT_PP       0b0011
#define GP_50MHZ_OUTPUT_OD       0b0111
#define AF_50MHZ_OUTPUT_PP       0b1011
#define AF_50MHZ_OUTPUT_OD       0b1111


/* Pins */
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3 
#define PIN4  4
#define PIN5  5 
#define PIN6  6 
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13 
#define PIN14 14
#define PIN15 15


#define PORTA_FIRST_HALF  0
#define PORTA_SECOND_HALF 1
#define PORTB_FIRST_HALF  2
#define PORTB_SECOND_HALF 3


void GPIO_SetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);
void GPIO_SetPin_Val (u8 Copy_u8Port ,u8 Copy_u8Pin , u8 CopyVal);
u8 GPIO_GetPin_Val (u8 Copy_u8Port,u8 Copy_u8Pin);
void GPIO_SetPort (u8 Copy_u8Port,u32 Copy_u32Val);
void GPIO_SetHalfPort (u8 Copy_u8HalfPort,u8 Copy_u8Val);

#endif /* GPIO_INTERFACE_H */