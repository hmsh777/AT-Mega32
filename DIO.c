#include "DIO_Interface.h"

void DIO_Init(void)
{
	u8 Pin_Num;
	Port_type Port;
	Pin_Status_type Status;
	u8 LocalIterator;
	
	for (LocalIterator=0;LocalIterator<TOTAL_PINS;LocalIterator++)
	{
		Status=Pins_Status[LocalIterator];
		Port=LocalIterator/8;
		Pin_Num=LocalIterator%8;
		
		switch (Status)
		{
			case OUTPUT:
			switch (Port)
			{
				case PA:
				SET_BIT(DDRA,Pin_Num);
				break;
				case PB:
				SET_BIT(DDRB,Pin_Num);
				break;
				case PC:
				SET_BIT(DDRC,Pin_Num);
				break;
				case PD:
				SET_BIT(DDRD,Pin_Num);
				break;
			}
			break;
			case INPULLUP:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,Pin_Num);
				SET_BIT(PORTA,Pin_Num);
				break;
				case PB:
				CLEAR_BIT(DDRB,Pin_Num);
				SET_BIT(PORTB,Pin_Num);
				break;
				case PC:
				CLEAR_BIT(DDRC,Pin_Num);
				SET_BIT(PORTC,Pin_Num);
				break;
				case PD:
				CLEAR_BIT(DDRD,Pin_Num);
				SET_BIT(PORTD,Pin_Num);
				break;
			}
			break;
			case INFREE:
			switch (Port)
			{
				case PA:
				CLEAR_BIT(DDRA,Pin_Num);
				CLEAR_BIT(PORTA,Pin_Num);
				break;
				case PB:
				CLEAR_BIT(DDRB,Pin_Num);
				CLEAR_BIT(PORTB,Pin_Num);
				break;
				case PC:
				CLEAR_BIT(DDRC,Pin_Num);
				CLEAR_BIT(PORTC,Pin_Num);
				break;
				case PD:
				CLEAR_BIT(DDRD,Pin_Num);
				CLEAR_BIT(PORTD,Pin_Num);
				break;
			}
			break;
		}
		
	}
}

void DIO_WritePort(Port_type Port,u8 Value)
{
	switch (Port)
	{
		case PA:
		ASSIGN_REG(PORTA,Value);
		break;
		case PB:
		ASSIGN_REG(PORTB,Value);
		break;
		case PC:
		ASSIGN_REG(PORTC,Value);
		break;
		case PD:
		ASSIGN_REG(PORTD,Value);
		break;
	}
}
void DIO_WriteBitsInPort(Port_type Port,u8 Value,u8 Mask)
{
	switch (Port)
	{
		case PA:
		CLEAR_BITS_REG(PORTA,Mask);
		SET_BITS_REG(PORTA,Value&Mask);
		break;
		case PB:
		CLEAR_BITS_REG(PORTB,Mask);
		SET_BITS_REG(PORTB,Value&Mask);
		break;
		case PC:
		CLEAR_BITS_REG(PORTC,Mask);
		SET_BITS_REG(PORTC,Value&Mask);
		break;
		case PD:
		CLEAR_BITS_REG(PORTD,Mask);
		SET_BITS_REG(PORTD,Value&Mask);
		break;
	}
}
u8 DIO_ReadPort(Port_type Port)
{
	switch (Port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
		default:
		return 0x00;
		break;
	}
}
void DIO_WritePin(Pin_Num_type Pin,Voltage_Level_type Value)
{
	u8 Pin_Num=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		if (HIGH==Value)
		{
			SET_BIT(PORTA,Pin_Num);
		}
		else
		{
			CLEAR_BIT(PORTA,Pin_Num);
		}
		break;
		case PB:
		if (HIGH==Value)
		{
			SET_BIT(PORTB,Pin_Num);
		}
		else
		{
			CLEAR_BIT(PORTB,Pin_Num);
		}
		break;
		case PC:
		if (HIGH==Value)
		{
			SET_BIT(PORTC,Pin_Num);
		}
		else
		{
			CLEAR_BIT(PORTC,Pin_Num);
		}
		break;
		case PD:
		if (HIGH==Value)
		{
			SET_BIT(PORTD,Pin_Num);
		}
		else
		{
			CLEAR_BIT(PORTD,Pin_Num);
		}
		break;
	}
}
void DIO_TogglePin(Pin_Num_type Pin)
{
	u8 Pin_Num=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
			TOOGLE_BIT(PORTA,Pin_Num);
		break;
		case PB:
			TOOGLE_BIT(PORTB,Pin_Num);
		break;
		case PC:
			TOOGLE_BIT(PORTC,Pin_Num);
		break;
		case PD:
			TOOGLE_BIT(PORTD,Pin_Num);
		break;
	}
}
Voltage_Level_type DIO_ReadPin(Pin_Num_type Pin)
{
	u8 Pin_Num=Pin%8;
	Port_type Port=Pin/8;
	switch (Port)
	{
		case PA:
		return CHECK_BIT(PINA,Pin_Num);
		break;
		case PB:
		return CHECK_BIT(PINB,Pin_Num);
		break;
		case PC:
		return CHECK_BIT(PINC,Pin_Num);
		break;
		case PD:
		return CHECK_BIT(PIND,Pin_Num);
		break;
		default:
		return 0x00;
		break;
	}
}

