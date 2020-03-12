/*
 * 7segment.h
 *
 *  Created on: Nov 28, 2019
 *      Author: pasos
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "Std_types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "DIO_Lcfg.h"
#include "Memmap32.h"


#define segment_port PA

void SEGMENT_Display(u8 num);


#endif /* 7SEGMENT_H_ */
