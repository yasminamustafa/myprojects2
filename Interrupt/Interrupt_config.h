/*
 * Interrupt_config.h
 *
 *  Created on: Mar 28, 2016
 *      Author: Yasmeen
 */

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_



/*************************Edge of interrupt request **************************/
#define INT0_REQUEST INT0_Rising

#define INT1_REQUEST  INT1_Onchange

#define INT2_REQUEST  INT2_Rising

#define INT0_pin	DIO_u8PIN26
#define INT1_pin	DIO_u8PIN27
#define INT2_pin	DIO_u8PIN10

#define PRESSED  1
#define RELEASED 0

#endif /* INTERRUPT_CONFIG_H_ */
