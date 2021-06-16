#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "button.h"

//ALIENTEK ̽����STM32F407������ ʵ��3
//��������ʵ��-�⺯���汾 
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾    
//���ߣ�����ԭ�� @ALIENTEK 


Button_t Button1;
Button_t Button2;
Button_t Button3;
Button_t Button4;


void Btn1_Dowm_CallBack(void *btn)
{
  PRINT_INFO("%s Dowm\r\n",((Button_t*)btn)->Name);
}

void Btn1_Double_CallBack(void *btn)
{
	PRINT_INFO("%s Double\r\n",((Button_t*)btn)->Name);
}

void Btn1_Long_CallBack(void *btn)
{
	PRINT_INFO("%s Long\r\n",((Button_t*)btn)->Name);
	
	Button_Delete(btn);
  PRINT_INFO("%s Delete\r\n",((Button_t*)btn)->Name);
  Search_Button();
}

void Btn1_Long_Free_CallBack(void *btn)
{
  PRINT_INFO("%s Long free\r\n",((Button_t*)btn)->Name);
}

uint8_t Read_Button1_Level(void)
{
  return KEY0;
}

uint8_t Read_Button2_Level(void)
{
  return KEY1;
}

uint8_t Read_Button3_Level(void)
{
  return KEY2;
}

uint8_t Read_Button4_Level(void)
{
  return WK_UP;
}



int main(void)
{ 
	delay_init(168);  //��ʼ����ʱ����
	LED_Init();				//��ʼ��LED�˿� 
	BEEP_Init();      //��ʼ���������˿�
	KEY_Init();       //��ʼ���밴�����ӵ�Ӳ���ӿ�
	uart_init(9600);
	
	LED0=0;				  	//�ȵ������
	
	Button_Create("Button1",				
                &Button1, 				
                Read_Button1_Level, 	//callback
                Bit_RESET);		     		//level
	
	Button_Attach(&Button1,BUTTON_DOWM,Btn1_Dowm_CallBack);		
  Button_Attach(&Button1,BUTTON_DOUBLE,Btn1_Double_CallBack);	
  Button_Attach(&Button1,BUTTON_LONG,Btn1_Long_CallBack);		
	Button_Attach(&Button1,BUTTON_LONG_FREE,Btn1_Long_Free_CallBack);		
	
	Button_Create("Button2",				
                &Button2, 				
                Read_Button2_Level, 	//callback
                Bit_RESET);		     		//level
	
	Button_Attach(&Button2,BUTTON_DOWM,Btn1_Dowm_CallBack);		
  Button_Attach(&Button2,BUTTON_DOUBLE,Btn1_Double_CallBack);	
  Button_Attach(&Button2,BUTTON_LONG,Btn1_Long_CallBack);		
	Button_Attach(&Button2,BUTTON_LONG_FREE,Btn1_Long_Free_CallBack);	
	
	Button_Create("Button3",				
                &Button3, 				
                Read_Button3_Level, 	//callback
                Bit_RESET);		     		//level
	
	Button_Attach(&Button3,BUTTON_DOWM,Btn1_Dowm_CallBack);		
  Button_Attach(&Button3,BUTTON_DOUBLE,Btn1_Double_CallBack);	
  Button_Attach(&Button3,BUTTON_LONG,Btn1_Long_CallBack);		
	Button_Attach(&Button3,BUTTON_LONG_FREE,Btn1_Long_Free_CallBack);	
	
	
	Button_Create("Button4",				
                &Button4, 				
                Read_Button4_Level, 	//callback
                Bit_SET);		     		//level
	
	Button_Attach(&Button4,BUTTON_DOWM,Btn1_Dowm_CallBack);		
  Button_Attach(&Button4,BUTTON_DOUBLE,Btn1_Double_CallBack);	
  Button_Attach(&Button4,BUTTON_LONG,Btn1_Long_CallBack);		
	Button_Attach(&Button4,BUTTON_LONG_FREE,Btn1_Long_Free_CallBack);	
	
	
	LED0=1;		
	
	while(1)
	{
		LED1 = !LED1;
		Button_Process(); 
		delay_ms(20); 
	}
}


