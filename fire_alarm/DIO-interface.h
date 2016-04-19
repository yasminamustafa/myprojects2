/*
 * DIO-interface.h
 *
 *  Created on: Jan 27, 2016
 *      Author: m.mamdooh
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/***************************************************************/
/*************PUBLIC DEFINITIONS*********************************/
/*************************************************************/

#include "type.h"

/*COMMENT!:PIN INDEX VALUES*/
#define DIO_u8PIN0     0
#define DIO_u8PIN1     1
#define DIO_u8PIN2     2
#define DIO_u8PIN3     3
#define DIO_u8PIN4     4
#define DIO_u8PIN5     5
#define DIO_u8PIN6     6
#define DIO_u8PIN7     7
#define DIO_u8PIN8     8
#define DIO_u8PIN9     9
#define DIO_u8PIN10    10
#define DIO_u8PIN11    11
#define DIO_u8PIN12    12
#define DIO_u8PIN13    13
#define DIO_u8PIN14    14
#define DIO_u8PIN15    15
#define DIO_u8PIN16    16
#define DIO_u8PIN17    17
#define DIO_u8PIN18    18
#define DIO_u8PIN19    19
#define DIO_u8PIN20    20
#define DIO_u8PIN21    21
#define DIO_u8PIN22    22
#define DIO_u8PIN23    23
#define DIO_u8PIN24    24
#define DIO_u8PIN25    25
#define DIO_u8PIN26    26
#define DIO_u8PIN27    27
#define DIO_u8PIN28    28
#define DIO_u8PIN29    29
#define DIO_u8PIN30    30
#define DIO_u8PIN31    31

/*COMMENT!:PORT INDEX VALUES*/
#define DIO_u8PORT0     0
#define DIO_u8PORT1     1
#define DIO_u8PORT2     2
#define DIO_u8PORT3     3

/*COMMENT!:PORT MAX INDEX */
#define DIO_u8PORTMAXIDX  3


/*COMMENT!:NUMBER OF PORTS -1 */
#define DIO_u8PINMAXIDX 31


/*COMMENT!:DIGITAL I/O VALUE*/
#define DIO_u8HIGH 1
#define DIO_u8LOW  0

/*COMMENT!:DIGITAL I/O DIRECTION*/
#define DIO_u8INPUT    0
#define DIO_u8OUTPUT   1


/***************************************************************/
/*************PUBLIC FUNCTIONS*********************************/
/*************************************************************/

/*COMMENT!: READ PIN VALUE*/
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToval);

/*COMMENT!: WRITE PIN VALUE*/
extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8Pinval);

/*COMMENT!: READ PORT VALUE*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrToval);

/*COMMENT!: WRITE PORT VALUE*/
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8Portval);

/*COMMENT!: WRITE PIN DIRECTION*/
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir);

/*COMMENT!: WRITE Port DIRECTION*/
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir);

/*COMMENT!: Read PIN DIRECTION*/
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8 * Copy_u8PtrToDir);

/*COMMENT!: Read Port DIRECTION*/
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8 *Copy_u8PtrToDir);

/*COMMENT!: INTIALIZATION*/
extern void  DIO_voidInit(void);


#endif /* DIO_INTERFACE_H_ */
