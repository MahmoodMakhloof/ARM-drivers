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

 void (* EXTI0_CallBack )  (void)  = NULL;
 void (* EXTI1_CallBack )  (void)  = NULL;
 void (* EXTI2_CallBack )  (void)  = NULL;
 void (* EXTI3_CallBack )  (void)  = NULL;
 void (* EXTI4_CallBack )  (void)  = NULL;
 void (* EXTI5_CallBack )  (void)  = NULL;
 void (* EXTI6_CallBack )  (void)  = NULL;
 void (* EXTI7_CallBack )  (void)  = NULL;
 void (* EXTI8_CallBack )  (void)  = NULL;
 void (* EXTI9_CallBack )  (void)  = NULL;
 void (* EXTI10_CallBack)  (void)  = NULL;
 void (* EXTI11_CallBack)  (void)  = NULL;
 void (* EXTI12_CallBack)  (void)  = NULL;
 void (* EXTI13_CallBack)  (void)  = NULL;
 void (* EXTI14_CallBack)  (void)  = NULL;
 void (* EXTI15_CallBack)  (void)  = NULL;

void MEXTI_VoidInit(void)
{
	/* initial configirations */
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
	SET_BIT(EXTI-> SWIER , Copy_u8EXTILine);
}

/***************   MEXTI Set callback function    *******************/
void MEXTI0_VoidSetCallBack(void (*ptr) (void))
{
	EXTI0_CallBack  = ptr;
}

void MEXTI1_VoidSetCallBack(void (*ptr) (void))
{
	EXTI1_CallBack  = ptr;
}

void MEXTI2_VoidSetCallBack(void (*ptr) (void))
{
	EXTI2_CallBack  = ptr;
}

void MEXTI3_VoidSetCallBack(void (*ptr) (void))
{
	EXTI3_CallBack  = ptr;
}

void MEXTI4_VoidSetCallBack(void (*ptr) (void))
{
	EXTI4_CallBack  = ptr;
}

void MEXTI5_VoidSetCallBack(void (*ptr) (void))
{
	EXTI5_CallBack  = ptr;
}

void MEXTI6_VoidSetCallBack(void (*ptr) (void))
{
	EXTI6_CallBack  = ptr;
}

void MEXTI7_VoidSetCallBack(void (*ptr) (void))
{
	EXTI7_CallBack  = ptr;
}

void MEXTI8_VoidSetCallBack(void (*ptr) (void))
{
	EXTI8_CallBack  = ptr;
}

void MEXTI9_VoidSetCallBack(void (*ptr) (void))
{
	EXTI9_CallBack  = ptr;
}

void MEXTI10_VoidSetCallBack(void (*ptr) (void))
{
	EXTI10_CallBack  = ptr;
}

void MEXTI11_VoidSetCallBack(void (*ptr) (void))
{
	EXTI11_CallBack  = ptr;
}

void MEXTI12_VoidSetCallBack(void (*ptr) (void))
{
	EXTI12_CallBack  = ptr;
}

void MEXTI13_VoidSetCallBack(void (*ptr) (void))
{
	EXTI13_CallBack  = ptr;
}

void MEXTI14_VoidSetCallBack(void (*ptr) (void))
{
	EXTI14_CallBack  = ptr;
}

void MEXTI15_VoidSetCallBack(void (*ptr) (void))
{
	EXTI15_CallBack  = ptr;
}



/*************   ISR For 16 EXTI lines  **************/
void EXTI0_IRQHandler (void)
{
	EXTI0_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 0);
}

void EXTI1_IRQHandler (void)
{
	EXTI1_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 1);
}

void EXTI2_IRQHandler (void)
{
	EXTI2_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 2);
}

void EXTI3_IRQHandler (void)
{
	EXTI3_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 3);
}

void EXTI4_IRQHandler (void)
{
	EXTI4_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 4);
}

void EXTI5_IRQHandler (void)
{
	EXTI5_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 5);
}

void EXTI6_IRQHandler (void)
{
	EXTI6_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 6);
}

void EXTI7_IRQHandler (void)
{
	EXTI7_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 7);
}

void EXTI8_IRQHandler (void)
{
	EXTI8_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 8);
}

void EXTI9_IRQHandler (void)
{
	EXTI9_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 9);
}

void EXTI10_IRQHandler (void)
{
	EXTI10_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 10);
}

void EXTI11_IRQHandler (void)
{
	EXTI11_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 11);
}

void EXTI12_IRQHandler (void)
{
	EXTI12_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 12);
}

void EXTI13_IRQHandler (void)
{
	EXTI13_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 13);
}

void EXTI14_IRQHandler (void)
{
	EXTI14_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 14);
}

void EXTI15_IRQHandler (void)
{
	EXTI15_CallBack();
	/* clear pending bit */
	SET_BIT(EXTI-> PR , 15);
}
