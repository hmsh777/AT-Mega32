
#include "WIFI.h"

volatile u8 WiFi_Buffer[20];

void NumberToString(u32 num,u8 *str)
{
	u8 i=0,j=0,temp;
	if(num==0)
	{
		str[0]='0';
		str[1]='\0';
	}
	else
	{
		while(num)
		{
			str[i]=num%10+'0';
			i++;
			num=num/10;
		}
		for(j=0;j<i;j++)
		{
			temp=str[j];
			str[j]=str[i-1-j];
			str[i-1-j]=temp;
		}
		str[i]='\0';
		
	}
}



void WIFI_Init(void)
{
	// Test
	UART_SendString("AT\r\n");
	_delay_ms(100);
	
	// Configuration
	UART_SendString("AT+UART_DEF=9600,8,1,0,0\r\n");
	_delay_ms(100);
	
	// WiFi Mode	
	UART_SendString("AT+CWMODE=1\r\n");
	_delay_ms(100);
	
	// Connect to network
	UART_SendString("AT+CWJAP=\"FH\",\"networkname\"\r\n");
	_delay_ms(10000);
	
	// Client Apply
	UART_SendString("AT+CIPSTART=\"TCP\",\"192.168.43.1\",1234\r\n");
	_delay_ms(5000);
	

	// Opening a channel to send data once received on uart
	UART_SendString("AT+CIPMODE=1\r\n");
	_delay_ms(100);
	
	// Send String
	UART_SendString("AT+CIPSEND\r\n");
	_delay_ms(100);
	
}


/* ================================================================================== */
/* Normal Mode */

void WIFI_sendNumber(u64 num)
{
	u16 data = num;
	u8 NumLenght=0;
	u8 NumLengthString[3];
	u8 NumString[10];
	if(num==0)
	{
		UART_SendString("AT+CIPSEND=");
		UART_SendData('1');
		UART_SendString("\r\n");
		_delay_ms(1000);
		UART_SendData('0');
		UART_SendString("\r\n");
	}
	else
	{
		while(data)//calculate number of digit in number
		{
			NumLenght++;
			data/=10;
		
		}
		NumberToString(NumLenght,NumLengthString);//convert number of digit to string
		NumberToString(num,NumString);//convert number to string
		
	    UART_SendString("AT+CIPSEND=");
		UART_SendString(NumLengthString);
	    UART_SendString("\r\n");
		_delay_ms(1000);
		UART_SendString(NumString);
		UART_SendString("\r\n");
	
	}
}

void WIFI_sendString(u8* str)
{
	u8 StringLength=0;
	u8 StringLengthString[10];
	while (str[StringLength])
	{
		StringLength++;
	}
	NumberToString(StringLength,StringLengthString);//convert string length to string	
		
	UART_SendString("AT+CIPSEND=");
	UART_SendString(StringLengthString);
	UART_SendString("\r\n");
	_delay_ms(300);
	UART_SendString(str);
	UART_SendString("\r\n");
}
