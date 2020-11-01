#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_inteface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	/* Send Bit by bit stating from Most signficant bit (MSb) */
	s8 Local_u8Counter;
	u8 Local_u8Bit;
	for (Local_u8Counter = 7; Local_u8Counter >=0 ; Local_u8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_u8Counter);
		MGPIO_VoidSetPinValue(STP_SERIAL_DATA,Local_u8Bit);

		/* send pulse to shift clock */
		MGPIO_VoidSetPinValue(STP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(STP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);


		/* send pulse to storage clock */
		MGPIO_VoidSetPinValue(STP_STORAGE_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(STP_STORAGE_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);
	}
}