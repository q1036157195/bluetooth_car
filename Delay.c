#include <intrins.h>
#include <REGX52.H>
#include "Delay.h"
 
void Delay(unsigned int a)		//@11.0592MHz
{
	unsigned char i, j;
	while(a--)
	{
			_nop_();
			i = 2;
			j = 199;
			do
			{
				while (--j);
			} while (--i);
	}	
}

void Delay10us()		//@11.0592MHz
{
	unsigned char i;
	i = 2;
	while (--i);
}

