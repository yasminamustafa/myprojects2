/*
 * Timer_config.h
 *
 *  Created on: Apr 1, 2016
 *      Author: Yasmeen
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_




#define ISR(vector,...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible))__VA_ARGS__;\
		void vector(void)


#define TCCR0	*((volatile u8*)(0x53))
#define TCNT0	*((volatile u8*)(0x52))
#define TIMSK	*((volatile u8*)(0x59))
#define TIFR	*((volatile u8*)(0x58))
#define SFIOR	*((volatile u8*)(0x50))



#define fsys	4000000
#define Tsys	1/4000000

#define WGM  		WGM_Normal
#define prescaler	prescaler3




#endif /* TIMER_CONFIG_H_ */
