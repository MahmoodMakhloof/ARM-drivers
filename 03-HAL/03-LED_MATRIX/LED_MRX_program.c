/***************************************************/
/*  Name    : Mahmoud Makhlouf                     */
/*  Date    : 31 Aug 2020                          */
/*  Version : v01                                  */
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_MRX_interface.h"
#include "LED_MRX_config.h"
#include "LED_MRX_private.h"

static u8 Local_u8count=25;

static void DisableAllCols(void)
{

	/*Diable all columns */
	GPIO_voidEnablePin(LED_MRX_COL0_PIN);
	GPIO_voidEnablePin(LED_MRX_COL1_PIN);
	GPIO_voidEnablePin(LED_MRX_COL2_PIN);
	GPIO_voidEnablePin(LED_MRX_COL3_PIN);
	GPIO_voidEnablePin(LED_MRX_COL4_PIN);

}
static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	
	Local_u8BIT=GET_BIT(Copy_u8Value,0);
	GPIO_voidSetPinVal(LED_MRX_ROW0_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Value,1);
	GPIO_voidSetPinVal(LED_MRX_ROW1_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Value,2);
	GPIO_voidSetPinVal(LED_MRX_ROW2_PIN,Local_u8BIT);
	
		Local_u8BIT=GET_BIT(Copy_u8Value,3);
	GPIO_voidSetPinVal(LED_MRX_ROW3_PIN,Local_u8BIT);
	
		Local_u8BIT=GET_BIT(Copy_u8Value,4);
	GPIO_voidSetPinVal(LED_MRX_ROW4_PIN,Local_u8BIT);
	
		Local_u8BIT=GET_BIT(Copy_u8Value,5);
	GPIO_voidSetPinVal(LED_MRX_ROW5_PIN,Local_u8BIT);
	
		Local_u8BIT=GET_BIT(Copy_u8Value,6);
	GPIO_voidSetPinVal(LED_MRX_ROW6_PIN,Local_u8BIT);
	
		Local_u8BIT=GET_BIT(Copy_u8Value,7);
	GPIO_voidSetPinVal(LED_MRX_ROW7_PIN,Local_u8BIT);
}

void LED_MRX_voidInit(void)
{
	GPIO_voidSetPinDirection(LED_MRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);

	GPIO_voidSetPinDirection(LED_MRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(LED_MRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);

}
void LED_MRX_voidDisplay(u8 *Copy_u8Data)
{
	Local_u8count=25;
	while(Local_u8count--)
	{
		/*Diable all columns */
		DisableAllCols();
		/*Enable column 0 */
		SetRowValues(Copy_u8Data[0]);
		GPIO_voidSetPinVal(LEDMRX_COL0_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms
		
		/* columns 1*/
		DisableAllCols();
		SetRowValues(Copy_u8Data[1]);
		GPIO_voidSetPinVal(LEDMRX_COL1_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms
			/* columns 2*/
		DisableAllCols();
		SetRowValues(Copy_u8Data[2]);
		GPIO_voidSetPinVal(LEDMRX_COL2_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms
			/* columns 3*/
		DisableAllCols();
		SetRowValues(Copy_u8Data[3]);
		GPIO_voidSetPinVal(LEDMRX_COL3_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms
			/* columns 4*/
		DisableAllCols();
		SetRowValues(Copy_u8Data[4]);
		GPIO_voidSetPinVal(LEDMRX_COL4_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms
			/* columns 5*/
		DisableAllCols();
		SetRowValues(Copy_u8Data[5]);
		GPIO_voidSetPinVal(LEDMRX_COL5_PIN,LOW);
		STK_voidSetBusyWait(2500);//2.5ms

	}	
}

