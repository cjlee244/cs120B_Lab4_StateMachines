/*	Author: clee244
 *  Partner(s) Name: Carson Welty
 *	Lab Section: 24
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, Wait, Unlock, Reset} state;


void TickSM() {
	switch(state) { //transitions
		case Start:
			state = Wait;
			PORTB = 0x00;
			break;
		case Wait:
			if((PINA & 0x0F) == 0x04) {
				state = Unlock;
			}
			else {
				state = Wait;
				if ((PINA & 0xF0) == 0x80) {
					PORTB = 0x00;
				}
			}
			break;
		case Unlock:
			if((PINA & 0x0F) == 0x00) {
				state = Reset;
			} 
			else if((PINA & 0x0F) == 0x04) {
				state = Unlock;
			} 
			else {
				state = Wait;
				if ((PINA & 0xF0) == 0x80) {
					PORTB = 0x00;
				}

			}
			break;
		case Reset:
			if((PINA & 0x0F) == 0x02) {
				state = Wait;
 				PORTB = 0x01;
			} 
			else if((PINA & 0x0F) == 0x00) {
				state = Reset;	
			} 
			else {
				state = Wait;
				if ((PINA & 0xF0) == 0x80) {
					PORTB = 0x00;
				}
			}
			break;
		default:
			state = Wait;
			PORTB = 0x00;
			break;
		break;
	}
	switch(state) { //actions (empty)
		case Start:
		case Wait:
		case Unlock:
		case Reset:
		default:
			break;
	}
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */    
	while (1) {
		TickSM();
    }
}
