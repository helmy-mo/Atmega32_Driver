/*
 * bit_math.h
 *
 *  Created on: Feb 25, 2020
 *      Author: helmy_
 */

#ifndef DIO_BIT_MATH_H_
#define DIO_BIT_MATH_H_

#define SET_BIT(Port_Id,pin_id)        (Port_Id) |= (1<<(pin_id))
#define CLEAR_BIT(Port_Id,pin_id)     (Port_Id) &= ~(1<<(pin_id))
#define TOGGLE_BIT(Port_Id,pin_id)     (Port_Id)^= (1<<(pin_id))
#define GET_BIT(Port_Id,pin_id)       (((Port_Id)>>(pin_id)) & 0x01)
#define TOG_BIT(PORT,BIT)	(PORT^=(1<<BIT))



#endif /* DIO_BIT_MATH_H_ */
