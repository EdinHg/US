#include "mbed.h"

BusOut leds(p5, p6, p7, p8, p9, p10, p11, p12);
AnalogIn pot(p15);
float voltage;
char br_dioda;

int main() {
    while (1) {
        voltage = pot.read();
        br_dioda = char(voltage * 8);
        leds.write(255 << br_dioda);
        wait_ms(100);
    }
}