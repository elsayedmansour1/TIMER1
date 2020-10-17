/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: elsay
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_INT.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/Global Interrupt/GIE_INT.h"
#include "../MCAL/TIMER1/TIMER1_Int.h"

void timer1_func(void);
int main(void)
{
	DIO_VidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
		TMR1_OF_SetCallBack(timer1_func);
		TIMER1_INIT();
		TIMER1_OverFlow_Interrupt_Enable();
		GIE_Vid_Enable();
		while(1)
			{

			}
	return 0;
}

void timer1_func(void)
{
	static u16 counter=0;
	counter++;

	if(counter==2)
	{
		//DIO_VidSetPinValue(DIO_PORTA, PIN0, HIGH);
		DIO_u8TogglePinValue(DIO_PORTA, PIN0);
		counter=0;
	}
}
