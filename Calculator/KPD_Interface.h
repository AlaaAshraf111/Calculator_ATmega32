/*
 * KPD_Interface.h
 *
 *  Created on: Nov 26, 2022
 *      Author: Alaa Ashraf
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/*Driver Description: This driver manages 4x4 KPD, on a standalone port in DIO
 *Constraints:  1- Columns must be connected to the lower bits of DIO port
 *              2- Rows must be connected to the higher 4 bits of DIO port*/

/************************************************************************************/
/********************************Public MACROs***************************************/
/************************************************************************************/

#define NOT_PRESSED 0xFF



/************************************************************************************/
/********************************Public Functions***************************************/
/************************************************************************************/
u8 KPD_u8GetPressedKey(void);



#endif /* KPD_INTERFACE_H_ */


