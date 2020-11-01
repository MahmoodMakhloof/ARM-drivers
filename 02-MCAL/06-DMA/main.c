#include 
#include
#include



int main (void)
{
	u32 Arr1[1000]= {0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];

	RCC_VoidsystemclockInit();
	RCC_voidEnablePeripheralClock(RCC_AHB , 1);

	DMA_voidChannelInit();

	NVIC_voidInterruptEnable (11);

	DMA_voidChannelStart(Arr1,Arr2,1000);

	for(u16 i = 0 ;i<1000;i++)
	{
		Arr4[i]= Arr3[i];
	}


	while (1)
	{

	}
	return 0;


}

void DMA1_Channel1_IRQHandler(void)
{
	/* don't forget to clear flags */
	/* clear GIF */
	DMA-> IFCR = 1<<0;
	/* clear TC */
	DMA ->IFCR = 1<<1;
}