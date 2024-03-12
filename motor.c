#include <REGX52.H>
 #include "move.h"
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit IN3 = P1^2;
sbit IN4 = P1^3;
 
 
void car_left_motor_forward()  //左电机向前
{
    IN3=0;
    IN4=1;
}
void car_left_motor_back()  //左电机向后
{
    IN3=1;
    IN4=0;
}
void car_right_motor_forward()  //右电机向前
{
    IN1=1;
    IN2=0;
}
void car_right_motor_back()  //右电机向后
{
    IN1=0;
    IN2=1;
}
void car_right_motor_stop()  //右电机停止
{
    IN1=1;
    IN2=1;
}
 
void car_left_motor_stop()  //左电机停止
{
    IN4=1;
    IN3=1;
}
