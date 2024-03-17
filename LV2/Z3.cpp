#include "mbed.h"

BusOut leds(p5, p6, p7, p8, p9, p10, p11, p12);
DigitalIn taster(BUTTON1);

int main() {
    int counter = 1;
    int smjer = 1;
    
    while(1) {
        leds.write(counter);
        if (smjer == 1) counter *= 2;
        else counter /= 2; // counter = counter >> 1;
        if (counter == 128) {
            // counter = 255
            leds.write(255);
            smjer *= -1;
        } else if (counter == 1) {
            smjer *= -1;
        }
        wait(0.1);
    }
}