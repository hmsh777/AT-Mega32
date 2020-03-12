#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "Std_types.h"
#include "Utils.h"
#include "DIO_Lcfg.h"
#include "Memmap32.h"

typedef enum
{
	PA=0,
	PB,
	PC,
	PD,
	}Port_type;
	
typedef enum
{
	LOW=0,
	HIGH=1,
	}Voltage_Level_type;

extern void DIO_Init(void);
extern void DIO_WritePort(Port_type Port, u8 Value);
extern void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask);
extern u8 DIO_ReadPort(Port_type Port);
extern void DIO_WritePin(Pin_Num_type Pin,Voltage_Level_type Value);
extern void DIO_TogglePin(Pin_Num_type Pin);
extern Voltage_Level_type DIO_ReadPin(Pin_Num_type Pin);

#endif
