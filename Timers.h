/*
 * Timers.h
 *
 *  Created on: Dec 2, 2019
 *      Author: pasos
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "Std_types.h"
#include "Utils.h"

#include "Memmap32.h"


typedef enum{
	timer_stop=0,
	timer_scale_1,
	timer_scale_8=2,
	timer_scale_64,
	timer_scale_256,
	timer_scale_1024,
	external_falling,
	external_rising
}prescaler0_type;

typedef enum
{
	Normal_mode=0,
	Phasecorrect_mode,
	CTC_mode,
	FastPWM_mode

}mode0_type;
typedef enum
{
	disconnected=0,
	Toggle,
	Nin_inverting,
	Inverting

}OC0_mode_type;



void Timer0_Init( mode0_type mode,prescaler0_type scaler ,OC0_mode_type oc_mode);
void Timer0_OVInterrupt_Enable(void);
void Timer0_OVInterrupt_Disable(void);
void Timer0_OCInterrupt_Enable(void);
void Timer0_OCInterrupt_Disable(void);
/*********************************************************************************************************/

typedef enum{
	timer1_stop=0,
	timer1_scale_1,
	timer1_scale_8=2,
	timer1_scale_64,
	timer1_scale_256,
	timer1_scale_1024,
	timer1_external_falling,
	timer1_external_rising
}prescaler1_type;

typedef enum
{
	Timer1_Normal_mode=0,
	Timer1_Phasecorrect_mode,
	Timer1_CTC_mode,
	Timer1_FastPWM_ICR_TOP_mode,
	Timer1_FastPWM_OCRA_TOP_mode

}mode1_type;

typedef enum
{
	OCRA_disconnected=0,
	OCRA_Toggle,
	OCRA_Nin_inverting,
	OCRA_Inverting

}OC1A_mode_type;

typedef enum
{
	OCRB_disconnected=0,
	OCRB_Toggle,
	OCRB_Nin_inverting,
	OCRB_Inverting

}OC1B_mode_type;


typedef enum{
	Rising,
	Falling
}Edge_type;




void Timer1_InputCaptureEdge(Edge_type edge);
void Timer1_Init( mode1_type mode,prescaler1_type scaler,OC1A_mode_type oc1a_mode,OC1B_mode_type oc1b_mode);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OV_InterruptEnable(void);
void Timer1_OV_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);



#endif /* TIMERS_H_ */
