#ifndef SERVO_DRIVER_H
#define SERVO_DRIVER_H

#include <stdint.h>
#include "../MCAL/PWM.h"
void Servo_Init();
void Servo_SetAngle(uint8_t angle);

#endif // SERVO_DRIVER_H
