/*
 * Interrupt_main.c
 *
 *  Created on: Mar 28, 2016
 *      Author: Yasmeen
 */

#include "types.h"
#include "util.h"
#include "DIO_interface.h"
#include "Interrupt_config.h"
#include "Interrupt_interface.h"
#include "Timer_interface.h"
#include "KEYSW_interface.h"
#include "delay.h"

void func0(void);
//void func1(void);
//void func2(void);


volatile static u8 flag1;
volatile static u8 flag2;
volatile static u8 flag3;


volatile static u8 var_y;
volatile static u8 var_r;
volatile static u8 var_g;

volatile static u8 local_u8counter;
void func(void);

int main(void)
{
	u8 temp=0;
	KEYSW_voidInit();
	Init_interrupt ();
	Timer_init();

	DIO_u8WritePinDir(26,DIO_u8INPUT);	//PIN INT0
	DIO_u8WritePinDir(6,DIO_u8OUTPUT); // PULSE GENERATOR
	DIO_u8WritePinDir(19,DIO_u8OUTPUT); // LED yellow
	DIO_u8WritePinDir(20,DIO_u8OUTPUT);	// LED red
	DIO_u8WritePinDir(21,DIO_u8OUTPUT); // LED green
	DIO_u8WritePinDir(BUTTON,DIO_u8INPUT); //switch




	enable_interrupt(INT0_pin,1);
//	enable_interrupt(INT1_pin,1);
//	enable_interrupt(INT2_pin,1);

	Set_ISR0(func0);
//	Set_ISR0(func1);
//	Set_ISR0(func2);
	Set_ISR(func);


while(1)
{
	temp = ReadKEYSW_u8Val();
	switch(temp)
	{
	case 1:
		var_y=1;
//			if(local_u8counter<50)
//			{
//			DIO_u8WritePinVal(19,0);
//			}

		break;
	case 2:
		var_r=1;
//			if(local_u8counter<50)
//			{
//			DIO_u8WritePinVal(20,0);
//			}
		break;
	case 3:
		var_g=1;
//		if(local_u8counter<50)
////		{
////		DIO_u8WritePinVal(21,0);
////		}
		break;

	default:

break;
	}

}


return 0;
}




void func0(void)
{

	if(var_y==1)
	{
	flag1=!flag1;
	DIO_u8WritePinVal(19,flag1);
	//var_y=0;
	}

	if(var_r==1)
		 	{
			flag2=!flag2;
			DIO_u8WritePinVal(20,flag2);
			//var_r=0;
			}

    if(var_g==1)
			{
			flag3=!flag3;
			DIO_u8WritePinVal(21,flag3);
			//var_g=0;
			}
}


void func(void)
{
	local_u8counter++;
}
