/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: amrmo
 */

#include "LIB/std_Types.h"
#include "LIB/ErrorStates.h"
#include "util/delay.h"

#include "APP/CALC_config.h"
#include "APP/CALC_int.h"

/*
 * This Program Is A simple Calculator That Makes Operations On
 * Just To Numbers Entered Using 4 x 4 KeyPad And Displayed On
 * 16 x 2 LCD
 *
 *
 * The Digits Entered Can't Exceed 5 digits But It can be Modified
 * In APP --> CALC_config.h
 *
 * The Digits In the Fraction Can't Exceed 5 Digits But it Can
 * Be Modified In HAL --> LCD --> LCD_config.h >> Line 49
 *
 * The Pins And Ports Of Each Component Is Defined In its OWN
 * Config.h File In HAL folder (It can Be Modified).
 *
 * */
extern u8 Global_u8EqualOperator;
int main(void){

	CALC_enuInit();
	s32 Local_u8Num1 = 0, Local_u8Num2 = 0;
	while(1){
		Local_u8Num1 = 0, Local_u8Num2 = 0;
		while( Global_u8EqualOperator != '='){
			CALC_enuReadNumber(&Local_u8Num1);
			_delay_ms(10);

			CALC_enuReadNumber(&Local_u8Num2);
			_delay_ms(10);

		}
		CALC_enuDisplayResult(Local_u8Num1, Local_u8Num2);
		_delay_ms(10);
		CALC_enuStandToErase();
	}

	return 0;
}
