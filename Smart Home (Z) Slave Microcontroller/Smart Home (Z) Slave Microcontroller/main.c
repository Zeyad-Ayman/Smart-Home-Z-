/*
* Smart Home (Z) Slave.c
*
* Created: 27/10/2020 21:54:58 م
* Author : Zeyad Ayman
*/

#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include "DIO.h"
#include "ADC.h"
#include "SSegments.h"

int main(void)
{
	LCD_Init();
	SPI_Init('S');
	ADC_Init();
	SSEG_Init();
	
	DDRC |= (1<<5) | (1<<6) | (1<<7);    
	DDRB |= (1<<0) | (1<<1);
	
	TCCR0 |=(1<<WGM00)|(1<<CS00)|(1<<CS01)|(1<<COM01);    //phase correct mode, non-inverting, N=64
	
	unsigned char motorFlag=0, slaveRequest, count=0;
	unsigned short tempValue;
	
	while (1)
	{
		slaveRequest = SPI_Receive();
		
		switch(slaveRequest)
		{
			case 'A':
			PORTC |= (1<<5);
			break;
			
			case 'a':
			PORTC &=~ (1<<5);
			break;
			
			case 'B':
			PORTC |= (1<<6);
			break;
			
			case 'b':
			PORTC &=~ (1<<6);
			break;
			
			case 'C':
			PORTC |= (1<<7);
			break;
			
			case 'c':
			PORTC &=~ (1<<7);
			break;
			
			case 'T':
			while(slaveRequest == 'T')
			{
	             tempValue = ADC_Read(3);
	             tempValue /= 4;
	             SSEG_display(tempValue);
			}
			break;
			
			case 't':
			while(slaveRequest == 't')
			{
				SSEG_Init();
			}
			break;
			
			case 'F':
			OCR0 = 0;
			PORTB |= (1<<1);
			PORTB &=~ (1<<0);
			LCD_Clear();
			LCD_Gotoxy(1,1);
			LCD_DisplayString(" Speed 0%");
			motorFlag = 1;
			count = 0;
			break;
			
			case 'f':
			OCR0 = 0;
			PORTB &=~ (1<<0);
			PORTB &=~ (1<<1);
			motorFlag = 0;
			count = 0;
			break;
			
			//-----------------------------
			
			case '+':
			if(motorFlag == 0)
			{
				LCD_Clear();
				LCD_Gotoxy(1,1);
				LCD_DisplayString(" Turn ON AC Fan!");
			}
			else
			{
				count++;
				switch(count)
				{
					case 1:
					OCR0 = 63;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed 25%");
					break;
					
					case 2:
					OCR0 = 127;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed 50%");
					break;
					
					case 3:
					OCR0 = 191;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed 75%");
					break;
					
					case 4:
					OCR0 = 255;
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Speed 100%");
					break;
				}
				if (count>4)
				{
					count=4;
				}
				break;
			
			//-----------------------------------
			
			case '-':
			if(motorFlag == 0)
			{
					LCD_Clear();
					LCD_Gotoxy(1,1);
					LCD_DisplayString(" Turn ON AC Fan!");
			}
			else
			{
					count--;
					switch(count)
					{
						case 0:
						OCR0 = 0;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed 0%");
						break;
						
						case 1:
						OCR0 = 63;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed 25%");
						break;
						
						case 2:
						OCR0 = 127;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed 50%");
						break;
						
						case 3:
						OCR0 = 191;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed 75%");
						break;
						
						case 4:
						OCR0 = 255;
						LCD_Clear();
						LCD_Gotoxy(1,1);
						LCD_DisplayString(" Speed 100%");
						break;
					}
				if (count<0)
				{
					count=0;
				}
				break;
			}
		}
	}
}
}
