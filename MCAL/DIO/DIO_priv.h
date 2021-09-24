/*
 * DIO_priv.h
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

#define BIT_MASK_VALUE	1

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

#define INPUT 		0
#define OUTPUT 		1

#define HIGH		1
#define LOW			0

#define PULL_UP 	1
#define FLOAT		0

#define PORTA	*((u8 *) 0x3B)
#define PORTB   *((u8 *) 0x38)
#define PORTC   *((u8 *) 0X35)
#define PORTD   *((u8 *) 0X32)

#define DDRA    *((u8 *) 0x3A)
#define DDRB    *((u8 *) 0x37)
#define DDRC    *((u8 *) 0x34)
#define DDRD    *((u8 *) 0x31)

#define PINA    *((volatile u8 *) 0x39)
#define PINB    *((volatile u8 *) 0x36)
#define PINC    *((volatile u8 *) 0x33)
#define PIND    *((volatile u8 *) 0x30)

#define CONC_HELP(PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN1, PIN0)		0b##PIN7##PIN6##PIN5##PIN4##PIN3##PIN2##PIN1##PIN0
#define CONC(PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN1, PIN0)	CONC_HELP(PIN7, PIN6, PIN5, PIN4, PIN3, PIN2, PIN1, PIN0)


#endif /* MCAL_DIO_DIO_PRIV_H_ */
