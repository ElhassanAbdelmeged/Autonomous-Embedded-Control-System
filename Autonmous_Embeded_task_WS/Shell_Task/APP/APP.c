#include"APP.h"



int stringSubstringToInteger( char *str, int start, int end) {
    // Calculate the length of the substring
    int length = end - start + 1;

    // Create a temporary buffer to hold the substring
    char subStr[length + 1]; // +1 for the null terminator

    // Copy the substring into the temporary buffer
    for (int i = 0; i < length; i++) {
        subStr[i] = str[start + i];
    }
    subStr[length] = '\0'; // Null-terminate the substring

    // Convert the substring to an integer
    int result = atoi(subStr);

    return result;
}

uint8 g_sec=0;
uint8 g_min=0;
uint8 g_hour=0;



void Timer_ISR_StopWatch(void)
{
	if(g_sec==60)
	{
		g_sec=0;
			LCD_moveCursor(2, 13);
			LCD_intgerToString(g_sec/10);//13..14
			LCD_moveCursor(2, 14);
			LCD_intgerToString(g_sec%10);//13..14


		if(g_min==60)
		{


			g_min=0;
			LCD_moveCursor(2, 10);
			LCD_intgerToString(g_min/10);//10..11
			LCD_moveCursor(2, 11);
			LCD_intgerToString(g_min%10);//10..11



			if(g_hour==24)
			{
				g_hour=0;
				LCD_moveCursor(2, 7);
				LCD_intgerToString(g_hour/10);//7..8
				LCD_moveCursor(2, 8);
				LCD_intgerToString(g_hour%10);//7..8



			}
			else
			{
				g_hour++;
				LCD_moveCursor(2, 7);
				LCD_intgerToString(g_hour/10);//7..8
				LCD_moveCursor(2, 8);
				LCD_intgerToString(g_hour%10);//7..8





			}

		}
		else{
			g_min++;
			LCD_moveCursor(2, 10);
			LCD_intgerToString(g_min/10);//10..11
			LCD_moveCursor(2, 11);
			LCD_intgerToString(g_min%10);//13..14


		}
	}

	else{

		g_sec++;
		LCD_moveCursor(2, 13);
		LCD_intgerToString(g_sec/10);//13..14
		LCD_moveCursor(2, 14);
		LCD_intgerToString(g_sec%10);//13..14


	}
}



void DisplytimeOnLCD(void)
{



//
//	LCD_moveCursor(2, 13);
//	LCD_displayCharacter(g_sec/10);//13..14
//	LCD_moveCursor(2, 14);
//	LCD_displayCharacter(g_sec%10);//13..14
//	g_min=00;//10..11
//	 g_hour=00; //7..8
//
//




	//}
	/*Speed: 76% Direction: -18 ||
	|| Time: 00:00:28 AM */


}
