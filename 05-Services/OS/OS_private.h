
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct 
{
	u16 priodicity     ;
	void (*Fptr) (void);
}Task;

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u16Priodicity , void(*ptr) (void));
void SOS_voidStart(void);

#endif
