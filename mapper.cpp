/*
 * mapper.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: shaddy
 */

#include "mapper.h"


#define m(x, to) mapSingle(colors, led, x, number, to);
void mapSingle(cRGB* colors, Single_led* led, int current, int number, int to){
	if (current == number){
		colors[to] = led->getCurrentColor();
	}
}

void mapLed(cRGB* colors, Single_led* led, int number){
	m(0, 5);
	m(1, 4);
	m(2, 0);
	m(3, 1);

	m(4, 5);
	m(5, 10);
	m(6, 9);
	m(7, 13);

	m(8, 5);
	m(9, 6);

	m(10, 7);
	m(11, 8);
	m(12, 4);
	m(13, 3);
	m(14, 2);

}

void map(cRGB* colors, Single_led* leds){
	Single_led* pointer = &leds[0];
	int counter = 0;
	while (pointer){
		mapLed(colors, pointer, counter);
		pointer = pointer->next;
		counter ++;
	}

}

