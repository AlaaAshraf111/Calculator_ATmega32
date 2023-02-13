/*
 * KPD_Prog.c
 *
 *  Created on: Nov 26, 2022
 *      Author: Alaa Ashraf
 */


#include <avr/delay.h>
#include "types.h"
#include "BIT_MATH.h"

/* KPD */
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

/* DIO */
#include"DIO1_Interface.h"


/*KeyPad matrix array*/

static const u8 KPD_au8Array [4][4] =
{
		{'7','8','9','/'},
		{'4','5','6','x'},
		{'1','2','3','-'},
		{'c','0','=','+'}
};


u8 KPD_u8GetPressedKey(void){
	u8 u8SwVal = NOT_PRESSED;
	u8 u8Col;
	u8 u8Row;

	for (u8Col =COl_BGN; u8Col < COl_NUM; u8Col++)
	{
		/*Clear Column Pin*/
		DIO_vidSetPinVal(KPD_PORT,u8Col,DIO_LOW);

		for(u8Row = ROW_BGN; u8Row<ROW_BGN+ROW_NUM; u8Row++)
		{
			/*Get Row Pin Status*/
			/*Check if any Key is Pressed (detecting if any row is zero)*/

			if(DIO_u8GetPinVal(KPD_PORT, u8Row)==DIO_LOW)
			{
				u8SwVal = KPD_au8Array[u8Row-4][u8Col];

				/*Handling the Bouncing generated from pressing the key*/
				_delay_ms(10);
				while(DIO_u8GetPinVal(KPD_PORT, u8Row)==DIO_LOW);
			}
		}
		DIO_vidSetPinVal(KPD_PORT,u8Col,DIO_HIGH);
	}
	return u8SwVal;
}




