/***************************************************/
/*  Name    : Mahmoud Makhlouf                     */
/*  Date    : 29 Aug 2020                          */
/*  Version : v01                                  */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MEXTI_VoidInit(void)
{
	#if   EXTI_LINE == EXTI_LINE_0
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_1
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_2
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_3
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_4
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_5
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_6
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_7
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_8
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_9
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_10
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_11
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_12
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_13
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_14
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#elif EXTI_LINE == EXTI_LINE_15
		SET_BIT(EXTI -> IMR , EXTI_LINE);
	#else
		#error ("Wrong External interrupt line")
	#endif


	#if EXTI_SENSE_MODE == RISING_EDGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif EXTI_SENSE_MODE == FALLING_EDGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif EXTI_SENSE_MODE == ON_CHANGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#else
		#error ("Wrong Sense Mode")
	#endif

}
void MEXTI_VoidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)
{
	switch (Copy_u8EXTISenseMode)
	{
		case RISING_EDGE : SET_BIT(EXTI -> RTSR , EXTI_LINE);
						   break;
		case FALLING_EDGE: SET_BIT(EXTI -> FTSR , EXTI_LINE);
		                   break;
		case ON_CHANGE   : SET_BIT(EXTI -> FTSR , EXTI_LINE);
						   SET_BIT(EXTI -> RTSR , EXTI_LINE); 
						   break;
		default          : break;

		SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
	}
}

void MEXTI_VoidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}

void MEXTI_VoidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine);
}

void MEXTI_VoidSoftwareTrigger(u8 Copy_u8EXTILine)
{

}

void MEXTI_VoidSetCallBack(void (*prt) (void))
{
	EXTI_CallBack[0] = ptr;
}

void EXTI0_IRQHandler (void)
{
	EXTI0_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 0);
}

