#include <REGX52.H>
#include <INTRINS.H>
#include "UT.h"
sbit Trig = P2^1;
sbit Echo = P2^0;
void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j;
 
	i = 90;
	j = 163;
	do
	{
		while (--j);
	} while (--i);
}
 
void Delay15us()		//@11.0592MHz
{
	unsigned char i;
 
	i = 4;
	while (--i);
}
 
 
void Timer2_Init(void)        
{
    T2MOD = 0;    //初始化模式寄存器
    T2CON = 0;    //初始化控制寄存器
    TL2 = 0x00;    //设置定时初值
    TH2 = 0x00;    //设置定时初值
    TR2 = 0;        //定时器2关闭计时
}
int judge(float cm , float number)
{
	float n = cm - number;
	if(n <= 3 && n >= -3)     
	{
		return 1;          //停止   
	}else if(n < -3)
	{
		return 2;			//后退   
	}else if(n > 3)
	{
		return 3;			//前进    
	}
	return 1;
}
void Delay25ms()		//@11.0592MHz
{
	unsigned char i, j;
 
	i = 45;
	j = 208;
	do
	{
		while (--j);
	} while (--i);
}
 
int UT_work()
{
	
	float number = 8;
	float s = 0;
	float cm = 0;
	int n = 0;
	Trig = 0;
	Echo = 0;
	
	
	Trig = 1;
	Delay15us();
	Trig = 0;		
	while(!Echo);	
	
	TR2 = 1;	
	while(Echo);
	TR2 = 0;			//关闭计时器
	s = (float)((TH2 * 256 + TL2) * 0.000001);
	cm = s * 340 / 2 * 100;		
	n =judge(cm , number);		
	cm = 0;
	s = 0;		
	TH2 = 0x00;
	TL2 = 0x00;			//清除定时器数值
	Delay25ms();
	return n;
 
	
		
		
	
	
}
 
//
