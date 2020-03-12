#include "Timers.h"


void Timer0_Init( mode0_type mode,prescaler0_type scaler,OC0_mode_type oc_mode)
{
	switch (mode)
				{
					case Normal_mode:
						CLEAR_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);

					break;
					case Phasecorrect_mode:
						SET_BIT(TCCR0,WGM00);
						CLEAR_BIT(TCCR0,WGM01);
					break;
					case CTC_mode:
						CLEAR_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);

					break;
					case FastPWM_mode:
						SET_BIT(TCCR0,WGM00);
						SET_BIT(TCCR0,WGM01);
					break;
				}

	switch (oc_mode)
				{
					case disconnected:
						CLEAR_BIT(TCCR0,COM00);
						CLEAR_BIT(TCCR0,COM01);
						break;
					case Toggle:
						SET_BIT(TCCR0,COM00);
						CLEAR_BIT(TCCR0,COM01);
						break;
					case Nin_inverting:
						CLEAR_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;
					case Inverting:
						SET_BIT(TCCR0,COM00);
						SET_BIT(TCCR0,COM01);
						break;
					}
	TCCR0&=0XF8;
	TCCR0|=scaler;

}
void Timer0_OVInterrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_OVInterrupt_Disable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}
void Timer0_OCInterrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_OCInterrupt_Disable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}
/*************************************************************************************************************/


void Timer1_Init( mode1_type mode,prescaler1_type scaler,OC1A_mode_type oc1a_mode,OC1B_mode_type oc1b_mode)
{
	switch (mode)
				{
					case Timer1_Normal_mode:
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						CLEAR_BIT(TCCR1B,WGM12);
						CLEAR_BIT(TCCR1B,WGM13);
						break;
					
					case Timer1_FastPWM_ICR_TOP_mode:
						CLEAR_BIT(TCCR1A,WGM10);
						SET_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1B,WGM12);
						SET_BIT(TCCR1B,WGM13);
						break;
						
				    case Timer1_FastPWM_OCRA_TOP_mode:
						SET_BIT(TCCR1A,WGM10);
						SET_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1B,WGM12);
						SET_BIT(TCCR1B,WGM13);
						break;
				}
	switch (oc1a_mode)
				{
					case OCRA_disconnected:
						CLEAR_BIT(TCCR1A,COM1A0);
						CLEAR_BIT(TCCR1A,COM1A1);
						break;
					case OCRA_Toggle:
						SET_BIT(TCCR1A,COM1A0);
						CLEAR_BIT(TCCR1A,COM1A1);
						break;
					case OCRA_Nin_inverting:
						CLEAR_BIT(TCCR1A,COM1A0);
						SET_BIT(TCCR1A,COM1A1);
						break;
					case OCRA_Inverting:
						SET_BIT(TCCR1A,COM1A0);
						SET_BIT(TCCR1A,COM1A1);
						break;
					}	
	switch (oc1b_mode)
				{
					case OCRB_disconnected:
						CLEAR_BIT(TCCR1A,COM1B0);
						CLEAR_BIT(TCCR1A,COM1B1);
						break;
					case OCRB_Toggle:
						SET_BIT(TCCR1A,COM1B0);
						CLEAR_BIT(TCCR1A,COM1B1);
						break;
					case OCRB_Nin_inverting:
						CLEAR_BIT(TCCR1A,COM1B0);
						SET_BIT(TCCR1A,COM1B1);
						break;
					case OCRB_Inverting:
						SET_BIT(TCCR1A,COM1B0);
						SET_BIT(TCCR1A,COM1B1);
						break;
					}						
						
					
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(Edge_type edge)
{
	if(edge==Rising)
		SET_BIT(TCCR1B,ICES1);


	else if(edge==Falling)
		CLEAR_BIT(TCCR1B,ICES1);

}

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OV_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

