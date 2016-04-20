/*
 * Interrupt_interface.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Yasmeen
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/

#define BUTTON    DIO_u8PIN16

/***********************INT0 IN MCUSR*****************************************/

#define INT0_Onchange	 SetBit(MCUCR,0);\
						 ClrBit(MCUCR,1);

#define INT0_Rising		SetBit(MCUCR,0);\
						SetBit(MCUCR,1);

#define INT0_falling	ClrBit(MCUCR,0);\
						SetBit(MCUCR,1);

#define INT0_Onlevel	 ClrBit(MCUCR,0);\
						 ClrBit(MCUCR,1);

/**********************INT1 IN MCUSR*******************************************/

#define INT1_Onchange	SetBit(MCUCR,3);\
						 ClrBit(MCUCR,4);

#define INT1_Rising		SetBit(MCUCR,3);\
						SetBit(MCUCR,4);

#define INT1_falling	SetBit(MCUCR,4);\
						 ClrBit(MCUCR,3);

#define INT1_Onlevel	 ClrBit(MCUCR,3);\
						 ClrBit(MCUCR,4);


/**********************INT2 IN MCUCSR ****************************************/

#define INT2_Rising		SetBit(MCUCSR,6);

#define INT2_falling	ClrBit(MCUCSR,6);



/*********************** Enable int1 *****************************************/

#define INT1_ENABLE     SetBit(GICR,7);

/*********************** Enable int2 *****************************************/

#define INT0_ENABLE     SetBit(GICR,6);

/*********************** Enable int0 ******************************************/

#define INT2_ENABLE		SetBit(GICR,5);


/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/

/***************initialize the interrupt *************************/
extern void Init_interrupt (void);

/*************** enable an external interrupt ************************/
extern u8 enable_interrupt(u8 Copy_u8Intpin, u8 CopyEnable);

/*************** disable an external interrupt ************************/

extern u8 disable_interrupt (u8 Copy_u8Intpin, u8 CopyEnable);

/**********************************************************************/

extern void Set_ISR0(void (Copy_ptrISR)(void));

/**********************************************************************/

extern void Set_ISR1(void (Copy_ptrISR)(void));
/**********************************************************************/

extern void Set_ISR2(void (Copy_ptrISR)(void));
#endif /* INTERRUPT_INTERFACE_H_ */
