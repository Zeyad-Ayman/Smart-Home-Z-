/*
 * SSegments.h
 *
 * Created: 25/10/2020 22:25:48م
 *  Author: Zeyad Ayman
 */ 


#ifndef SSEGMENTS_H_
#define SSEGMENTS_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void SSEG_display(float dist);
void SSEG_Init();

#endif 