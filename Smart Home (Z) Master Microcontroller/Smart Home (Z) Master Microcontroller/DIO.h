/*
* DIO.h
*
* Created: 27/10/2020
*  Author: Zeyad Ayman
*/


#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Math_Bit.h"
#include "DIO_HW.h"
#include "DIO_Types.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelNo,STD_Level Level);
STD_Level DIO_ReadChannel(DIO_ChannelTypes ChannelNo);

#endif /* DIO_H_ */