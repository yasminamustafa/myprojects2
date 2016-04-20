/*
 * Interrupt_prog.c
 *
 *  Created on: Mar 29, 2016
 *      Author: Yasmeen
 */


#include "types.h"
#include "util.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "Interrupt_interface.h"
#include "DIO_private.h"
#include "Interrupt_config.h"
#include "Interrupt_private.h"


static void (*Ptr_ISR0)(void);
static void (*Ptr_ISR1)(void);
static void (*Ptr_ISR2)(void);

extern void Init_interrupt (void)
{

	/************************Enable global interrupt******************************/
			__asm__("SEI");

		//	ClrBit(GICR,6); // disable int0
		//	ClrBit(GICR,7); // disable int1
		//	ClrBit(GICR,5); // disable int2
	/************************Set Int0,int1 on change *****************************/

			INT0_REQUEST   // int0 on change
			INT1_REQUEST	//int 1 on change
			INT2_REQUEST	// int2 on rising
	/*************************Set interrupt pins as input ************************/

			DIO_u8WritePinDir(INT0_pin,DIO_u8INPUT);
			DIO_u8WritePinDir(INT1_pin,DIO_u8INPUT);
			DIO_u8WritePinDir(INT2_pin,DIO_u8INPUT); // need to know pin int2


}



extern u8 enable_interrupt (u8 Copy_u8Intpin, u8 CopyEnable)
{
	u8 local_u8status;


	if(CopyEnable==1)
	{
		switch(Copy_u8Intpin)
		{
		case INT0_pin:
			SetBit(GICR,6);
			break;
		case INT1_pin:
			SetBit(GICR,7);
			break;
		case INT2_pin:
			SetBit(GICR,5);
			break;

		default:
			local_u8status=error;
		}

	local_u8status=okay;
	}

	else
	{
	local_u8status=error;
	}
return local_u8status;
}



extern u8 disable_interrupt (u8 Copy_u8Intpin, u8 CopyEnable)
{
	u8 local_u8status;


		if(CopyEnable==0)
		{
			switch(Copy_u8Intpin)
			{
			case 0:
				ClrBit(GICR,6);
				break;
			case 1:
				ClrBit(GICR,7);
				break;
			case 2:
				ClrBit(GICR,5);
				break;

			default:
				local_u8status=error;
			}

			local_u8status=okay;
		}
		else
		{
		local_u8status=error;
		}
	return local_u8status;

}

extern void Set_ISR0(void (*ptr2_ISR)(void))
{
	Ptr_ISR0 = ptr2_ISR;
}

ISR(__vector_1)  // ISR FOR INT0
{
	(Ptr_ISR0)();
}

extern void Set_ISR1(void (*ptr2_ISR)(void))
{
	Ptr_ISR1 = ptr2_ISR;
}

ISR(__vector_2)  // ISR FOR INT0
{
	(Ptr_ISR1)();
}
extern void Set_ISR2(void (*ptr2_ISR)(void))
{
	Ptr_ISR2 = ptr2_ISR;
}

ISR(__vector_3)  // ISR FOR INT0
{
	(Ptr_ISR2)();
}


