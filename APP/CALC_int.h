/*
 * CALC_int.h
 *
 *  Created on: Sep 23, 2021
 *      Author: amrmo
 */

#ifndef APP_CALC_INT_H_
#define APP_CALC_INT_H_

/*This Function is Used To Initialize the Calculator Components LCD and KEYPAD
 * its Also Intialize the Cursor to Write in the First Line
 */
ES_t CALC_enuInit(void);



/*This Function Is Used To Read The Number Pressed By the User*/
ES_t CALC_enuReadNumber(s32 *Copy_u32Num);


/*
 * This Function Is Used To Erase the LCD if The User Pressed the
 * Button ON/C
 *
 * */
ES_t CALC_enuStandToErase(void);



/*This Function Is Used To Display The Result Of the Operation Detected
 * By the User +, -, x, / and displays invalid Input if the Operation
 * Is Not Correctly Typed
 *
 * The Result Is Diplayed In the Left Of the Second Line
 * */
ES_t CALC_enuDisplayResult(s32 Copy_u32FirstNum, s32 Copy_u32SecondNum);

#endif /* APP_CALC_INT_H_ */
