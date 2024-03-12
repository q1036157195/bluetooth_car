#include <REGX52.H>
#include "move.h"
#include "timer_PWM.h"
#include "bluetooth.h"
volatile unsigned char key='d';		//������������
volatile unsigned int pattern = 0;   //ģʽѡ��
volatile unsigned int launch = 0;	//����ֹͣ�Ϳ�ʼ
void bluetooth_UartInit()		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;		//���ö�ʱ��ʼֵ
	TH1 = 0xFD;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
    ES=1;
    EA=1;
}
void bluetooth_move_take(unsigned char key)
{
    switch(key)
    {
        case 'a':if(pattern == 1){move_go();} break;        //ǰ��
        case 'b':if(pattern == 1){move_back();} break;      //����    
        case 'c':if(pattern == 1){move_left();}break;       //��ת    
        case 'd':if(pattern == 1){move_stop(); }break;      //ֹͣ
        case 'e':if(pattern == 1){move_right(); }break;     //��ת
		
        case 'f':speed_left = 50;speed_right = 50;break;  //�ٶ�1
        case 'g':speed_left = 100;speed_right = 100;break;//�ٶ�2  
		
		case 'h':move_stop();pattern = 1; break;			//��������ģʽ
		case 'i':launch = 0;move_stop();pattern = 2; break;		//����������ģʽ	
		
		case 'j':if(pattern == 2){launch = 1;move_stop();}break;						//��ʼ����
		case 'k':if(pattern == 2){launch = 0;move_stop();} break;						//ֹͣ����
		case 'l': move_stop();pattern = 3; break;                            //ѭ��ģʽ
    }
}
void bluetooth_uart_pass() interrupt 4
{
    
    if(RI==1)
    {
        key = SBUF;
        if(key <= 5)
        {
            move_stop();
        }
		
        bluetooth_move_take(key);
        
            
            
        RI = 0;
    }
    
}
