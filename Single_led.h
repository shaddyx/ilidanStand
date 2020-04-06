/*
 * single_led.h
 *
 *  Created on: Mar 29, 2020
 *      Author: shaddy
 */

#ifndef SINGLE_LED_H_
#define SINGLE_LED_H_
#include "funcUtil.h"
#include "lib/light_ws2812.h"

class Single_led {
public:
	cRGB* color;
	int8_t increment = 1;
	uint8_t brightness = 0;
	bool started = 0;
	bool finished = 0;
	Single_led *next = 0;
	void nextStep();
	cRGB getCurrentColor();
	int getColors(cRGB* colors);
	void stopAll();

};



#endif /* SINGLE_LED_H_ */
