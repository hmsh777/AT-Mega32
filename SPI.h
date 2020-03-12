/*
 * SPI.H
 *
 *  Created on: Dec 14, 2019
 *      Author: pasos
 */

#ifndef SPI_H_
#define SPI_H_





#include "Memmap32.h"
#include "Std_types.h"
#include "Utils.h"

void SPI_Init_Slave(void);
void SPI_Init_Master(void);
u8 SPI_TransRece(u8 TransmitedData);
void SPI_Transmit(u8 TransmitedData);
u8 SPI_Receive(void);
u8 SPI_Receive_NoPolling(void);
void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);
#endif /* SPI_H_ */
