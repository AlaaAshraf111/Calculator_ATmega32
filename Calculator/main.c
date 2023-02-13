/*
 * main.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Alaa Ashraf
 */


#include "types.h"
#include "BIT_MATH.h"
#include<util/delay.h>

/*DIO*/
#include "DIO1_Interface.h"

///*LCD*/
#include "LCD_Interface.h"

/*KPD*/
#include "KPD_Interface.h"

/*CALCULATOR*/
#include"Cal_interface.h"



int main (void){
	/*For KPD*/
	DIO_vidSetPortDir(DIO_PORTC,0x0F);       //Initialization KeyPad PORT
	DIO_vidSetPortval(DIO_PORTC,0xF0);       //Enable PULL-UP registers for columns

	//Initialization PORT Pins
	DIO_vidSetPortDir(DIO_PORTA,PORT_OUT);             /*D0 to D7 connected to PORTD*/
	DIO_vidSetPinDir(DIO_PORTD,DIO_PIN6,DIO_OUTPUT);   /*RS pin of lcd connected to pin6 of PORTA */
	DIO_vidSetPinDir(DIO_PORTD,DIO_PIN7,DIO_OUTPUT);   /*E  pin of lcd connected to pin7 of PORTA*/

	/*Led pin*/
	DIO_vidSetPinDir(DIO_PORTD,DIO_PIN0,DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);

	LCD_voidInit();
	LCD_voidSendChar('A');

//	//u8 RES[4];
//	u8 var;
//
//	while(1){
//		var = KPD_u8GetPressedKey();
//			if(var != NOT_PRESSED)
//			{
//				LCD_voidSendChar(var);
////				if(var =='9'){
////				res=Cal_u16MultiOperation(var);}
////				if(var =='=')
////				{
////					LCD_vidTnttoStr(res);
////				}
//				Cal_u16MultiOperation(var);
//
//			}
//
//
//
//
//	}




	u8 x[5];
	u8 y[5];
	u16 NUM1=0;
	u16 NUM2=0;

	u8 *op=&x[0];
	u8 var;
	u8 operation=' ';
//					/*For Detecting Input Negative Number*/
//	u16 flag_neg_num1=0;
//	u16 flag_neg_num2=0;

	u16 result=0;
	u16 result_sum=0;
	u32 result_multi=0;
	s16 result_sub=0;
	f64 result_div=0.0;
	while(1){

		var = KPD_u8GetPressedKey();
			if(var != NOT_PRESSED)
			{
				LCD_voidSendChar(var);

				if ((NUM_0 <var) &&(var<= NUM_9)){

					*op =var;
					op++;
					DIO_vidSetPinVal(DIO_PORTD,DIO_PIN0,DIO_HIGH);
				}
				else if((var == '/')|(var == 'x')|(var == '+')|(var == '-')){
//					/*For Detecting Input Negative Number*/
//					if((var == '-')&&(NUM1==0))
//					{
//						flag_neg_num1=1;
//					}
//					else if((var == '-')&&(NUM2==0)&&(operation != ' '))
//					{
//						flag_neg_num2=1;
//					}
					op=&y[0];
					operation =var;
					DIO_vidSetPinVal(DIO_PORTD,DIO_PIN0,DIO_LOW);

				}

				switch(var){
				case '=':
//					/*For Detecting Input Negative Number*/
//					if(flag_neg_num1==1)
//					{
//
//					}else
//					{
//						NUM1=CAL_u16StrtoInt(x);
//					}
//
//					if(flag_neg_num2==1)
//					{
//
//					}else
//					{
//						NUM2=CAL_u16StrtoInt(y);
//					}

					NUM1=CAL_u16StrtoInt(x);
					NUM2=CAL_u16StrtoInt(y);

					switch(operation){
					case '+':
						result_sum=CAL_u16SumOperation(NUM1,NUM2);
						LCD_vidTnttoStr(result_sum);
						break;
					case '-':
						result_sub=CAL_s16SubOperation(NUM1,NUM2);
						LCD_vidTnttoStr(result_sub);
						break;
					case 'x':
						result_multi=CAL_u32MultiOperation(NUM1,NUM2);
						LCD_vidTnttoStr(result_multi);
						break;
					case '/':
						result_div=CAL_f64DivOperation(NUM1,NUM2);
						LCD_vidFloattoStr(result_div);
						break;
					}

					break;
				case 'c':
					LCD_voidSendCMD(LCD_CLR);
					NUM1=0;
					NUM2=0;
					result_sum=0;
					result_multi=0;
					result_sub=0;
					result_div=0.0;
					for(int i=0;i<5;i++){
						x[i]=0;
						y[i]=0;
					}
					op=&x[0];
					operation=' ';

//					flag_neg_num1=0;
//					flag_neg_num2=0;

					break;
				}

			}

	}



	return 0;
}
