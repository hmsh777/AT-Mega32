
#include "ADC.h"

#include "LCD.h"

void ADC_Init(REF_type REF ,PreScaler_type PreScale)
{

//v ref set
	if(REF==AREF)
	{
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
	}
	else if(REF==AVCC)
	{
	     SET_BIT(ADMUX,REFS0);
		 CLEAR_BIT(ADMUX,REFS1);
	}
	else if (REF==REF256V)
	{
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	}

		//ADC right Adjust Result
		CLEAR_BIT(ADMUX,ADLAR);

		//ADC enable
		SET_BIT(ADCSRA,ADEN);

		//Prescaler 128
		ADCSRA&=0XF8;
		ADCSRA|=PreScale;

}

void ADC_StartConversion(Channel_type CH)
{   ADMUX &=0xe0;
	ADMUX |= CH;
	SET_BIT(ADCSRA,ADSC);
}

u16 ADC_GetRead(void)
{
	 u16 result; 
	  
	 while(CHECK_BIT(ADCSRA,ADSC));
	 
	 result=  *((u16*)& ADCL);
	 return result;
	
}


u16 ADC_GetRead_NoPolling(void)
	{
		 u16 result;
		result=  *((u16*)& ADCL);
		return result;

	}
void ADC_Interrupt_Enable(void)
	{
	SET_BIT(ADCSRA,ADIE);
	}
void ADC_Interrupt_Disable(void)
	{
	CLEAR_BIT(ADCSRA,ADIE);
	}

