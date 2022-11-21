/*
 * LED.c
 * Implementation file of DIO Driver
 * Created: 11/13/2022 5:46:14 AM
 *  Author: Haytham Metawie
 */ 

#include "LED.h"

/* LED Initialization Function */
EN_LEDErrorState_t LED_init(uint8_t LEDPortName, uint8_t LEDPinNumber)
{
	EN_LEDErrorState_t LED_initState = LED_OK;
	EN_DIOErrorState_t DIO_initState  = DIO_OK;
	DIO_initState = DIO_init(LEDPortName, LEDPinNumber, OUT);
	switch(DIO_initState)
	{
		case DIO_OK: LED_initState = LED_OK; break;
		case DIO_ERROR: LED_initState = LED_ERROR; break;
		default: LED_initState = LED_ERROR; break;
	}
	return LED_initState;
}

/* Turn LED on Function */
EN_LEDErrorState_t LED_on(uint8_t LEDPortName, uint8_t LEDPinNumber)
{
	EN_LEDErrorState_t LED_initState = LED_OK;
	EN_DIOErrorState_t DIO_initState  = DIO_OK;
	DIO_initState = DIO_write(LEDPortName, LEDPinNumber, HIGH);
	switch(DIO_initState)
	{
		case DIO_OK: LED_initState = LED_OK; break;
		case DIO_ERROR: LED_initState = LED_ERROR; break;
		default: LED_initState = LED_ERROR; break;
	}
	return LED_initState;
	
}

/* Turn LED off Function*/
EN_LEDErrorState_t LED_off(uint8_t LEDPortName, uint8_t LEDPinNumber)
{
	EN_LEDErrorState_t LED_initState = LED_OK;
	EN_DIOErrorState_t DIO_initState  = DIO_OK;
	DIO_initState = DIO_write(LEDPortName, LEDPinNumber, LOW);
	switch(DIO_initState)
	{
		case DIO_OK: LED_initState = LED_OK; break;
		case DIO_ERROR: LED_initState = LED_ERROR; break;
		default: LED_initState = LED_ERROR; break;
	}
	return LED_initState;
}

/* Toggle LED's State */
EN_LEDErrorState_t LED_toggle(uint8_t LEDPortName, uint8_t LEDPinNumber)
{
	EN_LEDErrorState_t LED_initState = LED_OK;
	EN_DIOErrorState_t DIO_initState  = DIO_OK;
	DIO_initState = DIO_toggle(LEDPortName, LEDPinNumber);
	switch(DIO_initState)
	{
		case DIO_OK: LED_initState = LED_OK; break;
		case DIO_ERROR: LED_initState = LED_ERROR; break;
		default: LED_initState = LED_ERROR; break;
	}
	return LED_initState;
}

/* LED Blink Function*/
EN_LEDErrorState_t LED_blink(uint8_t LEDPortName, uint8_t LEDPinNumber)
{
	return LED_toggle(LEDPortName, LEDPinNumber);
}

