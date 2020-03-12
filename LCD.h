#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000
#include "DIO_Interface.h"
#include "DIO_Lcfg.h"
#include <util/delay.h>

/**********************************     LCD Modes   **************************************************/
#define M_4BIT_SAMEPORT  0
#define M_4BIT_SEPARATED 1
#define M_8BIT           2


/********************************* define control pins     *******************************************/
#define RS PIN1
#define RW PIN0
#define E  PIN2
/*********************************   define LCD Mode       *******************************************/
#define LCD_MODE  M_4BIT_SEPARATED

/*******************for 8 bit mode and 4 bit_sameport mode define the LCD port **********************/
#define LCD_PORT  PA
/*******************for 4 bit same port mode define pins mask in port *******************************/
#define M_4BIT_MASK 0X78
/*******************    for 4 bit separated pins  mode define pins    *******************************/
#define D4 PIN3
#define D5 PIN13
#define D6 PIN23
#define D7 PIN31

/******************************************************************************************************/


extern void LCD_Init(void);
extern void LCD_WriteChar(u8 data);
extern void LCD_WriteSentence(u8 *ptrSentance);
extern void LCD_GoTo(u8 line, u8 x);
extern void LCD_WriteNumber(u64 u64Number);
extern void Create_Character(u8 *pucPattern,u8 cLocation);
extern void LCD_Clear(void);






#endif
