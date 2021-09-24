/*
 * DIO_prog.c
 *
 *  Created on: Sep 17, 2021
 *      Author: amrmo
 */

#include "../../LIB/std_Types.h"
#include "../../LIB/ErrorStates.h"


#include "DIO_priv.h"
#include "DIO_config.h"


ES_t DIO_enuInit(void){
	ES_t Local_enuErrorStates = ES_NOK;
	DDRA = CONC(DIO_PA_PIN7_DIR, DIO_PA_PIN6_DIR, DIO_PA_PIN5_DIR, DIO_PA_PIN4_DIR, DIO_PA_PIN3_DIR, DIO_PA_PIN2_DIR, DIO_PA_PIN1_DIR, DIO_PA_PIN0_DIR);
	DDRB = CONC(DIO_PB_PIN7_DIR, DIO_PB_PIN6_DIR, DIO_PB_PIN5_DIR, DIO_PB_PIN4_DIR, DIO_PB_PIN3_DIR, DIO_PB_PIN2_DIR, DIO_PB_PIN1_DIR, DIO_PB_PIN0_DIR);
	DDRC = CONC(DIO_PC_PIN7_DIR, DIO_PC_PIN6_DIR, DIO_PC_PIN5_DIR, DIO_PC_PIN4_DIR, DIO_PC_PIN3_DIR, DIO_PC_PIN2_DIR, DIO_PC_PIN1_DIR, DIO_PC_PIN0_DIR);
	DDRD = CONC(DIO_PD_PIN7_DIR, DIO_PD_PIN6_DIR, DIO_PD_PIN5_DIR, DIO_PD_PIN4_DIR, DIO_PD_PIN3_DIR, DIO_PD_PIN2_DIR, DIO_PD_PIN1_DIR, DIO_PD_PIN0_DIR);

	PORTA = CONC(DIO_PA_PIN7_VAL, DIO_PA_PIN6_VAL, DIO_PA_PIN5_VAL, DIO_PA_PIN4_VAL, DIO_PA_PIN3_VAL, DIO_PA_PIN2_VAL, DIO_PA_PIN1_VAL, DIO_PA_PIN0_VAL);
	PORTB = CONC(DIO_PB_PIN7_VAL, DIO_PB_PIN6_VAL, DIO_PB_PIN5_VAL, DIO_PB_PIN4_VAL, DIO_PB_PIN3_VAL, DIO_PB_PIN2_VAL, DIO_PB_PIN1_VAL, DIO_PB_PIN0_VAL);
	PORTC = CONC(DIO_PC_PIN7_VAL, DIO_PC_PIN6_VAL, DIO_PC_PIN5_VAL, DIO_PC_PIN4_VAL, DIO_PC_PIN3_VAL, DIO_PC_PIN2_VAL, DIO_PC_PIN1_VAL, DIO_PC_PIN0_VAL);
	PORTD = CONC(DIO_PD_PIN7_VAL, DIO_PD_PIN6_VAL, DIO_PD_PIN5_VAL, DIO_PD_PIN4_VAL, DIO_PD_PIN3_VAL, DIO_PD_PIN2_VAL, DIO_PD_PIN1_VAL, DIO_PD_PIN0_VAL);
	Local_enuErrorStates = ES_OK;
	return Local_enuErrorStates;
}

ES_t DIO_enuSetPortDir(u8 Copy_PortID, u8 Copy_PortDir){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <=  DIO_PORTD){
		switch(Copy_PortID){
			case DIO_PORTA:
				DDRA = Copy_PortDir;
				break;
			case DIO_PORTB:
				DDRB = Copy_PortDir;
				break;
			case DIO_PORTC:
				DDRC = Copy_PortDir;
				break;
			case DIO_PORTD:
				DDRD = Copy_PortDir;
				break;
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuSetPortValue(u8 Copy_PortID, u8 Copy_PortValue){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <=  DIO_PORTD){
		switch(Copy_PortID){
			case DIO_PORTA:
				PORTA = Copy_PortValue;
				break;
			case DIO_PORTB:
				PORTB = Copy_PortValue;
				break;
			case DIO_PORTC:
				PORTC = Copy_PortValue;
				break;
			case DIO_PORTD:
				PORTD = Copy_PortValue;
				break;
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuGetPortValue(u8 Copy_PortID, u8 *Copy_PortVal){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <=  DIO_PORTD){
		switch(Copy_PortID){
			case DIO_PORTA:
				*Copy_PortVal = PINA;
				break;
			case DIO_PORTB:
				*Copy_PortVal = PINB;
				break;
			case DIO_PORTC:
				*Copy_PortVal = PINC;
				break;
			case DIO_PORTD:
				*Copy_PortVal = PIND;
				break;
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuTogPortValue(u8 Copy_PortID){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <=  DIO_PORTD){
		switch(Copy_PortID){
			case DIO_PORTA:
				PORTA = ~PORTA;
				break;
			case DIO_PORTB:
				PORTB = ~PORTB;
				break;
			case DIO_PORTC:
				PORTC = ~PORTC;
				break;
			case DIO_PORTD:
				PORTD = ~PORTD;
				break;
		}
		Local_enuErrorStates = ES_OK;
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuSetPinDir(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinDir){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <= DIO_PORTD){
		if(Copy_PinID <= DIO_PIN7){
			switch(Copy_PortID){
				case DIO_PORTA:
					DDRA &= ~(BIT_MASK_VALUE << Copy_PinID);
					DDRA |= (Copy_PinDir << Copy_PinID);
					break;
				case DIO_PORTB:
					DDRB &= ~(BIT_MASK_VALUE << Copy_PinID);
					DDRB |= (Copy_PinDir << Copy_PinID);
					break;
				case DIO_PORTC:
					DDRC &= ~(BIT_MASK_VALUE << Copy_PinID);
					DDRC |= (Copy_PinDir << Copy_PinID);
					break;
				case DIO_PORTD:
					DDRD &= ~(BIT_MASK_VALUE << Copy_PinID);
					DDRD |= (Copy_PinDir << Copy_PinID);
					break;
			}
			Local_enuErrorStates = ES_OK;
		}
		else{
			Local_enuErrorStates = ES_PIN_OUT_OF_RANGE;
		}
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuSetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 Copy_PinValue){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <= DIO_PORTD){
			if(Copy_PinID <= DIO_PIN7){
				switch(Copy_PortID){
					case DIO_PORTA:
						PORTA &= ~(BIT_MASK_VALUE << Copy_PinID);
						PORTA |= (Copy_PinValue << Copy_PinID);
						break;
					case DIO_PORTB:
						PORTB &= ~(BIT_MASK_VALUE << Copy_PinID);
						PORTB |= (Copy_PinValue << Copy_PinID);
						break;
					case DIO_PORTC:
						PORTC &= ~(BIT_MASK_VALUE << Copy_PinID);
						PORTC |= (Copy_PinValue << Copy_PinID);
						break;
					case DIO_PORTD:
						PORTD &= ~(BIT_MASK_VALUE << Copy_PinID);
						PORTD |= (Copy_PinValue << Copy_PinID);
						break;
				}
				Local_enuErrorStates = ES_OK;
			}
			else{
				Local_enuErrorStates = ES_PIN_OUT_OF_RANGE;
			}
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuGetPinValue(u8 Copy_PortID, u8 Copy_PinID, u8 *Copy_PinVal){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <= DIO_PORTD){
			if(Copy_PinID <= DIO_PIN7){
				switch(Copy_PortID){
					case DIO_PORTA:
						*Copy_PinVal = ((PINA >> Copy_PinID) & BIT_MASK_VALUE);
						break;
					case DIO_PORTB:
						*Copy_PinVal = ((PINB >> Copy_PinID) & BIT_MASK_VALUE);
						break;
					case DIO_PORTC:
						*Copy_PinVal = ((PINC >> Copy_PinID) & BIT_MASK_VALUE);
						break;
					case DIO_PORTD:
						*Copy_PinVal = ((PIND >> Copy_PinID) & BIT_MASK_VALUE);
						break;
				}
				Local_enuErrorStates = ES_OK;
			}
			else{
				Local_enuErrorStates = ES_PIN_OUT_OF_RANGE;
			}
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}

ES_t DIO_enuTogPinValue(u8 Copy_PortID, u8 Copy_PinID){
	ES_t Local_enuErrorStates = ES_NOK;
	if(Copy_PortID <= DIO_PORTD){
			if(Copy_PinID <= DIO_PIN7){
				switch(Copy_PortID){
					case DIO_PORTA:
						PORTA ^= (BIT_MASK_VALUE << Copy_PinID);
						break;
					case DIO_PORTB:
						PORTB ^= (BIT_MASK_VALUE << Copy_PinID);
						break;
					case DIO_PORTC:
						PORTC ^= (BIT_MASK_VALUE << Copy_PinID);
						break;
					case DIO_PORTD:
						PORTD ^= (BIT_MASK_VALUE << Copy_PinID);
						break;
				}
				Local_enuErrorStates = ES_OK;
			}
			else{
				Local_enuErrorStates = ES_PIN_OUT_OF_RANGE;
			}
	}
	else{
		Local_enuErrorStates = ES_PORT_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}
