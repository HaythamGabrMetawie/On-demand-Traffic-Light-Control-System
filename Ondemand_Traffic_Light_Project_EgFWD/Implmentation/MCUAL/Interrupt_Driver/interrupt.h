/*
 * interrupt.h
 *
 * Created: 11/13/2022 5:54:12 AM
 *  Author: Haytham Metawie
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/datatypes.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"

/* Interrupt Source Pin Definition */
#define INT0 0
#define INT1 1
#define INT2 2

/* Interrupts Sense Definition */
#define LOW_LEVEL		0
#define LOG_CHANGE		1
#define FALLING_EDGE	2
#define RISING_EDGE		3

/* EXTERNAL INTERRUPT REQUEST 0 */
#define EXT_INT_0 __vector_1

/* MACRO DEFINES THE ISR for Pedestrian Traffic Mode */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

#define sei() __asm__ __volatile__ ("sei" ::: "memory")
#define cli() __asm__ __volatile__ ("cli" ::: "memory") 


typedef enum EN_InterruptErrorState_t
{
	INTERRUPT_OK, INTERRUPT_Error
	
} EN_InterruptErrorState_t;

/* Global Interrupt Enable Function*/
EN_InterruptErrorState_t global_interrupt_init(void);

/* External Interrupt Enable Function*/
EN_InterruptErrorState_t external_interrupt_init(uint8_t interruptSource, uint8_t interruptSense);





#endif /* INTERRUPT_H_ */