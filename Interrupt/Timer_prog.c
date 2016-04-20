/*
 * Timer_prog.c
 *
 *  Created on: Apr 1, 2016
 *      Author: Yasmeen
 */

#include "types.h"
#include "util.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "DIO_private.h"
#include "Timer_config.h"
#include "Timer_private.h"



static void (*Ptr_ISR)(void);




extern void Timer_init(void)
{
	/************************Enable global interrupt******************************/
			__asm__("SEI");


////////////////////////////////////////////////////////////////////////////////////////

//	ClrBit(TCCR0,4);  //com 00 compare op mode disconnected
//	ClrBit(TCCR0,5);  //com 01
//
///*************************** SET WGM TO NORMAL MODE WGM00 AND WGM01 *********************/
//
//#if 	WGM == WGM_Normal
//		ClrBit(TCCR0,3);
//		ClrBit(TCCR0,6);
//#elif	WGM == WGM_PWM
//		SetBit(TCCR0,6);
//		ClrBit(TCCR0,3);
//#elif 	WGM == WGM_CTC
//		SetBit(TCCR0,3);
//		ClrBit(TCCR0,6);
//#elif 	WGM == WGM_FastPWM
//		SetBit(TCCR0,6);
//		SetBit(TCCR0,3);
//
//#else
//#error "error"
//
//#endif

	/***************************** Set Prescaler ***********************************/
#if prescaler == prescaler0	// clk/8
	SetBit(TCCR0,1);
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,2);

#elif prescaler ==prescaler1 //clk/64
	SetBit(TCCR0,0);
	SetBit(TCCR0,1);
	ClrBit(TCCR0,2);

#elif prescaler == prescaler2 //clk/256
	SetBit(TCCR0,2);
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);

#elif prescaler == prescaler3 //clk/1024
	SetBit(TCCR0,2);
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
#else
#error "error"
#endif

/***************************** Enable timer interrupt *************************/
	SetBit(TIMSK,0);

	TCNT0=0;


}


extern void Read_TimerVal(u8 *CopyPtrtoVal)
{

	*CopyPtrtoVal=TCNT0;

}

extern void Set_ISR(void (*ptr2_ISR)(void))
{
	Ptr_ISR = ptr2_ISR;
}

ISR(__vector_11)  // ISR FOR INT0
{
	(Ptr_ISR)();
}


//extern u8 Read_ValReq(u16 CopyDelaytoVal)
//{
//
//u16 local_u8Val=CopyDelaytoVal*1000;
//
//u8 local_timer_count;
//
//local_timer_count =((local_u8Val*fsys)-1);
//
//return local_timer_count;
//
//}

//extern void Read_TimerOv(u8 *CopyPtrtoVal)
//{
//	u8 local_u8counter=0;
//
//
//	if(TIFR == 1)
//	{
//		local_u8counter++;
//		//SetBit(TIFR,0);   // set timer ov flag
//	}
//
//	*CopyPtrtoVal = local_u8counter;
//
//
//}






