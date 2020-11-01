/*********************************************/
/* Author : Mahmoud                          */
/* Date   : 23 oct 2020                      */
/* Ver    : v01                              */
/*********************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channel;

typedef struct 
{
	/* for all channels */
	volatile u32 ISR;
	volatile u32 IFCR;
	/* 7 channel , both of them contain 5 registers */
	DMA_Channel Channel [7];

}DMA_t;

#define DMA     ((volatile DMA_t *)0x40020000)

#endif /* DMA_PRIVATE_H */