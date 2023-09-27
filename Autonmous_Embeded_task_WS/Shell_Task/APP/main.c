#include"APP.h"
#include<avr/interrupt.h>
#include<util/delay.h>







int main (void)
{

	UART_ConfigType UART_Configuration={_8_bit,no_parity,_1_bit,9600};
	Timer1_ConfigType Timer1_Configuration={0,15625,F_CPU_1024,CTC_MODE}; //15625 for making an interrupt each second

	UART_init(&UART_Configuration);
	Timer1_init(&Timer1_Configuration);
	DcMotor_Init();
	LCD_init();
	Servo_Init();

	uint8 DataFlag=0;
	uint8 UART_Data[9];
	int Velocity=0;
	int Angle=0;

	DcMotor_State DcMotor_Direction=CW;  		//,F --->ANTI_CW ,  B---> CW

	LCD_displayStringRowColumn(0, 1, "Speed:000%");
	LCD_displayStringRowColumn(1, 1,"Direction:00");
	LCD_displayStringRowColumn(2, 1, "Time: 00:00:00");
//	Timer1_setCallBack(Timer_ISR_StopWatch);

while(1){



	do{
		//Timer1_setCallBack(Timer_ISR_StopWatch);
		UART_sendString("please put the Frame: ");
		UART_sendString("\r\n");
		UART_receiveString(UART_Data);

		Velocity	= stringSubstringToInteger(UART_Data,0,2);
		Angle		= stringSubstringToInteger(UART_Data,4,5);


		if(UART_Data[7]=='E')
		{


			if((Angle<=45)&&(Velocity<=100)){


				if((UART_Data[3]=='F')||UART_Data[3]=='B'){
					if((UART_Data[6]=='R')||UART_Data[6]=='L'){
							DataFlag=1;
					}

					else{
						UART_sendString("\r\n");
						UART_sendString("Wrong direction of the stepper motor. ");
						UART_sendString("\r\n");

					}





				}



				else{
					UART_sendString("\r\n");
					UART_sendString("Wrong direction of the DC motor . ");
					UART_sendString("\r\n");

				}





			}
			else{
				UART_sendString("\r\n");
				UART_sendString("You have Exceeds the limits of Velocity or Angle. ");
				UART_sendString("\r\n");

			}





		}


		else{
			UART_sendString("\r\n");
			UART_sendString("The Frame should End by 'E' . ");
			UART_sendString("\r\n");

		}

	}while(DataFlag!=1);



	if(UART_Data[3]=='F')
		{
		DcMotor_Direction=ANTI_CW;
		}

    else if(UART_Data[3]=='B'){
    	DcMotor_Direction=CW;

    }


//	UART_sendString("\r\n");
//	UART_sendString("To recieve another frame press #. ");
//	UART_sendString("\r\n");
//
//while(UART_recieveByte()!='#')
//{

	DcMotor_Rotate(DcMotor_Direction, Velocity);
	Servo_SetAngle(Angle);




	LCD_displayStringRowColumn(0, 1, "Speed:");


	if(Velocity==100){
	LCD_intgerToString(Velocity);
	}
	else if(Velocity<100){
		LCD_intgerToString(Velocity);
		LCD_displayString(" ");

	}



	if(UART_Data[6]=='R')
		{
		LCD_displayStringRowColumn(1, 1,"Direction:+");
		}

    else if(UART_Data[6]=='L'){
    	LCD_displayStringRowColumn(1, 1,"Direction:-");

    }



	LCD_intgerToString(Angle);
	//DisplytimeOnLCD();
	g_hour=0;
	g_min=0;
	g_sec=0;
	Timer1_setCallBack(Timer_ISR_StopWatch);

	UART_sendString("\r\n");
}

//LCD_displayStringRowColumn(2, 1, "Time: 00:00:00");
//}
/*Speed: 76% Direction: -18 ||
|| Time: 00:00:28 AM */









}