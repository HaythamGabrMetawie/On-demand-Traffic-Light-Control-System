/*
 * button.h
 *
 * Created: 11/14/2022 1:40:12 PM
 *  Author: Haytham Metawie
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCUAL/DIO_Driver/DIO.h"
#include "../../Utilities/datatypes.h"

/* Button Connection - Port Name and Pin */
#define BUTTON_PORT		PORT_D
#define BUTTON_PIN		PIN2

/* Button State Levels */
#define BUTTON_PRESSED		1
#define BUTTON_NOT_PRESSED	0

/* Button Error State Enum Definition */
typedef enum EN_ButtonErrorState_t
{
	BUTTON_OK, BUTTON_ERROR
}EN_ButtonErrorState_t;

/* Button Initialization Function */
EN_ButtonErrorState_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);

/* Button State Read Function */
EN_ButtonErrorState_t BUTTON_readState(uint8_t buttonPort, uint8_t buttonPin, uint8_t *stateRead);


#endif /* BUTTON_H_ */