/*
 * WDT.h
 *
 *  Created on: Nov 28, 2019
 *      Author: pasos
 */

#ifndef WDT_H_
#define WDT_H_

#include "Std_types.h"
#include "Utils.h"
#include "Memmap32.h"



typedef enum{
	timeout_16ms,
	timeout_32ms,
	timeout_65ms,
	timeout_130ms,
	timeout_260ms,
	timeout_520ms,
	timeout_1000ms,
	timeout_2100ms,
}TimeOut_t;



extern void WDT_Off(void);
extern void WDT_Set(TimeOut_t timeout);

#endif /* WDT_H_ */
