#include "mbed.h"

BusOut leds(p5, p6, p7, p8, p9, p10, p11, p12);
DigitalIn taster(BUTTON1);

int main() {
    int counter = 0;
    int smjer = 1;
    
    while(1) {
        // bolje bi vilo interrupt koristiti
            // if (taster.read()) smjer *= -1;
            // counter += smjer
        counter = (counter + (taster.read() ? -1 : 1)) % 256;
        
        leds.write(counter);
        wait(1);
    }
}