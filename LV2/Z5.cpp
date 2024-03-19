#include "mbed.h"

DigitalOut led(LED1);
DigitalOut e(LED_ACT);

void fun(float t) {
    float on = 1, off = 1;
    float d = 0.9 / 14;
    int smjer = 1;
    int it = 14;
    while (1) {
        led = !led; wait_us(on * t * 1000000);
        led = !led; wait_us(off * t * 1000000);
        if (it % 28 == 0) smjer *= -1;
        on += smjer * d;
        off -= smjer * d;
        it += smjer; 
    }
}

int main() {
    e = 0;
    fun(0.005);
}
