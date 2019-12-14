#include "light_ws2812.h"
#include "ws2812_config.h"
#include "test_lib.h"
#include <math.h>

#define LED_PIN     PB3
#define NUM_LEDS    5

// typedef struct _pixel {
// 	uint8_t g;
// 	uint8_t r;
// 	uint8_t b;
// } pixel;

cRGB pixels[NUM_LEDS];
u_int8_t brightness[NUM_LEDS];
int counter = 0;
void setup()
{  
}

int calc_multiplier(int angle){
    angle = angle % 180;
    if (angle <= 90){
        return angle;
    } 
    return 180 - angle;
}

void apply(){
    for (int i=0; i<NUM_LEDS; i++){
        int angle = counter + (i * 90);
        int c = calc_multiplier(angle);
        int value = 0;
        if (abs (counter - i * 180 / NUM_LEDS) <= 180 / NUM_LEDS * 2){
            value = c * (255 / 90);
        }
        pixels[i].r = 0;
        pixels[i].g = 0;
        pixels[i].b = value;
    }
    ws2812_setleds(pixels, NUM_LEDS);
}

void loop()
{
    delay(1);
    counter ++;
    if (counter >= 180){
        counter = 0;
    }
    for (int i=0; i<NUM_LEDS; i++){
        int angle = counter + (i * 90);
        int c = calc_multiplier(angle);
        int value = 0;
        if (abs (counter - i * 180 / NUM_LEDS) <= 180 / NUM_LEDS * 2){
            value = c * (255 / 90);
        }
        pixels[i].r = 0;
        pixels[i].g = 0;
        pixels[i].b = value;
    }
	
}
