#include "med.h"
#include "lpc1114etf.h"

DigitalOut e(LED_ACT);
BusOut leds(LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7)
BusIn col(dp9, dp10, dp11, dp13,);
BusOut rows(dp16, dp15, dp17, dp18);

char keys[][] = {
  { 1, 2, 3, 13 },
  { 4, 5, 6, 14 },
  { 7, 8, 9, 15 },
  { 10, 11, 12, 16 }
}

char get_key() {
    for (int i = 0; i < 4; i++) {
        rows[i] = 1;
        for (int j = 0; j < 4; j++) {
            char key = 0;

            if (cols[j]) {
                rows[i] = 0;
                wait_us(100000);
                return keys[i][j];
            }
        }

        rows[i] = 0;
    }

    return 0;
}

// def get_key():
//     for row in range(4):
//         for col in range(4):
//             rows[row].high()
//             key = None
            
//             if cols[col].value() == 1:
//                 rows[row].low()
//                 time.sleep(0.1)
//                 return keys[row][col] 
        
//         rows[row].low()

//     return 16


int main() {
    e = 0;

    while (1) {
        if (c >= 1 && c <= 8) {
            leds[c - 1] = 1;
        } else if (c == 15) {
            leds.write(0);
        }

        wait_us(100000);
    }
    

}


while True:
    c = get_key()
    print(c)
    if c >= 1 and c <= 8:
        leds[c - 1].value(1)
    elif c == 15:
        for led in leds:
            led.off()

    time.sleep(0.1)