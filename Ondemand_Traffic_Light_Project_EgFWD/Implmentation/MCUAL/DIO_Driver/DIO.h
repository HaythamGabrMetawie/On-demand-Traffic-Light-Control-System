/*
 * DIO.h
 * Header file of DIO Driver; contains all definition needed and functions prototypes for DIO.c
 * Created: 11/13/2022 4:05:58 AM
 *  Author: Haytham Metawie
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/datatypes.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

/* PORT NAMES DEFINITIONS */
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

/* PINS DEFINITIONS */
#define PIN0 0 
#define PIN1 1 
#define PIN2 2 
#define PIN3 3 
#define PIN4 4 
#define PIN5 5
#define PIN6 6
#define PIN7 7

// REGISTER DATA DIRECTION
#define IN	0
#define OUT	1

//PIN SIGNAL LEVEL
#define LOW		0
#define HIGH	1

typedef enum EN_DIOErrorState_t
{
	DIO_OK, DIO_ERROR
}EN_DIOErrorState_t;

/* DIO's pin Data Direction Initialization Function */
EN_DIOErrorState_t DIO_init(uint8_t portName, uint8_t pinNumber, uint8_t dataDirection);

/* Read data from a DIO's pin Function */
EN_DIOErrorState_t DIO_read(uint8_t portName, uint8_t pinNumber, uint8_t* dataRead);

/* Write data (LOW or HIGH) to a DIO's pin Function */
EN_DIOErrorState_t DIO_write(uint8_t portName, uint8_t pinNumber, uint8_t dataWrite);

/* Toggle data of a DIO's pin Function */
EN_DIOErrorState_t DIO_toggle(uint8_t portName, uint8_t pinNumber);



#endif /* DIO_H_ */