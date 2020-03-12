/*
 * Sensors.h
 *
 *  Created on: Dec 1, 2019
 *      Author: pasos
 */

#ifndef SENSORS_H_
#define SENSORS_H_





#include "DIO_Interface.h"
#include "ADC.h"


#define LM35_ch   CH_0
#define PIEZO_ch  CH_1
#define MPX_ch    CH_2
#define PROXI_PIN PIN3


u16 LM35_temp(void);
u8 PIEZO_force(void);

u16 MPX_Pressure(void);

Voltage_Level_type PROXI_Read(void);
void Fan_init(void);
u16 Fan_Speed(void);

#endif /* SENSORS_H_ */
