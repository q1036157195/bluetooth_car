#include <REGX52.H>
#include "move.h"
#include "timer_PWM.h"
#include "bluetooth.h"
volatile unsigned char key='d';		//接受蓝牙数据
volatile unsigned int pattern = 0;   //模式选择
volatile unsigned int launch = 0;	//跟随停止和开始
void bluetooth_UartInit()		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;		//设置定时初始值
	TH1 = 0xFD;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时
    ES=1;
    EA=1;
}
void bluetooth_move_take(unsigned char key)
{
    switch(key)
    {
        case 'a':if(pattern == 1){move_go();} break;        //前进
        case 'b':if(pattern == 1){move_back();} break;      //后退    
        case 'c':if(pattern == 1){move_left();}break;       //左转    
        case 'd':if(pattern == 1){move_stop(); }break;      //停止
        case 'e':if(pattern == 1){move_right(); }break;     //右转
		
        case 'f':speed_left = 50;speed_right = 50;break;  //速度1
        case 'g':speed_left = 100;speed_right = 100;break;//速度2  
		
		case 'h':move_stop();pattern = 1; break;			//蓝牙避障模式
		case 'i':launch = 0;move_stop();pattern = 2; break;		//超声波跟随模式	
		
		case 'j':if(pattern == 2){launch = 1;move_stop();}break;						//开始跟随
		case 'k':if(pattern == 2){launch = 0;move_stop();} break;						//停止跟随
		case 'l': move_stop();pattern = 3; break;                            //循迹模式
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
