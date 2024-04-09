#include "mbed.h"
#include "math.h"



AnalogOut analog(PTE30);
float data[25];
const float PI = atan(1) * 4;

int main() {
    for (int i = 0; i < 25; i++) {
        data[i] = sin(2 * PI / 50 * i);
    }

    while (1) {
        for (int i = 0; i < 25; i++) {
            auto start = std::chrono::high_resolution_clock::now();

            analog.write(data[i]);
        
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            wait_us(40);
        }
    }
}
    