/*********************************************/
/* Author : Mahmoud                          */
/* Date   : 23 oct 2020                      */
/* Ver    : v01                              */
/*********************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void DMA_voidChannelInit(void);
void DMA_voidChannelStart(u32 * Copy_Pu32SourceAdress , u32 * Copy_Pu32DestinationAdress , u16 Copy_u16ClockLength );

#endif /* DMA_INTERFACE_H