/*
 * DIO.c
 * Implementation file of DIO Driver
 * Created: 11/13/2022 4:17:16 AM
 *  Author: Haytham Metawie
 */

#include "DIO.h"

/* DIO's pin Data Direction Initialization Function */
EN_DIOErrorState_t DIO_init(uint8_t portName, uint8_t pinNumber, uint8_t dataDirection)
{
	EN_DIOErrorState_t DIO_initState  = DIO_OK;
	switch(portName)
	{
		case PORT_A:
			if(dataDirection == IN)
			{
				CLEAR_BIT(DDRA, pinNumber);
				if(!IS_CLEAR(DDRA, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else if (dataDirection == OUT)
			{
				SET_BIT(DDRA, pinNumber);
				if(!IS_SET(DDRA, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else break;
			
		case PORT_B:
			if(dataDirection == IN)
			{
				CLEAR_BIT(DDRB, pinNumber);
				if(!IS_CLEAR(DDRB, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			
			else if (dataDirection == OUT)
			{
				SET_BIT(DDRB, pinNumber);
				if(!IS_SET(DDRB, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else break;
		
		case PORT_C:
			if(dataDirection == IN) 
			{
				CLEAR_BIT(DDRC, pinNumber);
				if(!IS_CLEAR(DDRC, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else if (dataDirection == OUT) 
			{
				SET_BIT(DDRC, pinNumber);
				if(!IS_SET(DDRC, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else break;
		
		case PORT_D:
			if(dataDirection == IN)
			{
				CLEAR_BIT(DDRD, pinNumber);
				if(!IS_CLEAR(DDRD, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else if (dataDirection == OUT) 
			{
				SET_BIT(DDRD, pinNumber);
				if(!IS_SET(DDRD, pinNumber)) DIO_initState = DIO_ERROR;
				break;
			}
			else break;
		
		default: DIO_initState = DIO_ERROR; break;
	}
	return DIO_initState;
}

/* Read data from a DIO's pin Function */
EN_DIOErrorState_t DIO_read(uint8_t portName, uint8_t pinNumber, uint8_t* dataRead)
{
	EN_DIOErrorState_t DIO_ErrorState = DIO_OK;
	switch(portName)
	{
		case PORT_A: *dataRead = READ_BIT(PINA, pinNumber); break;
		case PORT_B: *dataRead = READ_BIT(PINB, pinNumber); break;
		case PORT_C: *dataRead = READ_BIT(PINC, pinNumber); break;
		case PORT_D: *dataRead = READ_BIT(PIND, pinNumber); break;
		default: DIO_ErrorState = DIO_ERROR; break;
	}
	return DIO_ErrorState;
}


/* Write data (LOW or HIGH) to a DIO's pin Function */
EN_DIOErrorState_t DIO_write(uint8_t portName, uint8_t pinNumber, uint8_t dataWrite)
{
	EN_DIOErrorState_t DIO_writeState = DIO_OK;
	switch(portName)
	{
		case PORT_A:
			if(dataWrite == LOW)
			{
				CLEAR_BIT(DDRA, pinNumber);
				if(!IS_CLEAR(DDRA, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else if (dataWrite == HIGH) 
			{
				SET_BIT(DDRA, pinNumber);
				if(!IS_SET(DDRA, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else {DIO_writeState = DIO_ERROR; break;}
		case PORT_B:
			if(dataWrite == LOW)
			{
				CLEAR_BIT(DDRB, pinNumber);
				if(!IS_CLEAR(DDRB, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else if (dataWrite == HIGH)
			{
				SET_BIT(DDRB, pinNumber);
				if(!IS_SET(DDRB, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else {DIO_writeState = DIO_ERROR; break;}
		
		case PORT_C:
			if(dataWrite == LOW)
			{
				CLEAR_BIT(DDRC, pinNumber);
				if(!IS_CLEAR(DDRC, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else if (dataWrite == HIGH)
			{
				SET_BIT(DDRC, pinNumber);
				if(!IS_SET(DDRC, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else {DIO_writeState = DIO_ERROR; break;}
		
		case PORT_D:
			if(dataWrite == LOW)
			{
				CLEAR_BIT(DDRD, pinNumber);
				if(!IS_CLEAR(DDRD, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else if (dataWrite == HIGH)
			{
				SET_BIT(DDRD, pinNumber);
				if(!IS_SET(DDRD, pinNumber)) DIO_writeState = DIO_ERROR;
				break;
			}
			else {DIO_writeState = DIO_ERROR; break;}
			
		default: DIO_writeState = DIO_ERROR; break;
	}
	return DIO_writeState;
}

/* Toggle data of a DIO's pin Function */
EN_DIOErrorState_t DIO_toggle(uint8_t portName, uint8_t pinNumber)
{
	EN_DIOErrorState_t DIO_toggleState = DIO_OK;
	switch(portName)
	{
		case PORT_A: TOGGLE_BIT(PORTA, pinNumber); break;
		case PORT_B: TOGGLE_BIT(PORTB, pinNumber); break;
		case PORT_C: TOGGLE_BIT(PORTC, pinNumber); break;
		case PORT_D: TOGGLE_BIT(PORTD, pinNumber); break;
		default: DIO_toggleState = DIO_ERROR; break;
	}
	return DIO_toggleState; // need to be checked before return
}