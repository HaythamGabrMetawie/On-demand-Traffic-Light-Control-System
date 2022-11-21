/*
 * bit_manipulation.h
 * Header file contains macros for bit manipulation on pins.
 * Created: 11/13/2022 3:50:29 AM
 *  Author: Haytham Metawie
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

/* Clear the bit at a certain position in a register */
#define CLEAR_BIT(registerAddress, pos) registerAddress &= ~(1<<pos)

/* Set the bit at a certain position in a register */
#define SET_BIT(registerAddress, pos) registerAddress |= (1<<pos)

/* Toggle the bit at a certain position in a register */
#define TOGGLE_BIT(registerAddress, pos) registerAddress ^= (1<<pos)

/* Read the value of a bit at a certain position in a register */
#define READ_BIT(registerAddress, pos) ((registerAddress &(1<<pos))>>pos)

/* Check for a bit at position is set in a register */
#define IS_SET(registerAddress, pos) (registerAddress & (1<<pos))

/* Check for a bit at position is cleared in a register */
#define IS_CLEAR(registerAddress, pos) (!(registerAddress & (1<<pos)))




#endif /* BIT_MANIPULATION_H_ */