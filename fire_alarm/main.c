/*
 * main.c
 *
 *  Created on: Mar 27, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "BUZ_interface.h"
#include "TSEN_interface.h"
#include "App_config.h"


int main (void)
{
	u16 local_u8AdcRead=0 ,local_u8OldAdcRead=1 ;
	u8 local_u8AdcStr[2],local_u8CountStr[2];
	u8	THR_COUNT= 0 , Old_THR_COUNT= 1 , THR_FLAG=0;
	DIO_voidInit();
	ADC_voidInit();
	CLC_voidInit();
	ADC_voidEnable();
while(1)
	{

		TSEN_u8ReadTSensr(0,&local_u8AdcRead);

	    if( local_u8AdcRead > (TSEN_u8THRSHOLD - TSEN_u8TOLERANCE) && THR_FLAG==0  )
	    {
	    	BUZ_voidBuzOn();
	    	THR_COUNT++;
	    	THR_FLAG=1 ;

	    	if(THR_COUNT>100)
	    		THR_COUNT=0 ;
	    }
	    else if( local_u8AdcRead < (TSEN_u8THRSHOLD - TSEN_u8TOLERANCE)  )
	    {
	    	BUZ_voidBuzOff();
	    	THR_FLAG=0;
	    }



	    if(THR_COUNT != Old_THR_COUNT || local_u8AdcRead != local_u8OldAdcRead)
	    {
	    	CLCD_u8WriteComand( CLC_u8CLRDISP);
	    	CLCD_u8WriteComand(CLC_u8STL);

	    	itoa(local_u8AdcRead,local_u8AdcStr,10);
	    	CLCD_u8WriteDataStr(local_u8AdcStr) ;

	    	CLCD_u8WriteComand(CLC_u8NEWL );

	    	itoa(THR_COUNT,local_u8CountStr,10);
	    	CLCD_u8WriteDataStr(local_u8CountStr);


	    	local_u8OldAdcRead = local_u8AdcRead ;
	    	Old_THR_COUNT=THR_COUNT ;
	    }
	}

return 0;
}


//if(local_u8AdcRead<10)
//{
//	itoa(local_u8AdcRead,local_u8AdcStr,10) ;
//	CLCD_u8WriteDataStr("0");
//    CLCD_u8WriteDataStr(local_u8AdcStr) ;
//
//}
//else
//{
//	itoa(local_u8AdcRead,local_u8AdcStr,10) ;
//	    CLCD_u8WriteDataStr(local_u8AdcStr) ;
//}
