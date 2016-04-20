/*
 * delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: Home
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "Delay_config.h"

#define DELAY_MS(Copy_U64DelayMs)   do{ u32 Local_U32LoopCounter;  u64 Local_U64DelayCounter; \
                                    for( Local_U64DelayCounter = Copy_U64DelayMs/4;  Local_U64DelayCounter > 0;  Local_U64DelayCounter-- ){ \
                                    for ( Local_U32LoopCounter = ((Delay_SysClock * 1000)/8);  Local_U32LoopCounter > 0;  Local_U32LoopCounter-- ){ \
                                   __asm__("NOP"); }  \
                                  } \
                                  }while(0)

#endif /* DELAY_H_ */
