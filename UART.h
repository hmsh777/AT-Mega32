/* Author: Mohamed Abd El Baset*/
 


#ifndef UART_H_
#define UART_H_


#include "Std_types.h"
#include "Utils.h"
#include "Memmap32.h"



void UART_Init(void);

void UART_Receiver_Int_Enable(void);
void UART_Receciver_Int_Disable(void);

void UART_Transmit_Int_Enable(void);
void UART_Transmit_Int_Disable(void);

void UART_callback_Rece_Int(void (*Ptr_to_Func)(void));
void UART_callback_Trans_Int(void (*Ptr_to_Func)(void));



void UART_SendByte(const u8 data);
u8 UART_RecieveByte(void);


void UART_SendData(const u8 data);
u8 UART_RecieveData(void);
u8 UART_Recieve_NoBlock(u8*pdata);


#endif /* UART_H_ */
