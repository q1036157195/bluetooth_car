#include <REGX52.H>
#include "Delay.h"
#include "Servo.h"
sbit servoPin = P3^2;

// ΢���ӳٺ�������Ҫ���ݵ�Ƭ����ʱ��Ƶ��������
void delay_us(unsigned int us) {
    while (us--) {
        // �����ѭ��������Ҫ���ݵ�Ƭ����ʱ��Ƶ��������
        // ���磬�����Ƭ����ʱ��Ƶ����12MHz����ô������Ҫѭ����ǧ�����ﵽ1΢��
    }
}

// �����ӳٺ���
void delay_ms(unsigned int ms) {
    while (ms--) {
        delay_us(1000); // ����delay_us������׼ȷ�ӳ�1΢��
    }
}

// �����ŷ�����Ƕ�
unsigned int pulseWidth;
void setServoAngle(unsigned char angle) {
    
    
    // ���ݽǶȼ��������ȣ�����ʹ�õ��ǳ�����1.5ms��2.5ms��Χ��
    if (angle <= 90) {
        pulseWidth = 1500 + (2500 - 1500) * angle / 90; // 1.5ms��2ms
    } else {
        pulseWidth = 2500 - (2500 - 1500) * (angle - 90) / 90; // 2ms��1.5ms
    }
    
    // ����PWM����
    servoPin = 1; // ��ʼ�ߵ�ƽ
    delay_us(pulseWidth / 2); // �ӳٵ������м��
    servoPin = 0; // �л����͵�ƽ
    delay_us(pulseWidth / 2); // �������
    
    // ���ŷ����һЩ��Ӧʱ��
    delay_ms(10);
}

unsigned char angle;
void servo() {
	
    while (1) {
		
        // �����0�ȵ�180��
        for (angle = 0; angle <= 180; angle += 1) {
			
            setServoAngle(angle);
        }
        
        // �����180�ȵ�0��
        for (angle = 180; angle >= 0; angle -= 1) {
            setServoAngle(angle);
        }
    }
}
