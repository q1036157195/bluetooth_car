#include <REGX52.H>
#include "timer_PWM.h"
sbit ENL1 = P1^4;
sbit ENL2 = P1^5;
sbit ENR1 = P1^7;
sbit ENR2 = P1^6;
volatile int count = 0;
volatile int speed_left = 0;
volatile int speed_right = 0;
void Timer0Init(void)		//��ʱ��0��ʼ����100΢��@11.0592MHz
{
			
		
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0xAE;		//���ö�ʱ��ʼֵ
	TH0 = 0xFB;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
    ET0=1;
    EA=1;
}
void time() interrupt 1
{
    
    TL0 = 0xAE;		//���ö�ʱ��ʼֵ
	TH0 = 0xFB;		//���ö�ʱ��ʼֵ
    count++;
    count%=100;
    if(count>=speed_left)
    {
        ENL1 = 0;
        ENL2 = 0;
    }
    else
    {
        ENL1 = 1;
        ENL2 = 1;
    }
    if(count>=speed_right)
    {
        ENR1 = 0;
        ENR2 = 0;
    }
    else
    {
        ENR1 = 1;
        ENR2 = 1;
    }
    
}
