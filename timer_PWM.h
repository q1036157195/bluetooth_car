#ifndef __TIMER_PWM_H__
#define __TIMER_PWM_H__
 extern volatile int count;
 extern volatile int speed_left;		//����ȫ�ֱ���
 extern volatile int speed_right;
 
 
void Timer0Init(void);		//��ʱ��0��ʼ����100΢��@11.0592MHz
void time(); 
 
#endif
