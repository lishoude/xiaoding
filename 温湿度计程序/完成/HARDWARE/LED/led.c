#include "led.h"

void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB,PE端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //LED0-->PB.1 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
	GPIO_SetBits(GPIOB,GPIO_Pin_1);						 //PB.1 输出高

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA4,
}
 



void LED_Flash_fast(void)  //LED快闪一次
{	
			LED_ON;
			delay_ms(250);
			LED_OFF;
			delay_ms(250);
}

void LED_Flash_low(void)  //LED慢闪一次
{
			LED_ON;
			delay_ms(1500);
			LED_OFF;
			delay_ms(1500);
}




uint8_t  KEY_SCAN(void)
{
	if(KEY1==0||KEY2==0||KEY3==0)
	{
		delay_ms(10);
		
		if(KEY1==0)
		{
			while(KEY1==0) ;  return KEY1_PRES;
		}
  	else if (KEY2==0)
		{
			while(KEY2==0) ; return KEY2_PRES;
		}
		else if(KEY3==0)
		{
			while(KEY3==0) ; return KEY3_PRES;
		}
	}
	else if (KEY1==0&&KEY2==0&&KEY3==0)
		return 0;
  return 0;
}
















