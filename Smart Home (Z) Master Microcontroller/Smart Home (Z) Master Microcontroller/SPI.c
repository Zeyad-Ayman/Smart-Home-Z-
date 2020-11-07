/*
 * SPI.c
 *
 * Created: 28/10/2020
 *  Author: Zeyad Ayman
 */ 

#include "SPI.h"

void SPI_Init(unsigned char status)
{
	switch(status)
	{
		case 'M':
		SPI_DDR |= (1<<MOSI) | (1<<SCK) | (1<<SS);	
		SPI_DDR &=~ (1<<MISO);
		SPCR |= (1<<MSTR) | (1<<SPE);
		SLAVE_DISEN();
		break;
		
		case 'S':
		SPI_DDR &=~ (1<<MOSI) | (1<<SCK) | (1<<SS);
		SPI_DDR |= (1<<MISO);
		SPCR |= (1<<SPE);
		break;
	}
	
}
unsigned char SPI_TxRx(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));   //waiting for reading data
	return SPDR;	
}