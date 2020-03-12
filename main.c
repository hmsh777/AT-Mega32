#define  F_CPU 8000000
#include "DIO_Interface.h"
#include "LCD.h"
#include "Timers.h"
#include <util/delay.h>
#include "UART_Services.h"
#include "ADC.h"
#include "SPI.h"
#include "EXT_Interrupt.h"
#include "Sensors.h"
#include "Key_Bad.h"
#include "WIFI.h"
#include "Servo.h"
#include "WDT.h"
#include "ultrasonic.h"
int main(void)
{
	sei();
	DIO_Init();
	LCD_Init();
	LCD_WriteSentence("WDT test");
	SERVO_Init();
	ULTRASONIC_Init();
	//Timer1_Init(Timer1_Normal_mode,timer1_scale_8,OCRA_disconnected,OCRB_disconnected);
	
   u8 x=1,key,dist;
  
   
	while(1)
	{
		key=KEYBAD_Entry();
		if (key!=default_key)
		{
			LCD_GoTo(0,10);
			LCD_WriteChar(key);
			if (key=='1')
			{
				SERVO_SetAngle(45);
				dist=ULTRASONIC_GetDistance(ULTRASONIC_1);
				LCD_GoTo(1,0);
				LCD_WriteNumber(dist);
			}
			else if (key=='2')
			{
				SERVO_SetAngle(90);
				dist=ULTRASONIC_GetDistance(ULTRASONIC_2);
				LCD_GoTo(1,0);
				LCD_WriteNumber(dist);
			}
			
		}
	
	}

	
					
					
		
	

		
		
	

}
