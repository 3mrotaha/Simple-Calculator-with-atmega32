/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define DIO_u8PORTA			0
#define DIO_u8PORTB			1
#define DIO_u8PORTC			2
#define DIO_u8PORTD			3

#define DIO_u8PIN0			0
#define DIO_u8PIN1			1
#define DIO_u8PIN2			2
#define DIO_u8PIN3			3
#define DIO_u8PIN4			4
#define DIO_u8PIN5			5
#define DIO_u8PIN6			6
#define DIO_u8PIN7			7

/* don't change these values */

#define DIO_u8INPUT 	0
#define DIO_u8OUTPUT 	1

#define DIO_u8HIGH		1
#define DIO_u8LOW		0

#define DIO_u8PULL_UP 	1
#define DIO_u8FLOAT		0

ES_t DIO_enuInit(void);

ES_t DIO_enuSetPortDir(u8 Copy_PortID, u8 Copy_PortDir);

ES_t DIO_enuSetPortValue(u8 Copy_PortID, u8 Copy_PortValue);

ES_t DIO_enuGetPortValue(u8 Copy_PortID, u8 *Copy_PortVal);

ES_t DIO_enuTogPortValue(u8 Copy_PortID);

ES_t DIO_enuSetPinDir(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PortDir);

ES_t DIO_enuSetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PortValue);

ES_t DIO_enuGetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 *Copy_PortVal);

ES_t DIO_enuTogPinValue(u8 Copy_PortID, u8 Copy_PinID);

#endif /* MCAL_DIO_DIO_INT_H_ */
