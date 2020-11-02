/***************************************************/
/*  Name    : Mahmoud Makhlouf                     */
/*  Date    : 29 Aug 2020                          */
/*  Version : v01                                  */
/***************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H
typedef struct 
{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_TYPE;


#define EXTI  ((volatile EXTI_TYPE *) 0x40010400)

#define NULL		(void*) 0




#endif /* EXTI_PRIVATE_H */
