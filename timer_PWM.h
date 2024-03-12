#ifndef __TIMER_PWM_H__
#define __TIMER_PWM_H__
 extern volatile int count;
 extern volatile int speed_left;		//创建全局变量
 extern volatile int speed_right;
 
 
void Timer0Init(void);		//定时器0初始化，100微秒@11.0592MHz
void time(); 
 
#endif
