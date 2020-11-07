/*
* Smart Home (Z) Master.c
*
* Created: 28/10/2020   18:36:34 م
*  Author: Zeyad Ayman
*/

#include <avr/io.h>
#include "UART.h"
#include "SPI.h"
#include "LCD.h"


int main(void)
{
	LCD_Init();
	SPI_Init('M');
	SLAVE_EN();
	Uart_Init();
	
	LCD_Gotoxy(1,1);
	LCD_DisplayString("AMIT-Learning ");
	LCD_Gotoxy(1,2);
	LCD_DisplayString("Smart Home (Z)");
	
	while (1)
	{
		switch(Uart_Receive())
		{
			case 'A':
			SPI_TxRx('A');
			LCD_Command(CLEAR);
			LCD_Gotoxy(2,1);
			LCD_DisplayString(" ROOM A IS ON");
			break;
			
			case 'a':
			SPI_TxRx('a');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM A IS OFF");
			break;
			
			case 'B':
			SPI_TxRx('B');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM B IS ON");
			break;
			
			case 'b':
			SPI_TxRx('b');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM B IS OFF");
			break;
			
			case 'C':
			SPI_TxRx('C');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM C IS ON");
			break;
			
			case 'c':
			SPI_TxRx('c');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" ROOM C IS OFF");
			break;
			
			case 'T':
			SPI_TxRx('T');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" AC Temp. Set ");
			break;
			
			case 't':
			SPI_TxRx('t');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" AC Sys. OFF ");
			break;
	
			case 'F':
			SPI_TxRx('F');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" AC Fan is ON ");
			break;
			
			case 'f':
			SPI_TxRx('f');
			LCD_Gotoxy(2,1);
			LCD_Command(CLEAR);
			LCD_DisplayString(" AC Fan is OFF ");
			break;
			
			case '+':
			SPI_TxRx('+');
			break;
			
			case '-':
			SPI_TxRx('-');
			break;
		}
	}
}

