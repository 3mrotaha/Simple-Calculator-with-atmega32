/*
 * LCD_priv.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT_BIT	51
#define FOUR_BIT	9


static inline void LCD_invidSendCommend(u8 Copy_u8Command);

static void LCD_vidLatch(u8 Copy_u8Data);

static inline void LCD_VoidDisplayAnyNumber(s32 Copy_s32Num);

#endif /* LCD_PRIV_H_ */
