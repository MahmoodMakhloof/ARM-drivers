/***************************************************/
/*  Name    : Mahmoud Makhlouf                     */
/*  Date    : 2 NOV 2020                           */
/*  Version : v01                                  */
/***************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_type;

#define     AFIO    ((AFIO_type*)0x40010000)


#endif /* AFIO_PRIVATE_H */
