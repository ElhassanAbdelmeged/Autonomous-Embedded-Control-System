#include "servo.h"

#include <avr/io.h>





// Function to initialize PWM and servo settings
void Servo_Init() {
	// Set OC2/PD7 pin as output
	    DDRD |= (1 << PD7);

}

// Function to set the angle of the servo motor
void Servo_SetAngle(uint8_t angle) {
	PWM_Timer2_Start(angle);



}

