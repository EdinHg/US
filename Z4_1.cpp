#include "mbed.h"
#include <cstdio>

DigitalOut cekanjeLED(LED1);
BusOut leds(p6, p7, p8, p9, p10, p11, p12, p13);
BusIn tasters(BUTTON1, p5);

void trcece(float t) {    
    for (int i = 1; i < 256; i *= 2) {
        leds.write(i);
        wait(t);
    }
    leds.write(255);
    wait(t);
    for (int i = 128; i >= 0; i /= 2) {
        leds.write(i);
        wait(t);
    }
}

int main() {
    unsigned char tick = 0;
    unsigned char pritisnuto;
    while (1) {
        std::printf("%u\n", tick);
        tick++;
        if (tick % 5 == 0) {
            cekanjeLED = !cekanjeLED;
            tick = 0;
        }
        if ((pritisnuto = tasters.read())) {
            if (pritisnuto == 1) {
                cekanjeLED = 0;
                tick = 0;
                trcece(0.1);
            } else {
                cekanjeLED = 0;
                tick = 0;
                trcece(0.5);
            }
        } else {
            wait(0.1);
        }
    }
}