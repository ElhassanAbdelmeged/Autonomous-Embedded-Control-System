#include<avr/io.h>
#include"PWM.h"


void PWM_Timer0_Start(uint8 duty_cycle){


	TCNT0 = 0; //Set Timer Initial value

	OCR0  = duty_cycle*(2.55) ;   // Set Compare Value 255max

	SET_BIT(DDRB,PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}

void PWM_Timer2_Start(uint8 duty_cycle){

	TCNT2 = 0; //Set Timer Initial value

	OCR2=((float)duty_cycle / 180.0) * 255;              //duty_cycle*(1.8) ;   // Set Compare Value 255max

	SET_BIT(DDRB,PD7);

	TCCR2= (1<<WGM21)|(1<<WGM20)|(1<<COM21)|(1<<CS21);
}
