/*
 * application.c
 *
 * Created: 11/14/2022 9:01:22 PM
 *  Author: Haytham Metawie
 */ 
#include "application.h"

uint8_t mode = NORMAL_TRAFFIC_MODE; 
uint8_t currentState = 0;
uint8_t blinksCount = 0;

void APP_init(void)
{
	/* Pedestrian Button initialization */
	BUTTON_init(BUTTON_PORT, BUTTON_PIN);
	
	/* LEDs initialization for car traffic light */
	LED_init(LED_CAR_PORT, LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT, LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT, LED_CAR_R_PIN);
	
	/* LEDs initialization for pedestrian traffic light */
	LED_init(LED_PED_PORT, LED_PED_G_PIN);
	LED_init(LED_PED_PORT, LED_PED_Y_PIN);
	LED_init(LED_PED_PORT, LED_PED_R_PIN);
	
	
	/* Enable Global and External Interrupts */
	global_interrupt_init();						// sei() replacement
	external_interrupt_init(INT0, FALLING_EDGE);	// enable interrupt INT0 w/ falling edge
	
	/* Timer0 initialization */
	TIMER0_init(NORMAL_MODE);
	
	/* set initial value for Timer0 */
	TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
	
}

void APP_start(void)
{
	while (1)
	{
		switch(mode)
		{
			
			case NORMAL_TRAFFIC_MODE: // Starting in Normal Traffic Mode
			// 1. Car Green LED is on and Pedestrian Red LED is on.
			currentState = GREEN;
			LED_on(LED_CAR_PORT, LED_CAR_G_PIN);
			LED_on(LED_PED_PORT, LED_CAR_R_PIN);
			// 2. Wait for 5 seconds delay
			TIMER0_delay(5, DELAY_1S_OVF , CLK_1024_PRESCALER);
			TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
			// 3. Car Green LED is off after 5 seconds delay
			LED_off(LED_CAR_PORT, LED_CAR_G_PIN);
			// 4. Yellow LED blinks for 5 seconds
			currentState = YELLOW;
			while (blinksCount < 5)
			{
				LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);	
				TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
				TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
				blinksCount ++;
			}
			blinksCount = 0; // reset blinks count
			// 5. Pedestrian Red LED is off 
			LED_off(LED_PED_PORT, LED_CAR_R_PIN);
			// 6. Car Red LED is on, Car Yellow LED is off, and Pedestrian Green LED is on.
			currentState = RED;
			LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
			LED_on(LED_CAR_PORT, LED_CAR_R_PIN);
			LED_on(LED_PED_PORT, LED_CAR_G_PIN);
			
			// 7. 5 seconds delay
			TIMER0_delay(5, DELAY_1S_OVF, CLK_1024_PRESCALER);
			TIMER0_set_initial_value(TIMER_INITIAL_VALUE); 
			
			// 8. Car Yellow LED is on and Pedestrian Green LED is off
			currentState = YELLOW;
			LED_on(LED_CAR_PORT, LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT, LED_PED_G_PIN);
			
			// 9. Both Car and Pedestrian Yellow LEDs blink for 5 seconds
			while (blinksCount < 5)
			{
				LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
				LED_blink(LED_PED_PORT, LED_PED_Y_PIN);
				TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
				TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
				blinksCount ++;
			}
			blinksCount = 0; // reset blinks count
			
			// 10. Both Car and Pedestrian  Yellow LEDs are off
			LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT, LED_PED_Y_PIN);
			break;
			
			case PEDESTRIAN_TRAFFIC_MODE: // Starting in Pedestrian Traffic Mode
			// 1. Clear global interrupt
			CLEAR_BIT(SREG, 7);
			// 2. check for current state
			switch(currentState)
			{
				case RED:
				// 1. Pedestrian Green LED is on
				LED_on(LED_PED_PORT, LED_PED_G_PIN);
				// 2. Delay for 5 seconds
				TIMER0_delay(5, DELAY_1S_OVF , CLK_1024_PRESCALER);
				TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
				// 3. Car Red LED is off
				LED_off(LED_CAR_PORT, LED_CAR_R_PIN);
				// 4. Blink Car Yellow Led for 5 seconds 
				while (blinksCount < 5)
				{
					LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
					TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
					TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
					blinksCount ++;
				}
				blinksCount = 0; // reset blinks count
				// 5. Pedestrian Green LED is off and Car Yellow LED is off
				LED_off(LED_PED_PORT, LED_PED_G_PIN);
				LED_off(LED_CAR_PORT, LED_PED_Y_PIN);
				break;
				
				case YELLOW:
				// 1. Car Yellow LED is off and Pedestrian Red LED is off
				LED_off(LED_CAR_PORT, LED_PED_Y_PIN);
				LED_off(LED_PED_PORT, LED_PED_R_PIN);
				
				// 2. Both Car and Pedestrian Yellow LEDs blink for 5 seconds
				while (blinksCount < 5)
				{
					LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
					LED_blink(LED_PED_PORT, LED_PED_Y_PIN);
					TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
					TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
					blinksCount ++;
				}
				blinksCount = 0; // reset blinks count
				
				// 3. Car Yellow LED is off and Car Red LED is on
				LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
				LED_on(LED_CAR_PORT, LED_CAR_R_PIN);
				// 4. Pedestrian Yellow LED is off and Pedestrian Green LED is on
				LED_off(LED_PED_PORT, LED_PED_Y_PIN);
				LED_on(LED_PED_PORT, LED_PED_G_PIN);
				// 5. Delay for 5 seconds
				TIMER0_delay(5, DELAY_1S_OVF , CLK_1024_PRESCALER);
				TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
				// 6. Car Red LED is off
				LED_off(LED_CAR_PORT, LED_CAR_R_PIN);
				// 7. Blink Car Yellow Led for 5 seconds
				while (blinksCount < 5)
				{
					LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
					TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
					TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
					blinksCount ++;
				}
				blinksCount = 0; // reset blinks count
				// 8. Car Yellow LED is off and Pedestrian Green LED is off
				LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT, LED_PED_G_PIN);
				break;
				
				case GREEN:
				// 1. Car Green LED is off and Pedestrian Red LED is off
				LED_off(LED_CAR_PORT, LED_CAR_G_PIN);
				LED_off(LED_PED_PORT, LED_PED_R_PIN);
				// 2. Both Car and Pedestrian Yellow LEDs blink for 5 seconds
				while (blinksCount < 5)
				{
					LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
					LED_blink(LED_PED_PORT, LED_PED_Y_PIN);
					TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
					TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
					blinksCount ++;
				}
				blinksCount = 0; // reset blinks count
				// 3. Car Yellow LED is off and Car Red LED is on
				LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
				LED_on(LED_CAR_PORT, LED_CAR_R_PIN);
				// 4. Pedestrian Yellow LED is off and Pedestrian Green LED is on
				LED_off(LED_PED_PORT, LED_PED_Y_PIN);
				LED_on(LED_PED_PORT, LED_PED_G_PIN);
				// 5. Delay for 5 seconds
				TIMER0_delay(5, DELAY_1S_OVF , CLK_1024_PRESCALER);
				TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
				// 6. Car Red LED is off
				LED_off(LED_CAR_PORT, LED_CAR_R_PIN);
				// 7. Blink Car Yellow Led for 5 seconds
				while (blinksCount < 5)
				{
					LED_blink(LED_CAR_PORT, LED_CAR_Y_PIN);
					TIMER0_delay(1, DELAY_1S_OVF , CLK_1024_PRESCALER);
					TIMER0_set_initial_value(TIMER_INITIAL_VALUE);
					blinksCount ++;
				}
				blinksCount = 0; // reset blinks count
				// 8. Car Yellow LED is off and Pedestrian Green LED is off
				LED_off(LED_CAR_PORT, LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT, LED_PED_G_PIN);
				break;	
				
			}
			// Restore normal traffic mode
			mode = NORMAL_TRAFFIC_MODE;
			global_interrupt_init();
			external_interrupt_init(INT0, FALLING_EDGE);	
			break;
			default: break;
		}
	}
}

ISR(EXT_INT_0) // ISR for external interrupt 0
{
	mode = PEDESTRIAN_TRAFFIC_MODE;
	APP_start();
}


