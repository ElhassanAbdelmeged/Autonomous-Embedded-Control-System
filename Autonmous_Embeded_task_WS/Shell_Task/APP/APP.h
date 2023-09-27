#ifndef APP_H_
#define APP_H_


#include "avr/io.h"

#include "../MCAL/uart.h "
#include "../MCAL/timer.h "
#include "../MCAL/gpio.h "


#include "../HAL/motor.h "
#include "../HAL/lcd.h "
#include "../HAL/servo.h "

#include "../LIB/std_types.h"


extern uint8 g_sec;
extern uint8 g_min;
extern uint8 g_hour;




int stringSubstringToInteger( char *str, int start, int end);
void Timer_ISR_StopWatch(void);
#endif /* APP_H_ */