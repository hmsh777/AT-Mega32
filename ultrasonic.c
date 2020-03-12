#include "ultrasonic.h"


static volatile u16 t1,t2,flag=0,c=0;

void ULTRASONIC_Init(void)
{
	/****you can use timer in another mode except modes using ICR as top put take care dont reset timer****/
	Timer1_Init(Timer1_Normal_mode,timer_scale_8,OCRA_disconnected,OCRB_disconnected);
	
}

u8 ULTRASONIC_GetDistance(ULTRASONIC_type ultrasonic_pin)
{
	
	u8 distance;
	u16 time;
	TCNT1=0;
	c=0;
	flag=0;
	DIO_WritePin(ultrasonic_pin,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic_pin,LOW);
	Timer1_InputCaptureEdge(Rising);
	Timer1_ICU_InterruptEnable();
	while (flag<2);
	time=t2-t1;
	distance=time/58;
	Timer1_ICU_InterruptDisable();
	return distance;
	
}

ISR (TIMER1_CAPT_vect)
{
	if(flag==0)
	{
		t1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(Falling);
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
		Timer1_InputCaptureEdge(Rising);
	}
}