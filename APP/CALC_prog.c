/*
 * CALC_prog.c
 *
 *  Created on: Sep 23, 2021
 *      Author: amrmo
 */


#include "../LIB/std_Types.h"
#include "../LIB/ErrorStates.h"
#include "util/delay.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/KPAD/KPAD_priv.h"
#include "../HAL/KPAD/KPAD_int.h"

#include "../HAL/LCD/LCD_int.h"

#include "CALC_priv.h"
#include "CALC_config.h"

 /*Global Variable That Receives the +, -, x, / operators */
u8 Global_u8Operator = 0;

/*Global Variable that Receives the = Operator */
u8 Global_u8EqualOperator = 0;


/*This Function is Used To Initialize the Calculator Components LCD and KEYPAD
 * its Also Intialize the Cursor to Write in the First Line
 */
ES_t CALC_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	LCD_enuInit();
	KPAD_enuInit();
	LCD_enuSendCommand(0x80);
	return Local_enuErrorState;
}

/*This Function Is Used To Read The Number Pressed By the User*/
ES_t CALC_enuReadNumber(s32 *Copy_u32Num){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u32Num != NULL){

		CALC_VoidReadingPrintNumber(Copy_u32Num);

	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


/*This Function Is Used To Display The Result Of the Operation Detected
 * By the User +, -, x, / and displays invalid Input if the Operation
 * Is Not Correctly Typed
 *
 * The Result Is Diplayed In the Left Of the Second Line
 * */
ES_t CALC_enuDisplayResult(s32 Copy_u32FirstNum, s32 Copy_u32SecondNum){
	ES_t Local_enuErrorState = ES_NOK;
	f32 Local_f32ResultOfOperation = 0;
	if(Global_u8EqualOperator == '='){
		LCD_enuSendCommand(0xC0);
		switch(Global_u8Operator){
			Local_enuErrorState = ES_OK;
		case '+':
				Local_f32ResultOfOperation = Copy_u32FirstNum + Copy_u32SecondNum;
				 LCD_enuDisplayIntegerNum((s32)Local_f32ResultOfOperation);
			break;
		case '-':
				Local_f32ResultOfOperation = Copy_u32FirstNum - Copy_u32SecondNum;
				 LCD_enuDisplayIntegerNum((s32)Local_f32ResultOfOperation);
			break;
		case 'x':
				Local_f32ResultOfOperation = Copy_u32FirstNum * Copy_u32SecondNum;
				 LCD_enuDisplayIntegerNum((s32)Local_f32ResultOfOperation);
			break;
		case '/':
			if(Copy_u32SecondNum == 0){
				LCD_enuDisplayString("DIVISION ERROR", 14);
				Local_enuErrorState = ES_NOK;
			}
			else{
				Local_f32ResultOfOperation = (f32) Copy_u32FirstNum / Copy_u32SecondNum;
				LCD_DisplayFloatNumber(Local_f32ResultOfOperation);
			}
			break;
		default:
			LCD_enuDisplayString("INVALID INPUT", 13);
			Local_enuErrorState = ES_NOK;
		}

	}


	return Local_enuErrorState;
}

/*
 * This Function Is Used To Erase the LCD if The User Pressed the
 * Button ON/C
 *
 * */
ES_t CALC_enuStandToErase(void){
	ES_t Local_enuErrorStates = ES_NOK;
	while(Global_u8Operator != 'c'){
		KPAD_enuGetKeyValue(&Global_u8Operator);
		_delay_ms(10);
	}
	Global_u8EqualOperator = 0;
	LCD_enuSendCommand(0x01);
	return Local_enuErrorStates = ES_OK;
}


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
static inline void CALC_VoidReadingPrintNumber(s32 *Copy_u8Number){

	u8 Local_Au8KeyPadValues[NMBER_OF_DIGITS] = {0,0,0,0,0};
	u8 Local_u8CharactersChecker = 0;
	u8 Local_u8Iterator = 0;
	while(Local_u8Iterator < NMBER_OF_DIGITS){

		KPAD_enuGetKeyValue(&Local_u8CharactersChecker);
		_delay_ms(10);

		if(Local_u8CharactersChecker != KEY_NOT_PRESSED ){
			if(NOT_ARITHMATIC_OPERATOR){
				Local_Au8KeyPadValues[Local_u8Iterator] = Local_u8CharactersChecker;
				LCD_enuDisplayIntegerNum(Local_Au8KeyPadValues[Local_u8Iterator]);
				Local_u8Iterator++;
			}
			else if(ARITHMATIC_OPERATOR){
				Global_u8Operator = Local_u8CharactersChecker;
				LCD_enuDisplayChar(Global_u8Operator);
				break;
			}
			else if(EQUAL_OPERATOR){
				Global_u8EqualOperator = Local_u8CharactersChecker;
				break;
			}
		}
	}

	u8 Local_u8PowerFactor = 0;
	s32 Local_u16PowerResult = 0;
	while(Local_u8Iterator > 0){
		Local_u16PowerResult = CALC_u16ReturnPowr(Local_u8PowerFactor);
		*Copy_u8Number += Local_Au8KeyPadValues[Local_u8Iterator - 1] * Local_u16PowerResult;
		Local_u8Iterator--;
		Local_u8PowerFactor++;
	}
}

/*This Function is Used To Return The Number Position I.e. 1, 10, 100, 1000, 10000*/
static s32 CALC_u16ReturnPowr(u8 Copy_u8Iterator){
	s32 result = 1;
	for(char_8 Local_u8Iterator = Copy_u8Iterator; Local_u8Iterator > 0; Local_u8Iterator--){
		result *= 10;
	}
	return result;
}
