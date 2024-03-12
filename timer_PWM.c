#include <REGX52.H>
#include "timer_PWM.h"
sbit ENL1 = P1^4;
sbit ENL2 = P1^5;
sbit ENR1 = P1^7;
sbit ENR2 = P1^6;
volatile int count = 0;
volatile int speed_left = 0;
volatile int speed_right = 0;
void Timer0Init(void)		//定时器0初始化，100微秒@11.0592MHz
{
			
		
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xAE;		//设置定时初始值
	TH0 = 0xFB;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
    ET0=1;
    EA=1;
}
void time() interrupt 1
{
    
    TL0 = 0xAE;		//设置定时初始值
	TH0 = 0xFB;		//设置定时初始值
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
