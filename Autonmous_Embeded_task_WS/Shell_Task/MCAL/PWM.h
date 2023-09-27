/*
 * PWM.h
 *
 *  Created on: Oct 9, 2022
 *      Author: dell
 */

#ifndef PWM_H_
#define PWM_H_

#include "../LIB/std_types.h"
#include "../LIB/common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
*/
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
