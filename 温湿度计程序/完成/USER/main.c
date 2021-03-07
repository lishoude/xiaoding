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


u8 t; //������־λ
int a=0;//��Ļ��־λ
int temp;//�¶�
u16 humi;//ʪ��

 int main(void)
 {	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();//================================��ʱ��ʼ��
	IIC_Init();//==================================IIC��ʼ��
	SHT30_Init();//================================��ʪ�ȼƳ�ʼ��
	OLED_Init();//=================================oled��ʼ��
	USART1_init();//===============================��ʼ������1
	USART2_init();//===============================��ʼ������2
	LED_Init();//==================================ָʾ�ư�����ʼ��	
	wifi_protocol_init();//========================��ʼ��Ϳѻģ��
	OLED_ColorTurn(0);//===========================0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//=========================0������ʾ 1 ��Ļ��ת��ʾ

	while(1)
	{
		wifi_uart_service();  //SDK����
		wifi_uart_service();  //SDK����
		t = KEY_SCAN();
		switch(t)//ɨ�谴��
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
		
		//����״̬
		switch(mcu_get_wifi_work_state())
    {
			case SMART_CONFIG_STATE: 
					 LED_Flash_fast(); //���� Smart ����״̬���� LED ����
					 break;
			case AP_STATE:  
					 LED_Flash_low();//���� AP ����״̬���� LED ����
					 break;
			case WIFI_NOT_CONNECTED:
					 LED_OFF;//Wi-Fi ������ɣ���������·�������� LED ����
					 break;
			case WIFI_CONNECTED:
					 LED_ON;//·�������ӳɹ����� LED ����
					 break;
			default:break;
    }
		
	  SHT30_Read_Humiture(&temp,&humi);	
		
		OLED_Refresh();
if(a==0)//�¶���ʾ
	{
		OLED_ShowChinese(0,2,0,16,1);
		OLED_ShowChinese(18,2,1,16,1);
		OLED_ShowString(37,3,":",16,1);  
		OLED_ShowNum(55,4,temp,2,24,1);
		OLED_ShowString(82,10,"(",16,1); 
		OLED_ShowChinese(92,10,1,16,1);
    OLED_ShowString(109,10,")",16,1); 
}
if(a==1)//ʪ����ʾ
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
		mcu_dp_value_update(DPID_HUMIDITY_VALUE,humi);  //��������ϱ�ʪ��
		mcu_dp_value_update(DPID_TEMP_CURRENT,temp*10); //��������ϱ��¶�
 }

}
 
