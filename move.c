#include <REGX52.H>
#include "motor.h"
#include "move.h"
void move_go()                      //ǰ��
{
    car_left_motor_forward();      //������ǰ
    car_right_motor_forward();     //�ҵ����ǰ
}
 
 
void move_back()                      //ǰ��
{
    car_left_motor_back();      //�������
    car_right_motor_back();     //�ҵ�����
}
 
 
 
void move_left()                      //��ת
{
    car_left_motor_stop();          //����ֹͣ
    car_right_motor_forward();     //�ҵ����ǰ
}
 
 
void move_right()                      //��ת
{
    car_left_motor_forward();      //������ǰ
    car_right_motor_stop();     //�ҵ��ֹͣ
}
void move_stop()
{
    car_right_motor_stop();     //�ҵ��ֹͣ
    car_left_motor_stop();          //����ֹͣ
}
void move_back_left()                      //��ת
{
    car_left_motor_stop();          //����ֹͣ
    car_right_motor_back();     //�ҵ����ǰ
}

 
void move_back_right()                      //��ת
{
    car_left_motor_back();      //������ǰ
    car_right_motor_stop();     //�ҵ��ֹͣ
}
