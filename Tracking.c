#include <REGX52.H>
#include "motor.h"
#include "timer_PWM.h"
#include "Delay.h"
#include "Tracking.h"
#include "move.h"

sbit OUT1 = P2^7;//����
sbit OUT2 = P2^6;//��΢��
sbit OUT4 = P2^5;//�Ҵ��
sbit OUT3 = P2^4;//��΢��


sbit IN1 = P1^0;//����
sbit IN2 = P1^1;//����
sbit IN3 = P1^2;//����
sbit IN4 = P1^3;//����


void Chack()
{
	if(OUT1 == 1 && OUT2 == 1 && OUT3 == 1 && OUT4 == 1)//ȫ���ߣ�����У�ͣ��
	{
		speed_left = 0;
		speed_right = 0;
		move_stop();
	}

	if(OUT1 == 0 && OUT2 == 0 && OUT3 == 1 && OUT4 == 0)//ƫ������
	{
		speed_left=30;
		speed_right =40;
		move_go();
	}

	if(OUT1 == 0 && OUT2 == 1 && OUT3 == 0 && OUT4 == 0)//ƫ�ң�����
	{
	   speed_left =40;
		speed_right =30;
		move_go();
	}

	if(OUT1 == 1 && OUT2 == 1 && OUT3 == 0 && OUT4 == 0)//���ת
	{
		move_stop();
		Delay(20);
	    speed_left = 50;
		speed_right= 30;
		Delay(20);
		move_go();
		
		while(1)
		{
				IN1 = 0;
				IN2 = 1;
				if(OUT3 == 1) 
			{
				IN1 = 1;
				IN2 = 0;
				break;
			}
				speed_left = 40;
				speed_right = 40;
				move_go();
				
		}
	}
	if(OUT1 == 0 && OUT2 == 0 && OUT3 == 0 && OUT4 == 1)//�Ҵ�ת
	{
		move_stop();
		Delay(20);
		speed_left = 30;
		speed_right = 50;
		Delay(20);
		move_go();
		
	while(1)
		{
			IN3 = 0;
			IN4 = 1;
				if(OUT2 == 1) 
			{
				IN3 = 1;
				IN4 = 0;
			break;
			}
				speed_left = 40;
				speed_right = 40;
				move_go();
				
		}
	}

	if(OUT1 == 1 && OUT2 == 0 && OUT3 == 0 && OUT4 == 1)
	{
		speed_left = 40;
		speed_right = 40;
		move_go();
	}
}
