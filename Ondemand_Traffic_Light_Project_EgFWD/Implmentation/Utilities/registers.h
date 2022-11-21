/*
 * registers.h
 * This file contains the definition (addresses) of the commonly used registers in ATMega32A microprocessor
 * Created: 11/9/2022 12:05:16 AM
 *  Author: Haytham Metawie
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "datatypes.h"

/********************************************************/
/* ================ Status Register ================== */
/******************************************************/
#define SREG (*(volatile uint8_t*)(0x5F))

/********************************************************/
/* ================= GPIO Registers ================== */
/******************************************************/

/* PortA registers */
#define PINA (*(volatile uint8_t*)(0x39))
#define DDRA (*(volatile uint8_t*)(0x3A))
#define PORTA (*(volatile uint8_t*)(0x3B))

/* PortB registers */
#define PINB (*(volatile uint8_t*)(0x36))
#define DDRB (*(volatile uint8_t*)(0x37))
#define PORTB (*(volatile uint8_t*)(0x38))

/* PortC registers */
#define PINC (*(volatile uint8_t*)(0x33))
#define DDRC (*(volatile uint8_t*)(0x34))
#define PORTC (*(volatile uint8_t*)(0x35))


/* PortD registers */
#define PIND (*(volatile uint8_t*)(0x30))
#define DDRD (*(volatile uint8_t*)(0x31))
#define PORTD (*(volatile uint8_t*)(0x32))



/*********************************************************/
/* ================= Timer0 Registers ================= */
/*******************************************************/
/* Timer/Counter Register */
#define TCNT0 (*(volatile uint8_t*)(0x52))

/* Timer/Counter Control Register */
#define TCCR0 (*(volatile uint8_t*)(0x53))

/* Timer/Counter Flag Register */
#define TIFR (*(volatile uint8_t*)(0x58))

/* Timer/Counter Interrupt Mask Register */
#define TIMSK (*(volatile uint8_t*)(0x59))

/* Timer/Counter Interrupt Mask Register */
#define OCR0 *((volatile uint8_t*)0x5C)

/*****************************************************************/
/* ================ External Interrupts Registers ============= */
/***************************************************************/

/* MCU Control Register */
#define MCUCR (*(volatile uint8_t*)(0x55))

/* MCU Control and Status Register */
#define MCUCSR (*(volatile uint8_t*)(0x54))

/* General Interrupt Flag Register */
#define GIFR *((volatile uint8_t*)0x5A)

/* General Interrupt Control Register */ 
#define GICR (*(volatile uint8_t*)(0x5B))





#endif /* REGISTERS_H_ */