/*
 Blink
 Turns on an LED on for one second, then off for one second, repeatedly.

 Most Arduinos have an on-board LED you can control. On the Uno and
 Leonardo, it is attached to digital pin 13. If you're unsure what
 pin the on-board LED is connected to on your Arduino model, check
 the documentation at http://www.arduino.cc

 This example code is in the public domain.

 modified 8 May 2014
 by Scott Fitzgerald
 */
#include "Single_led.h"
#include "arrayTools.h"
#include "mapper.h"
#include "colorutil.h"
//#include "lib/light_ws2812.h"

#define NUM_LEDS 14
#define NUM_REAL_LEDS 18
Single_led leds[NUM_LEDS];
#define lastLedIndex array_size(leds) - 1

//cRGB color = { 255, 255, 255 };
//const cRGB color PROGMEM = { 255, 255, 255 };
const cRGB color = { 255, 0, 0 };

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	Serial.println("Started: " + String(array_size(leds)) + " : " + String(sizeof(Single_led)));
	leds[0].stopAll();
	leds[0].started = true;
	for (int i = 0; i < array_size(leds); i++) {
		if (i < array_size(leds) - 1) {
			leds[i].next = &leds[i + 1];
		}
		leds[i].color = &color;
	}
//	while (true){
//
//	}

}
uint8_t brightness = 0;
int8_t increment = 2;
long prev = 0;

// the loop function runs over and over again forever
void loop() {
	delay(13);              // wait for a second
	brightness += increment;
	if (increment > 0 && brightness >= 250){
		increment = - increment;
	}

	if (increment < 0 && brightness <= 10){
		increment = - increment;
	}

	bool allowDelay = false;
	for (int i = 0; i < 15; i++) {
		leds[0].nextStep();
		if (leds[lastLedIndex].finished) {
			//Serial.println("Callback called:");
			leds[0].stopAll();
			allowDelay = true;
			break;
		}
	}
	cRGB colors[NUM_REAL_LEDS];
	for (int i=0; i < NUM_REAL_LEDS; i++){
		colors[i].r = 0;
		colors[i].g = 0;
		colors[i].b = 0;
	}
	for (int i=14; i < NUM_REAL_LEDS; i++){
		colors[i] = getColor(color, brightness);
	}
	map(colors, leds);
	ws2812_setleds(colors, NUM_REAL_LEDS);

	if (allowDelay){
		//delay (2000);
		prev = millis();
	}
	if (millis() < prev){
		prev = millis();
	}
	if (prev != 0 && millis() - prev > 2000){
		prev = 0;
		leds[0].started = true;
	}

//Serial.println("Callback called:" + String(led -> brightness));


}
