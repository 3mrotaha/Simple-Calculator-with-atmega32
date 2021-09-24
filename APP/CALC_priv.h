/*
 * CALC_priv.h
 *
 *  Created on: Sep 23, 2021
 *      Author: amrmo
 */

#ifndef APP_CALC_PRIV_H_
#define APP_CALC_PRIV_H_

/* 1 - This Function Is Used to Read The Values Of KeyPad DIGIT BY DIGIT
 * and But These Digits In Array (Local_Au8KeyPadValues) Until The First Operator
 * Pressed By the User Then Saves This Operator In the Global Variable (Global_u8Operator)
 * And then Break Of the Loop.
 *
 *  2- Calculate the Number Entered By The User And Displayed On LCD (i.e. 1243 )
 *
 *  3- When The User Enters the Second Operand And Clicks = The function Breaks The Loop And
 *  Similarly Calculates The Second Operand Entered
 *
 **/
static inline void CALC_VoidReadingPrintNumber(s32 *Copy_u8Number);


/*This Function is Used To Return The Number Position I.e. 1, 10, 100, 1000, 10000*/
static s32 CALC_u16ReturnPowr(u8 Copy_u8Iterator);


#define 	NOT_ARITHMATIC_OPERATOR		Local_u8CharactersChecker != '+' &&\
										Local_u8CharactersChecker != 'x' &&\
										Local_u8CharactersChecker != '/' &&\
										Local_u8CharactersChecker != '-' &&\
										Local_u8CharactersChecker != '='\


#define 	ARITHMATIC_OPERATOR		    Local_u8CharactersChecker == '+' ||\
                                        Local_u8CharactersChecker == 'x' ||\
                                        Local_u8CharactersChecker == '/' ||\
                                        Local_u8CharactersChecker == '-' \

#define 	EQUAL_OPERATOR				Local_u8CharactersChecker == '='


#endif /* APP_CALC_PRIV_H_ */
