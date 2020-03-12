
#include "WDT.h"

extern void WDT_Off(void)
{
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}

extern void WDT_Set(TimeOut_t timeout)
{
	
	u8 wdt_value=0x08;//WDE SET & WDTOE CLEARED
	wdt_value|=timeout;
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR=wdt_value;
	

	
	
}
