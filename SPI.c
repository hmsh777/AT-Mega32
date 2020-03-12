
#include "SPI.h"

void SPI_Init_Slave(void)
{
	/*Set MISO as Output */
	//DIO_vidSetPinDirection(PORTB_Reg,PIN6,OUTPUT);

	/*Select Slave Mode*/
	CLEAR_BIT(SPCR,MSTR);
	/*Setup in Leading Edge,Sample in Trailing */
	SET_BIT(SPCR,CPHA);
	/*SCK is LOW when idle,Leading Edge is Rising,Trailing Edge is Falling*/
	CLEAR_BIT(SPCR,CPOL);
	/*LSB of the data word is transmitted first.*/
	SET_BIT(SPCR,DORD);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);

}
void SPI_Init_Master(void)
{
	/*Set MOSI,CLK,SS as Output*/
	//PORTB|=0xb0;
	/*Select Master Mode*/
	SET_BIT(SPCR,MSTR);
	/*Set in Leading Edge,Sample in Trailing */
	SET_BIT(SPCR,CPHA);
	/*SCK is LOW when idle,Leading Edge is Rising,Trailing Edge is Falling*/
	CLEAR_BIT(SPCR,CPOL);
	/*LSB of the data word is transmitted first.*/
	SET_BIT(SPCR,DORD);
	/*CLK/128*/
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLEAR_BIT(SPSR,SPI2X);
	/*Enable SPI*/
	SET_BIT(SPCR,SPE);
}

u8 SPI_TransRece(u8 TransmitedData)
{
	/*copy Transmitted Data To data Register*/
	SPDR=TransmitedData;
	/*Wait serial transfer to complete*/
	while(CHECK_BIT(SPSR,SPIF)==0);
	/*Save Received Data */
	return SPDR;
	//DIO_vidSetPinValue(PORTC_Reg,PIN7,HIGH);
}

void SPI_Transmit(u8 TransmitedData)
{
	SPDR=TransmitedData;
}


u8 SPI_Receive(void)
{
	while(CHECK_BIT(SPSR,SPIF)==0);
		return SPDR;
}

u8 SPI_Receive_NoPolling(void)
{

		return SPDR;
}

void SPI_Interrupt_Enable(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_Interrupt_Disable(void)
{
	CLEAR_BIT(SPCR,SPIE);

}

