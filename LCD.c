#include "LCD.h"
/************************************* 8 BIT Mode functions********************************************/
#if (LCD_MODE==M_8BIT)

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,(command));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}

void LCD_Init(void)
{
	
	_delay_ms(50);          // said in data sheet to delay after power on for 1st time
	
	LCD_WriteCommand(0x38); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,(data));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}
/************************************* 4 BIT Mode functions********************************************/
#elif (LCD_MODE==M_4BIT_SAMEPORT)



static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WriteBitsInPort(LCD_PORT,(command>>1),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(command),0xf0);
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
	DIO_WriteBitsInPort(LCD_PORT,(command<<3),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(command<<4),0xf0);
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}

 static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WriteBitsInPort(LCD_PORT,(data>>1),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,((data)),0xf0);
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
	DIO_WriteBitsInPort(LCD_PORT,(data<<3),M_4BIT_MASK);
	//DIO_WriteBitsInPort(LCD_PORT,(data<<4),0xf0);
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}
void LCD_Init(void)
{
	
	_delay_ms(50);          // said in data sheet to delay after power on for 1st time
	LCD_WriteCommand(0x02);//4 bit mode only
	_delay_ms(1); 
	LCD_WriteCommand(0x28); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}
/************************************* 4 BIT Mode separated Pins functions********************************************/
#elif (LCD_MODE==M_4BIT_SEPARATED)

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(D4,CHECK_BIT(command,4));
	DIO_WritePin(D5,CHECK_BIT(command,5));
	DIO_WritePin(D6,CHECK_BIT(command,6));
	DIO_WritePin(D7,CHECK_BIT(command,7));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
	DIO_WritePin(D4,CHECK_BIT(command,0));
	DIO_WritePin(D5,CHECK_BIT(command,1));
	DIO_WritePin(D6,CHECK_BIT(command,2));
	DIO_WritePin(D7,CHECK_BIT(command,3));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(D4,CHECK_BIT(data,4));
	DIO_WritePin(D5,CHECK_BIT(data,5));
	DIO_WritePin(D6,CHECK_BIT(data,6));
	DIO_WritePin(D7,CHECK_BIT(data,7));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
	DIO_WritePin(D4,CHECK_BIT(data,0));
	DIO_WritePin(D5,CHECK_BIT(data,1));
	DIO_WritePin(D6,CHECK_BIT(data,2));
	DIO_WritePin(D7,CHECK_BIT(data,3));
	DIO_WritePin(E,HIGH);
	_delay_ms(2);
	DIO_WritePin(E,LOW);
	_delay_ms(2);
}
void LCD_Init(void)
{
	_delay_ms(50);          // said in data sheet to delay after power on for 1st time
	LCD_WriteCommand(0x02);//4 bit mode only
	_delay_ms(1);
	LCD_WriteCommand(0x28); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in data sheet
	LCD_WriteCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_WriteCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x80);
}
#endif

/*************************** service functions*****************************************************/
void LCD_WriteChar(u8 character)
{
	LCD_WriteData(character);
}



void LCD_WriteSentence(u8 *ptrSentance)
{
	u8 i=0;
	for(i=0;ptrSentance[i];i++)
	{
		LCD_WriteData(ptrSentance[i]);
	}

	

}
void LCD_GoTo(u8 line, u8 x)
{
	if(0 == line)
	{
		if (x>=0 && x <=15)
		{
			LCD_WriteCommand(0x80 + x);
		}
	}
	else if (1 == line)
	{
		if (x>=0 && x <=15)
		{
			LCD_WriteCommand(0xC0 + x);
		}
	}
}



void LCD_WriteNumber(u64 u64Number)
{
	u8 i=0,arr[10],j;
	if(u64Number==0)
	LCD_WriteData('0');
	else{
		while(u64Number)
		{
			arr[i]=u64Number%10+'0';
			u64Number/=10;
			i++;
		}
		for(j=i;j>0;j--)
		{
			LCD_WriteData(arr[j-1]);
		}
	}
	/*
	LCD_WriteData(u64Number%10000/1000+'0');
	LCD_WriteData(u64Number%1000/100+'0');
	LCD_WriteData(u64Number%100/10+'0');
	LCD_WriteData(u64Number%10/1+'0');
*/
}

void Create_Character(u8 *pucPattern,u8 cLocation) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(cLocation*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(pucPattern[iLoop]); //Pass the bytes of pattern on LCD

}
void LCD_Clear(void)
{

	LCD_WriteCommand(0x01);

}

	

