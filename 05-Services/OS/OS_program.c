
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* eclipse error NULL and it is the definition of NULL */
#define  NULL   (void *) 0

/* array of tasks - array of structure */
/* static keyword because this file only used this data and all static put in private */
static Task OS_Tasks [NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity , void(*ptr) (void)) //ID = priority
{
	OS_Tasks[Copy_u8ID].priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8ID].Fptr       = ptr               ;
}

void SOS_voidStart(void)
{
	/* initialization */
	MSTK_VoidInit();

	/* Tick => 1msec */
	/* HSE 8MHZ/8  = 1000 micro sec = 1 mill sec */
	MSTK_VoidSetIntervalPeriodic( 1000 , Scheduler )

}

/* tick count variable */
volatile u16 TickCounts =0;

/* Scheduler orderring tasks */
static void Scheduler (void)
{
	for (u8 i =0 ; i<NUMBER_OF_TASKS ;i++)
	{
		if ((TickCounts % OS_Tasks[i].priodicity)== 0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCounts++;
}

/* Scheduler orderring tasks */
static void Scheduler (void)
{
	for (u8 i =0 ; i<NUMBER_OF_TASKS ;i++)
	{
		if ((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].State == TASK_READY ))
		{
			if (OS_Tasks[i].firstDelay == 0)
			{
				OS_Tasks[i].firstDelay = OS_Tasks[i].priodicity-1;
				OS_Tasks[i].Fptr9();
			}

			else
			{
				OS_Tasks[i].firstDelay--;
			}
		}
	}
	TickCounts++;
}