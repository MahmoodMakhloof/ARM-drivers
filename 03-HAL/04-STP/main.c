#include "STD_TYPES.h"
#include 





void main (void)
{
	/* Clock init */
	RCC_voidInitSYsCLock();
	RCC_voidEnableClock(RCC_APB2,2);

	/* pin Direction */
	MGPIO_vidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_vidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_vidSetPinDirection(GPIOA,2,0b0010);

	/* timer init */
	STK_voidInit();

	/* HSTP_voidSendSynchronus(0b10101010); */
 
	u8 i =0;

	while(1)
	{
		for(i=0;i<8;i++)
		{
			STP_voidSendSynchronus(1<<i);
			STK_voidSetBusyWait(300000);
		}

	}
}