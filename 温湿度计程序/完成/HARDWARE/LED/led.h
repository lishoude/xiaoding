#ifndef __LED_H
#define __LED_H	 
#include "sys.h"




#define LED  PBout(1)// PB1


#define KEY1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)
#define KEY2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define KEY3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)

#define KEY1_PRES	 1		//KEY1 
#define KEY2_PRES	 2		//KEY2 
#define KEY3_PRES	 3		//KEY3 


uint8_t  KEY_SCAN(void);



#define LED_OFF                  			GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define LED_ON                 				GPIO_ResetBits(GPIOB,GPIO_Pin_1)

void LED_Init(void);
void LED_Flash_fast(void);  //LED快闪一次
void LED_Flash_low(void);  //LED慢闪一次











void LED_Init(void);//初始化		 				
#endif
