#include "mbed.h"

PinName leds[4] = { LED1, LED2, LED3, LED4 };

int main() {
    while(1) {
        for (int i = 0; i < 4; i++) {
            DigitalOut led(leds[i]);
            led = 1;
            wait(1);
            led = 0;
            wait(1);        
        }
    }
}