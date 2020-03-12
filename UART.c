
#include "UART.h"

 /****************************Pointer to functions to be assigned to ISR*********************************/

static void (*Ptr_To_Trans_Int) (void);
static void (*Ptr_To_Rece_Int) (void);



/********************************************initialization **********************************************/

void UART_Init(void)
{
	//double transmission speed
	SET_BIT(UCSRA,U2X);

	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);

	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);

	//B- Bit data
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);

	//Async
	CLEAR_BIT(UCSRC,UMSEL);
	//NO parity
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	// One stop bit
	CLEAR_BIT(UCSRC,USBS);


	/* baud rate=9600 & Fosc=16MHz */
	UBRRH = 0;
	UBRRL = 207;
}



/*****************************************Interrupt functions*********************************************/


void UART_Receiver_Int_Enable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

 void UART_Receiver_Int_Disable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

 void UART_Transmit_Int_Enable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

 void UART_Transmit_Int_Disable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}
	
 void UART_callback_Rece_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Rece_Int = Ptr_to_Func;
}

 void UART_callback_Trans_Int(void (*Ptr_to_Func)(void))
{
	Ptr_To_Trans_Int = Ptr_to_Func;
}

 ISR(USART_RXC_vect)
{

	(*Ptr_To_Rece_Int)();
}

 ISR(USART_TXC_vect)
{
	(*Ptr_To_Trans_Int)();
}


/****************************************Send and receive functions with no ckecking********************************/

void UART_SendByte(const u8 data)
{

	UDR = data;
}

u8 UART_RecieveByte(void)
{

    return UDR;
}
/****************************************Send and receive functions with polling     ********************************/
void UART_SendData(const u8 data)
{
	while(!(CHECK_BIT(UCSRA,UDRE)));  //UDRE flag is set when the buffer is empty and ready for transmitting a new byte so wait until this flag is set to one.
	UDR = data;
}

u8 UART_RecieveData(void)
{
	while(!(CHECK_BIT(UCSRA,RXC)));  //RXC flag is set when the UART receive data so until this flag is set to one
    return UDR;
}



u8 UART_Recieve_NoBlock(u8*pdata)
{
	char statue=0;
	if(CHECK_BIT(UCSRA,RXC))
	{
		*pdata=UDR;

		statue=1;

	}
	else
	{	statue=0;
	}
return statue;
}









