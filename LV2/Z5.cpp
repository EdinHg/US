#include "mbed.h"
#include <iostream>

DigitalOut led(LED1);

void fun(float t) {
    float on = 1, off = 1;
    float d = 0.9 / 14;
    int smjer = 1;
    int it = 14;
    while (1) {
        std::cout << on << " " << off << std::endl;
        led = !led; wait(on * t);
        led = !led; wait(off * t);
        if (it % 28 == 0) smjer *= -1;
        on += smjer * d;
        off -= smjer * d;
        it += smjer; 
    }
}

int main() {
    fun(0.005);
}
