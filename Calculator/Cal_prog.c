/*
 * Cal_prog.c
 *
 *  Created on: Dec 3, 2022
 *      Author: Alaa Ashraf
 */

#include "types.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include <stdio.h>

//#define F_CPU 8000000UL
#include <avr/delay.h>
#include "DIO1_interface.h"
//#include "DIO_private.h"
#include "KPD_Interface.h"

#include "Cal_interface.h"
#include "Cal_private.h"

#include "LCD_Interface.h"

/****************************************************************************************/
/****************************implementation functions************************************/

u16 CAL_u16StrtoInt(u8 *a){
	u16 Num;
	Num =atoi(a);
//	for (int i=0 ;i<3 ; i++){
//			//while(op[i++] != 0){
//	//	if(*(a+i)=='\0'){ break;}
//
//		if((NUM_0 <*(a+i)) &&(*(a+i)<= NUM_9)){
//				Num =((Num) *10) + (*(a+i) -'0');
//				//LCD_vidTnttoStr(Num);
//				//a++;
//				//LCD_voidSendChar('d');
//			}else{break;}
//	}
	//LCD_vidTnttoStr(Num);
			return Num;

}




u32 CAL_u32MultiOperation(u16 NUM1 ,u16 NUM2){

	u32 res;
	res = NUM1 *NUM2;
	return res;
}
u16 CAL_u16SumOperation(u16 NUM1 ,u16 NUM2){

	u16 res;
	res = NUM1 + NUM2;
	//LCD_vidTnttoStr(res);
	return res;
}
s16 CAL_s16SubOperation(u16 NUM1 ,u16 NUM2){

	s16 res;
	res = NUM1 - NUM2;
	//LCD_vidTnttoStr(res);
	return res;
}

f64 CAL_f64DivOperation(u16 NUM1 ,u16 NUM2){

	f64 res;
	if(NUM2 == 0){
		LCD_voidwriteStr("ERORR !");
	}else{
		res = (f64)NUM1/(f64)NUM2;
	}

	//LCD_vidTnttoStr(res);
	return res;
}








