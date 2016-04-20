/*
 * KEYSW_prog.c
 *
 *  Created on: Mar 3, 2016
 *      Author: Yasmeen
 */


#include "types.h"
#include "util.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "KEYSW_interface.h"
#include "DIO_private.h"
#include "KEYSW_config.h"
#include "KEYSW_private.h"



u8 pin_input[]={DIO_u8PIN7,DIO_u8PIN6,DIO_u8PIN5,DIO_u8PIN4};
u8 pin_output[]={DIO_u8PIN3,DIO_u8PIN2,DIO_u8PIN1,DIO_u8PIN0};


extern void KEYSW_voidInit()
{
	u8 i;
	for(i=0;i<4;i++)
	{
		DIO_u8WritePinDir(pin_input[i],DIO_u8INPUT);
	}

	for(i=0;i<4;i++)
		{
			DIO_u8WritePinDir(pin_output[i],DIO_u8OUTPUT);
		}
}





extern u8 ReadKEYSW_u8Val(void)

{
	u8 row;
	u8 temp;
	u8 var=0;
	u8 col;

for(row=0;row<4;row++)

{
	DIO_u8WritePinVal(pin_output[row],1);

	for(col=0;col<4;col++)
	{
		DIO_u8ReadPinVal(pin_input[col],&temp);
		if(temp==1)
		{
			  var=(row*4)+col+1;
			  break;
		}

	}
	DIO_u8WritePinVal(pin_output[row],0);
}
	return var;
}









