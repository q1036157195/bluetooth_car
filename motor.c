#include <REGX52.H>
 #include "move.h"
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
 
 
void car_left_motor_forward()  //������ǰ
{
    IN3=0;
    IN4=1;
}
void car_left_motor_back()  //�������
{
    IN3=1;
    IN4=0;
}
void car_right_motor_forward()  //�ҵ����ǰ
{
    IN1=1;
    IN2=0;
}
void car_right_motor_back()  //�ҵ�����
{
    IN1=0;
    IN2=1;
}
void car_right_motor_stop()  //�ҵ��ֹͣ
{
    IN1=1;
    IN2=1;
}
 
void car_left_motor_stop()  //����ֹͣ
{
    IN4=1;
    IN3=1;
}
