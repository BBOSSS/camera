#ifndef __LED_H
#define __LED_H
#include "sys.h"




//LED�˿ڶ���
#define LED0 PBout(0)	// DS0

#define LED_ON   GPIO_ResetBits(GPIOB,GPIO_Pin_0)
#define LED_OFF  GPIO_SetBits(GPIOB,GPIO_Pin_0)
 

void LED_Init(void);//��ʼ��		 				    
#endif
