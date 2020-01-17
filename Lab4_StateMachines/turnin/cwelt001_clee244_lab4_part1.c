/*	Author: clee244
 *  Partner(s) Name: Carson Welty
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Init, On, Off} state;

void TickSM() {
	switch (state) { // Transitions
		case Init:
			state = On;
			break;
		case On:
			state = PINA? Off: On;
			break;
		case Off:
			state = PINA? Off: On;
			break;
		default:
			state = Init;
			break;
	}
	switch (state) { // State Actions
		case Init:
			break;
		case On:
			PORTB = 0x01;
			break;
		case Off:
			PORTB = 0x02;
			break;
		default:
			break;
	}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    state = Init;
    while (1) {
		TickSM();
    }
    return 1;
}
