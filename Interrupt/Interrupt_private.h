/*
 * Interrupt_private.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Yasmeen
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_


#define ISR(vector,...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible))__VA_ARGS__;\
		void vector(void)


#define MCUCR	*((volatile u8*)(0x55))
#define MCUCSR	*((volatile u8*)(0x54))
#define GICR	*((volatile u8*)(0x5B))
#define GIFR 	*((volatile u8*)(0x5A))





#endif /* INTERRUPT_PRIVATE_H_ */
