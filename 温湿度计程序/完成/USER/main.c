#include "sys.h"
#include "usart_init.h"
#include "wifi.h"
#include "stm32f10x.h"
#include "delay.h"
#include "wifi.h"	
#include <string.h>
#include "led.h"
#include "oled.h"
#include "bmp.h"
#include "myiic.h"
#include "sht30.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


u8 t; //按键标志位
int a=0;//屏幕标志位
int temp;//温度
u16 humi;//湿度

 int main(void)
 {	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();//================================延时初始化
	IIC_Init();//==================================IIC初始化
	SHT30_Init();//================================温湿度计初始化
	OLED_Init();//=================================oled初始化
	USART1_init();//===============================初始化串口1
	USART2_init();//===============================初始化串口2
	LED_Init();//==================================指示灯按键初始化	
	wifi_protocol_init();//========================初始化涂鸦模块
	OLED_ColorTurn(0);//===========================0正常显示，1 反色显示
  OLED_DisplayTurn(0);//=========================0正常显示 1 屏幕翻转显示

	while(1)
	{
		wifi_uart_service();  //SDK函数
		wifi_uart_service();  //SDK函数
		t = KEY_SCAN();
		switch(t)//扫描按键
		{				 
			case KEY1_PRES:
					 mcu_set_wifi_mode(SMART_CONFIG);
					 break;
			case KEY2_PRES:
					 LED_Flash_fast();a=!a;	OLED_Refresh();OLED_Clear();OLED_Refresh();					
					 break;
			case KEY3_PRES:				
					 LED_Flash_low();a=!a;OLED_Refresh();OLED_Clear();OLED_Refresh();		
					 break;
			default:
			     break;	
		} 
		
		//配网状态
		switch(mcu_get_wifi_work_state())
    {
			case SMART_CONFIG_STATE: 
					 LED_Flash_fast(); //处于 Smart 配置状态，即 LED 快闪
					 break;
			case AP_STATE:  
					 LED_Flash_low();//处于 AP 配置状态，即 LED 慢闪
					 break;
			case WIFI_NOT_CONNECTED:
					 LED_OFF;//Wi-Fi 配置完成，正在连接路由器，即 LED 常暗
					 break;
			case WIFI_CONNECTED:
					 LED_ON;//路由器连接成功，即 LED 常亮
					 break;
			default:break;
    }
		
	  SHT30_Read_Humiture(&temp,&humi);	
		
		OLED_Refresh();
if(a==0)//温度显示
	{
		OLED_ShowChinese(0,2,0,16,1);
		OLED_ShowChinese(18,2,1,16,1);
		OLED_ShowString(37,3,":",16,1);  
		OLED_ShowNum(55,4,temp,2,24,1);
		OLED_ShowString(82,10,"(",16,1); 
		OLED_ShowChinese(92,10,1,16,1);
    OLED_ShowString(109,10,")",16,1); 
}
if(a==1)//湿度显示
{
		OLED_ShowChinese(0,2,2,16,1);
		OLED_ShowChinese(18,2,1,16,1);
		OLED_ShowString(37,3,":",16,1);  
		OLED_ShowNum(55,4,humi,2,24,1);
		OLED_ShowString(82,10,"(",16,1); 
		OLED_ShowString(92,10,"%",16,1); 
    OLED_ShowString(102,10,")",16,1); 

}
		OLED_Refresh();
		mcu_dp_value_update(DPID_HUMIDITY_VALUE,humi);  //向服务器上报湿度
		mcu_dp_value_update(DPID_TEMP_CURRENT,temp*10); //向服务器上报温度
 }

}
 
