
#include "EXT_Interrupt.h"
/*
void External_Interrupt_Init(InterruptPin_type interrupt_pin,Interrupt_Trigger_Mode_type interrupt_mode )
{

	SET_BIT(EIMSK,interrupt_pin);
	switch(interrupt_pin)
	{
		case (INT0):
		{
			switch(interrupt_mode)
			{
				case Low_level :
				{
					CLEAR_BIT(EICRA,ISC00);
					CLEAR_BIT(EICRA,ISC01);
					break;
				}
				case Logical_chang :
				{
					SET_BIT(EICRA,ISC00);
					CLEAR_BIT(EICRA,ISC01);
					break;
				}
				case Falling_edge :
				{
					CLEAR_BIT(EICRA,ISC00);
					SET_BIT(EICRA,ISC01);
					break;
				}
				case Rising_edge :
				{
					SET_BIT(EICRA,ISC00);
					SET_BIT(EICRA,ISC01);
					break;
				}
				default:
				break;

			}
			break;
		}



		case (INT1):
		{

			switch(interrupt_mode)
			{
				case Low_level :
				{
					CLEAR_BIT(EICRA,ISC10);
					CLEAR_BIT(EICRA,ISC11);
					break;
				}
				case Logical_chang :
				{
					SET_BIT(EICRA,ISC10);
					CLEAR_BIT(EICRA,ISC11);
					break;
				}
				case Falling_edge :
				{
					CLEAR_BIT(EICRA,ISC10);
					SET_BIT(EICRA,ISC11);
					break;
				}
				case Rising_edge :
				{
					SET_BIT(EICRA,ISC10);
					SET_BIT(EICRA,ISC11);
					break;
				}
				default:
				break;
			}
			break;
		}
		case (INT2):
		{
			switch(interrupt_mode)
			{

				case Falling_edge :
				{
					CLEAR_BIT(EICRA,ISC20);
					SET_BIT(EICRA,ISC21);

					break;
				}
				case Rising_edge :
				{
					SET_BIT(EICRA,ISC20);
					SET_BIT(EICRA,ISC21);
					break;
				}
				default:
				break;
			}
			break;

		}
		default:
		break;
	}
}*/


