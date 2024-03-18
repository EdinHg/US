#include "mbed.h"

DigitalOut cekanjeLED(LED1);
BusOut leds(p6, p7, p8, p9, p10, p11, p12, p13);

// BusIn tasters(BUTTON1, p5);

InterruptIn fast(BUTTON1);
InterruptIn slow(p5);

void ciklus(float t) {
    for (int i = 1; i < 256; i *= 2) {
        leds.write(i);
        wait(t);
    }
    leds.write(255);
    wait(t);
    for (int i = 128; i > 0; i /= 2) {
        leds.write(i);
        wait(t);
    }
    leds.write(0);
}

void slowCycle() { ciklus(0.5); }
void fastCycle() { ciklus(0.1); }

int main() {
    fast.rise(&fastCycle);
    slow.rise(&slowCycle);
    
    while (1) {
        cekanjeLED = !cekanjeLED;
        wait(0.5);
    }
}