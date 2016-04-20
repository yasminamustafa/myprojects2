/*
 * Timer_interface.h
 *
 *  Created on: Apr 1, 2016
 *      Author: Yasmeen
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/







/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/


/********************** to intialize timer ************************/
extern void Timer_init(void);

/********************** read value of timer ***********************/
extern void Read_TimerVal(u8 *CopyPtrtoVal);

/********************** read timer overflow ***********************/
extern void Read_TimerOv(u8 *CopyPtrtoVal);

/********************** count to specific delay *******************/
extern u8 Read_ValReq(u16 CopyDelaytoVal);

/*******************************************************************/
extern void Set_ISR(void (*ptr2_ISR)(void));




#endif /* TIMER_INTERFACE_H_ */
