/*
 * interrupt.c
 *
 * Created: 11/14/2022 2:47:38 PM
 *  Author: Haytham Metawie
 */ 

#include "interrupt.h"

/* Global Interrupt Enable Function*/
EN_InterruptErrorState_t global_interrupt_init(void)
{
	sei();
	//SET_BIT(SREG, 7); /* Set I-bit in status register to 1 */
	EN_InterruptErrorState_t globalInterruptInitState = INTERRUPT_OK;
	if(!IS_SET(SREG,7)) globalInterruptInitState = INTERRUPT_Error;
	return globalInterruptInitState;
}

/* External Interrupt Enable Function*/
EN_InterruptErrorState_t external_interrupt_init(uint8_t interruptSource, uint8_t interruptSense)
{
	EN_InterruptErrorState_t externalInterruptInitState = INTERRUPT_OK;
	switch(interruptSource)
	{
	case INT0 :
		if(interruptSense == LOW_LEVEL)
		{
				CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
				SET_BIT(GICR,6);			// 2. Enable external interrupt pin INT0
				CLEAR_BIT(MCUCR,0);			// 3. Set INT0 to low level interrupt sense
				CLEAR_BIT(MCUCR,1);			// 3. Set INT0 to low level interrupt sense
				SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
		}

		else if(interruptSense == LOG_CHANGE)
		{
			CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
			SET_BIT(GICR,6);			// 2. Enable external interrupt pin INT0
			SET_BIT(MCUCR,0);			// 3. Set INT0 to logical change interrupt sense
			CLEAR_BIT(MCUCR,1);			// 3. Set INT0 to logical change interrupt sense
			SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
		}

		else if(interruptSense == FALLING_EDGE)
		{
			//CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
			SET_BIT(MCUCR,1);			// 3. Set INT0 to falling edge interrupt sense
			CLEAR_BIT(MCUCR,0);			// 3. Set INT0 to falling edge interrupt sense
			SET_BIT(GICR,6);			// 2. Enable external interrupt pin INT0
			//SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
		}
	

		else if(interruptSense == RISING_EDGE)
		{
			CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
			SET_BIT(GICR,6);			// 2. Enable external interrupt pin INT0
			SET_BIT(MCUCR,0);			// 3. Set INT0 to rising edge interrupt sense
			SET_BIT(MCUCR,1);			// 3. Set INT0 to rising edge interrupt sense
			SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
		}
	
		else {externalInterruptInitState = INTERRUPT_Error;}
		break;

	case INT1 :

	if(interruptSense == LOW_LEVEL)
	{
		CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
		SET_BIT(GICR,7);			// 2. Enable external interrupt pin INT1
		CLEAR_BIT(MCUCR,0);			// 3. Set INT1 to low level interrupt sense
		CLEAR_BIT(MCUCR,3);			// 3. Set INT1 to low level interrupt sense
		SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
	}

	else if(interruptSense == LOG_CHANGE)
	{
		CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
		SET_BIT(GICR,7);			// 2. Enable external interrupt pin INT1
		SET_BIT(MCUCR,0);			// 3. Set INT1 to logical change interrupt sense
		CLEAR_BIT(MCUCR,3);			// 3. Set INT1 to logical change interrupt sense
		SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
	}

	else if(interruptSense == FALLING_EDGE)
	{
		CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
		SET_BIT(GICR,7);			// 2. Enable external interrupt pin INT1
		SET_BIT(MCUCR,3);			// 3. Set INT1 to falling edge interrupt sense
		CLEAR_BIT(MCUCR,0);			// 3. Set INT1 to falling edge interrupt sense
		SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
	}
	

	else if(interruptSense == RISING_EDGE)
	{
		CLEAR_BIT(SREG,7);			// 1. Clear global interrupt bit
		SET_BIT(GICR,7);			// 2. Enable external interrupt pin INT1
		SET_BIT(MCUCR,0);			// 3. Set INT1 to rising edge interrupt sense
		SET_BIT(MCUCR,3);			// 3. Set INT1 to rising edge interrupt sense
		SET_BIT(SREG,7); 			// 4. Set global interrupt bit to enable interrupts
	}
	
	else {externalInterruptInitState = INTERRUPT_Error;}
	break;
	
	case INT2:

	if(interruptSense == FALLING_EDGE)
	{
		CLEAR_BIT(SREG,7);					// 1. Clear global interrupt bit
		SET_BIT(GICR,5);					// 2. Enable external interrupt pin INT2
		CLEAR_BIT(MCUCSR,6);				// 3. Set INT2 to falling edge interrupt sense
		SET_BIT(SREG,7);					// 4. Set global interrupt bit to enable interrupts
	}

	else if(interruptSense == RISING_EDGE)
	{
		CLEAR_BIT(SREG,7);					// 1. Clear global interrupt bit
		SET_BIT(GICR,5);					// 2. Enable external interrupt pin INT2
		SET_BIT(MCUCSR,6);					// 3. Set INT2 to rising edge interrupt sense
		SET_BIT(SREG,7);					// 4. Set global interrupt bit to enable interrupts
	}
	else {externalInterruptInitState = INTERRUPT_Error;}
	break;
	
	default: externalInterruptInitState = INTERRUPT_Error; break;

}


	return externalInterruptInitState;
}

