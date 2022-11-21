/*
 * Timer.h
 * Header file of Timer Driver; contains all definition needed and functions prototypes for Timer.c
 * Created: 11/13/2022 6:04:38 AM
 *  Author: Haytham Metawie
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/datatypes.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../Interrupt_Driver/interrupt.h"

/* Timer Scaler - Clock Select */
#define CLK_NO_PRESCALING	1
#define CLK_8_PRESCALER		8
#define CLK_64_PRESCALER	64
#define CLK_256_PRESCALER	256
#define CLK_1024_PRESCALER	1024

/* Timer/Counter Operations Mode */				//	WGM01(3)	WGM00(6)
#define NORMAL_MODE						0x00	//		0			0
#define PHASE_CORRECT_PWM_MODE			0x40	//		0			1
#define CTC_MODE						0x08	//		1			0
#define FAST_PWM_MODE					0x48	//		1			1


/* Timer Error State Enum Definition */
typedef enum EN_TimerErrorState_t
 {
	 TIMER_OK, TIMER_ERROR
 }EN_TimerErrorState_t;


/* Timer Initialization Function */
EN_TimerErrorState_t TIMER0_init(uint8_t timerMode);

/* Set initial value to Timer0 register */
EN_TimerErrorState_t TIMER0_set_initial_value(uint16_t intialValue);

/* Reset initial value of Timer0 register */
EN_TimerErrorState_t TIMER0_reset_initial_value(uint16_t intialValue);

/* Start Timer0 Function */
EN_TimerErrorState_t TIMER0_start(uint16_t timerPrescaler);

/* Stop Timer0 Function */
EN_TimerErrorState_t TIMER0_stop(void);

/* Timer0 Delay Function */
EN_TimerErrorState_t TIMER0_delay(uint16_t numberOfSeconds, uint16_t overFlowPrescaler, uint16_t timerPrescaler);

#endif /* TIMER_H_ */