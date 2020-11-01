




int main(void)
{
	/****** initialization ******/
	
	/* RCC_initialization */
	/* Enable GPIO RCC_PORTA */

	/* GPIO Initialization diriction */

	SOS_voidCreateTask (0 , 1000 , LED0);
	SOS_voidCreateTask (1 , 2000 , LED1);
	SOS_voidCreateTask (2 , 3000 , LED2);

	OS_void_start();

	while (1)
	{

	}
	return 0;
}

void LED0 (void)
{
	static u8 Local_u8Pin0 =0;
	TOG_BIT(Local_u8Pin0,0);

	MGPIO_VoidSetPinValue(GPIOA , PIN0 , Local_u8Pin0);
}

void LED1 (void)
{
	static u8 Local_u8Pin1 =0;
	TOG_BIT(Local_u8Pin1,0);

	MGPIO_VoidSetPinValue(GPIOA , PIN1 , Local_u8Pin1);
}

void LED2 (void)
{
	static u8 Local_u8Pin2 =0;
	TOG_BIT(Local_u8Pin2,0);

	MGPIO_VoidSetPinValue(GPIOA , PIN2, Local_u8Pin2);
}