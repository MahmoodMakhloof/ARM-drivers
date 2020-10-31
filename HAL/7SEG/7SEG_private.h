/******************************************************************/
/* Name    : Mahmoud Makhlouf                                     */
/* Date    : 16 Aug 2020                                          */
/* Version : V01                                                  */
/******************************************************************/

#ifndef 7SEG_PRIVATE_H
#define 7SEG_PRIVATE_H

#if   defined(COMMON_CATHODE)
	u8 NUMBERS[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

#elif defined(COMMON_ANODE)
	u8 NUMBERS[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};

#else
	/* Error Message */

#endif




#endif /* 7SEG_PRIVATE_H */