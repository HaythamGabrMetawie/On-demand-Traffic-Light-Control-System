/*
 * button.c
 *
 * Created: 11/14/2022 1:43:53 PM
 *  Author: Haytham Metawie
 */ 

#include "button.h"

/* Button Initialization Function */
EN_ButtonErrorState_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	EN_ButtonErrorState_t BUTTON_init_error = BUTTON_OK;
	EN_DIOErrorState_t DIO_state = DIO_init(buttonPort, buttonPin, IN);
	switch(DIO_state)
	{
		case DIO_OK: break;
		case DIO_ERROR: BUTTON_init_error = BUTTON_ERROR; break;
		default: BUTTON_init_error = BUTTON_ERROR; break;
	}
	
	return BUTTON_init_error;
}

/* Button State Read Function */
EN_ButtonErrorState_t BUTTON_readState(uint8_t buttonPort, uint8_t buttonPin, uint8_t* stateRead)
{
	EN_ButtonErrorState_t BUTTON_read_error = BUTTON_OK;

	EN_DIOErrorState_t DIO_state = DIO_OK;
	DIO_state = DIO_read(buttonPort, buttonPin, stateRead);
	switch(DIO_state)
	{
		case DIO_OK: break;
		case DIO_ERROR: BUTTON_read_error = BUTTON_ERROR; break;
		default: BUTTON_read_error = BUTTON_ERROR; break;
	}
	
	return BUTTON_read_error;
}