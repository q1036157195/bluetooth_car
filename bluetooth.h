#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__
 
void bluetooth_UartInit();
void bluetooth_move_take(unsigned char key);
void bluetooth_uart_pass();
extern volatile unsigned char key;
extern volatile unsigned int pattern;
extern volatile unsigned int launch;
#endif
