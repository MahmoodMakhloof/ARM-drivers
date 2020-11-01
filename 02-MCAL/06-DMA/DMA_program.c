/*********************************************/
/* Author : Mahmoud                          */
/* Date   : 23 oct 2020                      */
/* Ver    : v01                              */
/*********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"\

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"


void DMA_voidChannelInit(void)
{

	/*
	   1- memory to memory 
	   2- priority is very high 
	   3- source size and destination size  = 32 bit 
	   4- MINC , PINC activated 
	   5- no circuilar 'no repeat'
	   6- direction : 
	   7- transfer interrupt enable
	*/

	#if CHANNEL_ID == 1 
	DMA -> Cahnnel[0].CCR = 
	#endif
}


void DMA_voidChannelStart (u32 * Copy_Pu32SourceAdress , u32 * Copy_Pu32DestinationAdress , u16 Copy_u16ClockLength )
{
	/* make sure that channel is disabled */
	CLR_BIT(DMA -> Channel[0].CCR , 0);

	/* write the address */
	DMA -> Channel[0].CPAR = Copy_Pu32SourceAdress;
	DMA -> Channel[0].CMAR = Copy_Pu32DestinationAdress;

	/* Block length */
	DMA -> Channel[0].CNDTR = Copy_u16ClockLength;

	/* enable chanel */
	SET_BIT(DMA -> Channel[0].CCR , 0);


}
