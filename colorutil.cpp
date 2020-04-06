/*
 * colorutil.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: shaddy
 */

#include "colorutil.h"

#define MAX 255

uint8_t mapBrightness(uint8_t value){
	return value;
//	float brightness = (float) value / RGBconst;
//	if (brightness > 255) {
//		brightness = 255;
//	}
//	return brightness;
	//return brightnessMap[value];
}


uint8_t percentage(uint8_t col, int br){
    return ((float) col / MAX) * br;
}

cRGB getColor(cRGB color, uint8_t brightness){
	cRGB current;
	auto br = mapBrightness(brightness);
	current.r = percentage(color.r, br);
	current.g = percentage(color.g, br);
	current.b = percentage(color.b, br);
	return current;
}
