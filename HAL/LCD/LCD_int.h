/*
 * LCD_int.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuDisplayString(char *Copy_u8Data, u8 Copy_u8DataLength);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);


ES_t LCD_enuDisplayExtraChar(u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry);


ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num);

ES_t LCD_DisplayFloatNumber(f32 Copy_f32Number);

#endif /* LCD_INT_H_ */
