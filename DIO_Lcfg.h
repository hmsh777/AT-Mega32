#ifndef DIO_LCFG_H_
#define DIO_LCFG_H_

typedef enum
{   
	OUTPUT=0,
	INPULLUP,
	INFREE,
	}Pin_Status_type;

typedef enum
{
	PIN0=0,
	PIN1=1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31,
	TOTAL_PINS
	}Pin_Num_type;
	
extern const Pin_Status_type Pins_Status[TOTAL_PINS];

#endif
