/*
 * LED.h
 * Header file of LED Driver; contains all definition needed and functions prototypes for LED.c
 * Created: 11/13/2022 4:43:08 AM
 *  Author: Haytham Metawie
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCUAL/DIO_Driver/DIO.h"

/* Ports and Pins -- Car Lights */
#define LED_CAR_PORT PORT_A
#define LED_CAR_G_PIN PIN0
#define LED_CAR_Y_PIN PIN1
#define LED_CAR_R_PIN PIN2

/* Ports and Pins -- Pedestrians Lights */
#define LED_PED_PORT PORT_B
#define LED_PED_G_PIN PIN0
#define LED_PED_Y_PIN PIN1
#define LED_PED_R_PIN PIN2

typedef enum EN_LEDErrorState_t
{ 
	LED_OK, LED_ERROR
}EN_LEDErrorState_t;

/* LED Initialization Function */
EN_LEDErrorState_t LED_init(uint8_t LEDPortName, uint8_t LEDPinNumber);

/* Turn LED on Function */
EN_LEDErrorState_t LED_on(uint8_t LEDPortName, uint8_t LEDPinNumber);

/* Turn LED off Function*/
EN_LEDErrorState_t LED_off(uint8_t LEDPortName, uint8_t LEDPinNumber);

/* Toggle LED's State */
EN_LEDErrorState_t LED_toggle(uint8_t LEDPortName, uint8_t LEDPinNumber);

/* LED Blink Function*/
EN_LEDErrorState_t LED_blink(uint8_t LEDPortName, uint8_t LEDPinNumber);



#endif /* LED_H_ */