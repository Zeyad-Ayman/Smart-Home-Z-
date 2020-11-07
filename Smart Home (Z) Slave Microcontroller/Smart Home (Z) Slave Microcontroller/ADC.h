/*
 * ADC.h
 *
 * Created: 23/10/2020 23:15:30 م
 *  Author: Zeyad Ayman
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_Init();
unsigned short ADC_Read(unsigned char Channel);



#endif /* ADC_H_ */