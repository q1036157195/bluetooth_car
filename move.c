#include <REGX52.H>
#include "motor.h"
#include "move.h"
void move_go()                      //前进
{
    car_left_motor_forward();      //左电机向前
    car_right_motor_forward();     //右电机向前
}
 
 
void move_back()                      //前退
{
    car_left_motor_back();      //左电机向后
    car_right_motor_back();     //右电机向后
}
 
 
 
void move_left()                      //左转
{
    car_left_motor_stop();          //左电机停止
    car_right_motor_forward();     //右电机向前
}
 
 
void move_right()                      //右转
{
    car_left_motor_forward();      //左电机向前
    car_right_motor_stop();     //右电机停止
}
void move_stop()
{
    car_right_motor_stop();     //右电机停止
    car_left_motor_stop();          //左电机停止
}
void move_back_left()                      //左转
{
    car_left_motor_stop();          //左电机停止
    car_right_motor_back();     //右电机向前
}

 
void move_back_right()                      //右转
{
    car_left_motor_back();      //左电机向前
    car_right_motor_stop();     //右电机停止
}
