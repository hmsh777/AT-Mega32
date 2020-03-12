
#include "UART_Services.h"

static void Send_Int_Function(void);
static void Send_Int_Function2(void);
static void Receive_Int_Function(void);
/**********************************************variables*******************************************************/

volatile  u8 flag=1;
static u8  *Asynch_Send_Str;
static u8  *Asynch_receive_str;

/*******************************************Send Functions*****************************************************/

void UART_SendString(const u8 *Str)
{
	u8 i = 0;
	while(Str[i] != '\0'){
		UART_SendData(Str[i]);
		i++;

	}
}
								////////////////////////////////////

void UART_SendString_Asynch(u8 *Str)
{
	Asynch_Send_Str=Str;
	UART_SendByte(Str[0]);

	UART_callback_Trans_Int(Send_Int_Function);
	UART_Transmit_Int_Enable();

}

static void Send_Int_Function(void)
{
static u8 i=1;
	if(Asynch_Send_Str[i] !='\0')
	{
		UART_SendByte(Asynch_Send_Str[i]);
		i++;
	}
	else
		{
		i=1;
		UART_Transmit_Int_Disable();
		}
}
								////////////////////////////////////
								
void UART_SendString_Asynch_NocodeInInt(u8 *Str)
{
	UART_callback_Trans_Int(Send_Int_Function2);
		UART_Transmit_Int_Enable();
	static	u8 i=0;
	if(flag)
		{
		if(Str[i])
			{
			UART_SendByte(Str[i]);
			i++;
			flag=0;
			}

		}

}
static void Send_Int_Function2(void)
{
	flag=1;
}


/*****************************************Receive Functions*****************************************************/

void UART_ReceiveString(u8 *Str)       //receive entil  '#'
{
	u8 i = 0;
	Str[i] = UART_RecieveData();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_RecieveData();
	}
	Str[i] = '\0';
}
								////////////////////////////////////

void UART_ReceiveString_NoBlock(u8 *Str)       // this function block cpu it's just to try "UART_RecieveData_NoBlock"  receive entil  '#'
{
	u8 i=0,data,status;
	do
	{
		status=UART_Recieve_NoBlock(&data);
		if(status)
		{
		Str[i]=data;
		i++;
		}
	}while(Str[i-1]!='#');
	Str[i-1]='\0';
}

								////////////////////////////////////
								
void UART_ReceiveString_Asynch(u8 *Str)
{
	Asynch_receive_str=Str;
	UART_Receiver_Int_Enable();
	UART_callback_Rece_Int(Receive_Int_Function);

}

static void Receive_Int_Function(void)
{
	static u8 i=0;
	Asynch_receive_str[i]=UART_RecieveByte();
	i++;

}




void SendString_MYProtocol(u8*str)
{
	u8 i=0,l=0;
	u16 sum=0;
	while(str[l])
	{

		sum+=str[l];
		
		l++;
	}
	UART_SendData(l);
	for(i=0;i<l;i++)
	{
		UART_SendData(str[i]);
	}
	UART_SendData((u8)sum);
	UART_SendData((u8)(sum>>8));


}
u8 ReceiveString_MyProtocol(u8*str)
{
	u8 i=0,l=0,firstbyte=0,secondbyte=0;
	u16 sum_send=0,sum_calc=0;
	l=UART_RecieveData();
	for(i=0;i<l;i++)
	{
		str[i]=UART_RecieveData();
		sum_calc+=str[i];
	}
	firstbyte=UART_RecieveData();
	secondbyte=UART_RecieveData();
	sum_send=firstbyte|(secondbyte<<8);

	if(sum_calc==sum_send)
		return 1;
	else
		return 0;


}

