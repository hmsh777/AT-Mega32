/*
 * ultrasonic.h
 *
 * Created: 2/4/2020 5:20:53 PM
 *  Author: pasos
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#define F_CPU 8000000
#include "DIO_Interface.h"
#include "Timers.h"
#include <util/delay.h>




typedef enum{
	ULTRASONIC_1=PIN8,
	ULTRASONIC_2=PIN9,
	ULTRASONIC_3=PIN28,
	ULTRASONIC_4=PIN29
	}ULTRASONIC_type;
	
	
void ULTRASONIC_Init(void);
u8 ULTRASONIC_GetDistance(ULTRASONIC_type ultrasonic_pin);



#endif /* ULTRASONIC_H_ */