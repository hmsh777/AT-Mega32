/*
 * WIFI.h
 *
 * Created: 3/5/2020 9:26:04 PM
 *  Author: pasos
 */ 


#ifndef WIFI_H_
#define WIFI_H_
#define  F_CPU  8000000
#include "Std_types.h"
#include "Utils.h"
#include "Memmap32.h"
#include <avr/delay.h>


void NumberToString(u32 num,u8 *str);
void WIFI_Init(void);
void WIFI_sendNumber(u64 num);
void WIFI_sendString(u8* str);


#endif /* WIFI_H_ */