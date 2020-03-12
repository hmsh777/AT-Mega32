
#include "Servo.h"


void SERVO_Init(void)
{
	/*set timer 1 prescaler to 8to get 1us tick time
	use fast mode with top value at OCRA reg to set the freq of servo
	diconnect OC1A PIN ,and generate the PWM on OC1B PIN with nin inverting mode to use OCR1B reg as the ton value*/

	Timer1_Init(Timer1_FastPWM_OCRA_TOP_mode,timer1_scale_8,disconnected,Nin_inverting);
	OCR1A=19999;//20000us to get 50hz 
	OCR1B=999;// 2000us ton to get angle zero
}

void SERVO_SetAngle(u8 angle)
{
	OCR1B=(((u32)angle*1000)/180)+999;
}

void DCMOTOR_Direction(Direction_type dir)
{
	if (dir==Clock_Wize)
	{
			DIO_WritePin(PIN30,LOW);
			DIO_WritePin(PIN31,HIGH);
	}
	else if (dir==UntiClock_Wize)
	{
			DIO_WritePin(PIN30,HIGH);
			DIO_WritePin(PIN31,LOW);
	}
	
}