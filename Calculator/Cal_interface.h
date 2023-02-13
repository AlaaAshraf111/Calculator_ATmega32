/*
 * Cal_interface.h
 *
 *  Created on: Dec 3, 2022
 *      Author: Alaa Ashraf
 */

#ifndef CAL_INTERFACE_H_
#define CAL_INTERFACE_H_

/********************************************************************************/
/************************************public macros*******************************/
#define DIV_BY_ZERO  0
#define NUM_0        48
#define NUM_1        49
#define NUM_2        50
#define NUM_3        51
#define NUM_4        52
#define NUM_5        53
#define NUM_6        54
#define NUM_7        55
#define NUM_8        56
#define NUM_9        57


/******************************************************************************/
/**********************************public functions****************************/


//void Cal_u16MultiOperation(u8 var);
//s16 Cal_s16DivOperation(s16 x, s16 y);
//s16 Cal_s16SumOperation(s16 x, s16 y);
//s16 Cal_s16SubOperation(s16 x, s16 y);


u32 CAL_u32MultiOperation(u16 NUM1 ,u16 NUM2);
u16 CAL_u16SumOperation(u16 NUM1 ,u16 NUM2);
s16 CAL_s16SubOperation(u16 NUM1 ,u16 NUM2);
f64 CAL_f64DivOperation(u16 NUM1 ,u16 NUM2);
void CAL_StrtoInt(u8 var, u8* op,u8* op2,u16 *NUM1 ,u16 *NUM2);

u16 CAL_u16StrtoInt(u8 *op);

#endif /* CAL_INTERFACE_H_ */
