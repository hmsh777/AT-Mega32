#ifndef ADC_H_
#define ADC_H_

#include "Memmap32.h"
#include "Std_types.h"
#include "Utils.h"

typedef enum
{
	CH_0=0x00,
	CH_1=0x01,
	CH_2=0x02,
	CH_3=0x03,
	CH_4=0x04,
	CH_5=0x05,
	CH_6=0x06,
	CH_7=0x07,
}Channel_type;

typedef enum
{
	AREF    =0x00,
	AVCC    =0x01,
	REF256V =0x03

}REF_type;

typedef enum
{
	scale_2   =0x00,
	scale_4   =0x02,
	scale_8   =0x03,
	scale_16  =0x04,
	scale_32  =0x05,
	scale_64  =0x06,
	scale_128 =0x07,
}PreScaler_type;

	extern	void ADC_Init(REF_type REF ,PreScaler_type PreScale);
	extern	void ADC_StartConversion(Channel_type CH);
	extern	u16 ADC_GetRead(void);
	extern	u16 ADC_GetRead_NoPolling(void);
	extern	void ADC_Interrupt_Enable(void);
	extern	void ADC_Interrupt_Disable(void);


#endif
