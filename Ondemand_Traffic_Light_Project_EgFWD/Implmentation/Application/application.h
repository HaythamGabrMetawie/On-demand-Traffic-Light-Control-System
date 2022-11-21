/*
 * application.h
 *
 * Created: 11/14/2022 9:01:10 PM
 *  Author: Haytham Metawie
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../Utilities/datatypes.h"
#include "../MCUAL/Timer_Driver/Timer.h"
#include "../ECUAL/LED_Driver/LED.h"
#include "../ECUAL/Button_Driver/button.h"


/* Traffic Operational Modes Definition*/
#define NORMAL_TRAFFIC_MODE		0
#define PEDESTRIAN_TRAFFIC_MODE	1

#define	DELAY_1S_OVF	4	// count of overflows for one second delay w/ 1024 prescaler
//#define	TIMER_INITIAL_VALUE	11
#define	TIMER_INITIAL_VALUE	12

/* STATES DEFINITION */
#define RED		1
#define YELLOW	2
#define GREEN	3

void APP_init(void);
void APP_start(void);

#endif /* APPLICATION_H_ */