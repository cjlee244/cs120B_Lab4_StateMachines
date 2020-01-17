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

enum States {Start, Wait, Enter, Unlock, Lock} state;
	
void TickSM() {
	switch(state) {
		case Start:
			state = Wait;
			break;
		case Wait:
			state = ((PINA & 0x04) == 4) ? Enter:Wait; 
			break;
		case Enter:
			state = ((PINA & 0x02) == 2) ? Unlock:Wait;
			break;
		case Unlock:
			state = Lock;
			break;
		case Lock:
			state = ((PINA & 0x80) == 0x80) ? Wait:Lock;
			break;
		default:
			state = Start;
			break;
	}
	
	switch(state) {
		case Start:
			PORTC = 0x00;
			break;
		case Wait:
			PORTB = 0x00;
			PORTC = 0x01;
			break;
		case Enter:
			PORTC = 0x02;
			break;
		case Unlock:
			PORTB = 0x01;
			PORTC = 0x03;
			break;
		case Lock:
			PORTC = 0x04;
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
