/*
 * KEYSW_interface.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Yasmeen
 */




#ifndef KEYSW_INTERFACE_H_
#define KEYSW_INTERFACE_H_

/*****************************************************************/
/***********************Public Definitions************************/
/*****************************************************************/




#define 	stop 		9
#define 	changedir	7


/*****************************************************************/
/***********************Public Functions**************************/
/*****************************************************************/

/*Comment!= Read the switch states if it's high or low */
//extern u8 KEYSW_u8CheckSw(u8 Copy_U8SwIdx, u8* Copy_U8PtrVal);

/*Comment!= Initialize the switch module */
extern void KEYSW_voidInit();

/*Comment!= Write on switch */
extern u8 ReadKEYSW_u8Val(void);

#endif /* KEYSW_INTERFACE_H_ */
