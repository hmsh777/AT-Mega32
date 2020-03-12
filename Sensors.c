
#include "Timers.h"
#include "Sensors.h"
#include "LCD.h"

volatile u8 over_flow_count=0;

u16 LM35_temp(void)
{
	u16 temp;
	u16 volt;
	u16 adc;
	
	ADC_StartConversion(LM35_ch);
	adc=ADC_GetRead();
	volt = ((u32)5000 * adc) / 1024;
	temp=volt/10;
	return temp;
}


u8 PIEZO_force(void)
{
	u16 force,volt;
	u16 adc,rem;
	ADC_StartConversion(PIEZO_ch);
	adc=ADC_GetRead();
	force = ((u32)100 * adc) / 1024;
	
	return force;
}



u16 MPX_Pressure(void)
{
	u32 press;
	u16 volt;
	u16 adc;
	ADC_StartConversion(MPX_ch);
	adc=ADC_GetRead();
	press=(((u32)adc-55)*1086)+150000;
	press=press/1000;
	
	return press;
}

/******************************************************************************************************/

void Fan_init(void)
{
	/*set timer 0 to prescaller 1024 to get tick time 128us*/
	Timer0_Init(Normal_mode,timer_scale_1024,disconnected);
	
	
	
}



u8 PROXI_Read(void)
{
	Voltage_Level_type status=DIO_ReadPin(PROXI_PIN);
	return status;
}

u16 Fan_Speed(void)
{
	u16 fan_speed=0;
	/*to calculate 1sec = 1000000
	tick number=1000000/ticktime=7812.5
	number of overflow=7812.5/256=30.517
	.517*256=132 tick
	so to get 7812tick we need to preload timer with(256-132) and count 31 interrupt*/
	TCNT0=124;
	over_flow_count=0;
	
	
	
	Timer0_OVInterrupt_Enable();
	while (over_flow_count<31)
	{
		
		if (PROXI_Read())
		{
			fan_speed++;
			while(PROXI_Read());

		}
	}
	
	
	Timer0_OVInterrupt_Disable();
	return fan_speed;//rps
	
	
}

ISR(_VECTOR(11))
{
	over_flow_count++;
}