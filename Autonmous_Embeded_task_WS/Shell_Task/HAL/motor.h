/*
 * motor.h
 *
 *  Created on: Oct 9, 2022
 *      Author: dell
 */

#ifndef MOTOR_H_
#define MOTOR_H_



#include "../LIB/std_types.h"
#include "../LIB/common_macros.h" /* To use the macros like SET_BIT */
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
typedef enum{CW,ANTI_CW,STOP}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
