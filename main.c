#include <REGX52.H>
#include "motor.h"
#include "move.h"
#include "Delay.h"
#include "timer_PWM.h"
#include "bluetooth.h"
#include "UT.h"
#include "Servo.h"

sbit PIR1 = P0^0;
sbit PIR2 = P0^1;
sbit PIR3 = P0^2;
sbit PIR4 = P0^3;
void PIR_work()                 //∫ÏÕ‚±‹’œƒ£øÈ
{
    if(PIR1 == 0 || PIR2 == 0)
        {
            move_stop();
            move_back();
            Delay(150);
            move_stop();
           
            
        }
        if(PIR3 == 0 || PIR4 == 0)
        {
            move_stop();
            move_go();
            Delay(150);
            move_stop();
            
        }
}
void PIR_turn()			//∫ÏÕ‚π’Õ‰
{
	if(PIR1 == 0 && PIR2 == 1)  //”“π’
	{
		move_left();
		
		
	}
	if(PIR1 == 1 && PIR2 == 0)  //◊Ûπ’
	{
		move_right();		
	}
	
	
}
 
void main()
{
    int n = 0;
	Timer0Init();
    bluetooth_UartInit();
	Timer2_Init();
    speed_left=50;
    speed_right=50;
	 
    while(1)
    {
        if(pattern == 1)
		{
			PIR_work();
			PIR_turn();
		}
		if(pattern == 2)
		{
			 servo();
			
			if(launch==1)
			{	
				
				PIR_turn();
				n = UT_work();
					
				switch(n)
				{
					case 1:move_stop();break;
					case 2:move_back();break;
					case 3:move_go();break;
				}
			}
		}
		if(pattern==3)
		{
		void Chack();
		}
 
               
    }
}
