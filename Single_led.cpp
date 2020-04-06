/*
 * single_led.cpp
 *
 *  Created on: Mar 29, 2020
 *      Author: shaddy
 */
#include <Arduino.h>
#include "Single_led.h"
#include "arrayTools.h"
#include "colorutil.h"
//uint8_t brightnessMap[] = {0, 1, 2, 3, 4, 5, 8, 15, 30, 60, 120, 180, 250};
uint8_t brightnessMap[] =   {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
float RGBconst = (251 * log10(2))/(log10(255));
//#define MAX (array_size(brightnessMap) - 1)

#define MAX 250
#define BOUNDARY (MAX / 3)
#define ONDECREMENT false



void Single_led::nextStep(){
	if (this->started){
		this->finished = false;
		this->brightness += this->increment;
		if (this->brightness >= MAX){
			this->brightness = MAX;
			this->increment = -this->increment;
		}
		if (this->brightness <= 0){
			this->started = false;
			this->increment = -this->increment;
			if (!this->next){
				this->finished = true;
			}
		}
	}

	if (this->next){
		if (this->brightness > BOUNDARY && ((this->increment < 0 && ONDECREMENT) || (this->increment > 0 && !ONDECREMENT))){
			next->started = true;
		}

		next->nextStep();
	}
}
void Single_led::stopAll(){
	Single_led *pointer = this;
	while (pointer){
		pointer->started = false;
		pointer->brightness = 0;
		if (pointer->increment < 0){
			pointer->increment = -pointer->increment;
		}
		pointer->finished = false;
		pointer = pointer->next;
	}
}

cRGB Single_led::getCurrentColor(){
	return getColor(*this->color, this->brightness);
}


int Single_led::getColors(cRGB* colors){
	int counter = 0;
	Single_led *pointer = this;
	while (pointer){
		colors[counter] = pointer->getCurrentColor();
		counter ++;
		pointer = pointer->next;
		if (counter > 100){
			Serial.println("err");
			return 0;
		}
	}
	return counter;
}



