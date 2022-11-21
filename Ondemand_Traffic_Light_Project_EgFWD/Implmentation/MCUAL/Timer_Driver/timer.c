/*
 * Timer.c
 *
 * Created: 11/14/2022 7:18:26 PM
 *  Author: Haytham Metawie
 */ 
#include "timer.h"

uint16_t overFlowCounter = 0;

/* Timer Initialization Function */
EN_TimerErrorState_t TIMER0_init(uint8_t timerMode)
{
	EN_TimerErrorState_t timer_initErrorState = TIMER_OK;
	switch(timerMode)
	{
		case NORMAL_MODE: TCCR0 = NORMAL_MODE; break;
		case PHASE_CORRECT_PWM_MODE: TCCR0 = PHASE_CORRECT_PWM_MODE; break;
		case CTC_MODE: TCCR0 = CTC_MODE; break;
		case FAST_PWM_MODE: TCCR0 = FAST_PWM_MODE; break;
		default: timer_initErrorState = TIMER_ERROR; break;	
	}
	return timer_initErrorState;
}

/* Set initial value to Timer0 register */
EN_TimerErrorState_t TIMER0_set_initial_value(uint16_t intialValue)
{
	TCNT0 = intialValue;
	return TIMER_OK;
}

/* Reset initial value of Timer0 register */
EN_TimerErrorState_t TIMER0_reset_initial_value(uint16_t intialValue)
{
	overFlowCounter = 0;
	return TIMER0_set_initial_value(intialValue);
}

/* Start Timer0 Function */
EN_TimerErrorState_t TIMER0_start(uint16_t timerPrescaler)
{
	EN_TimerErrorState_t timer_startErrorState = TIMER_OK;
	switch(timerPrescaler)
	{
		case CLK_NO_PRESCALING: SET_BIT(TCCR0, 0); break;
		case CLK_8_PRESCALER: SET_BIT(TCCR0, 1); break;
		case CLK_64_PRESCALER: SET_BIT(TCCR0, 0); SET_BIT(TCCR0, 1); break;
		case CLK_256_PRESCALER: SET_BIT(TCCR0, 2); break;
		case CLK_1024_PRESCALER: SET_BIT(TCCR0, 0); SET_BIT(TCCR0,2); break;
		default: timer_startErrorState = TIMER_ERROR; break;
	}
	return timer_startErrorState;
}

/* Stop Timer0 Function */
EN_TimerErrorState_t TIMER0_stop(void)
{
	TCCR0 &= 0xF8;
	return TIMER_OK;
}

/* Timer0 Delay Function */
EN_TimerErrorState_t TIMER0_delay(uint16_t numberOfSeconds, uint16_t overFlowPrescaler, uint16_t timerPrescaler)
{
	if(TIMER0_start(timerPrescaler) == TIMER_OK)
	{
		while(overFlowCounter < (overFlowPrescaler*numberOfSeconds))
		{
			while(READ_BIT(TIFR,0) == 0);		// Listening for overflow to occur
			SET_BIT(TIFR,0);				// Clear overflow flag 
			overFlowCounter ++;				// Increment overflow counter value
		}
		overFlowCounter = 0;
		return TIMER0_stop();
	}
	else return TIMER_ERROR;
}
