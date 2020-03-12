/*
 * EXT_Interrupt.h
 *
 *  Created on: Dec 6, 2019
 *      Author: pasos
 */

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "Memmap32.h"
#include "Std_types.h"
#include "Utils.h"


typedef enum {
	INT0,
	INT1,
	INT2,
	INT3,
	INT4,
	INT5,
	INT6,
	INT7
}InterruptPin_type;
typedef enum {
	Low_level=0,
	Logical_chang=1,
	Falling_edge=2,
	Rising_edge=3
}Interrupt_Trigger_Mode_type;
void External_Interrupt_Init(InterruptPin_type ,Interrupt_Trigger_Mode_type );



#endif /* EXT_INTERRUPT_H_ */
