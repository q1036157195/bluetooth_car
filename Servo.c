#include <REGX52.H>
#include "Delay.h"
#include "Servo.h"
sbit servoPin = P3^2;

// 微秒延迟函数，需要根据单片机的时钟频率来调整
void delay_us(unsigned int us) {
    while (us--) {
        // 这里的循环次数需要根据单片机的时钟频率来计算
        // 例如，如果单片机的时钟频率是12MHz，那么可能需要循环数千次来达到1微秒
    }
}

// 毫秒延迟函数
void delay_ms(unsigned int ms) {
    while (ms--) {
        delay_us(1000); // 假设delay_us函数能准确延迟1微秒
    }
}

// 设置伺服电机角度
unsigned int pulseWidth;
void setServoAngle(unsigned char angle) {
    
    
    // 根据角度计算脉冲宽度（这里使用的是常见的1.5ms到2.5ms范围）
    if (angle <= 90) {
        pulseWidth = 1500 + (2500 - 1500) * angle / 90; // 1.5ms到2ms
    } else {
        pulseWidth = 2500 - (2500 - 1500) * (angle - 90) / 90; // 2ms到1.5ms
    }
    
    // 产生PWM脉冲
    servoPin = 1; // 开始高电平
    delay_us(pulseWidth / 2); // 延迟到脉冲中间点
    servoPin = 0; // 切换到低电平
    delay_us(pulseWidth / 2); // 完成脉冲
    
    // 给伺服电机一些响应时间
    delay_ms(10);
}

unsigned char angle;
void servo() {
	
    while (1) {
		
        // 电机从0度到180度
        for (angle = 0; angle <= 180; angle += 1) {
			
            setServoAngle(angle);
        }
        
        // 电机从180度到0度
        for (angle = 180; angle >= 0; angle -= 1) {
            setServoAngle(angle);
        }
    }
}
