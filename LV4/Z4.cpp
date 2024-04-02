#include "mbed.h"
#include "N5110.h"
#include "lpc1114etf.h"

//N5110 lcd(VCC,SCE, RST, DC, MOSI,SCLK,LED));
N5110   lcd(dp4,dp24,dp23,dp25,dp2,dp6,dp18);
DigitalIn taster(Taster_1);
DigitalOut enable(LED_ACT);
AnalogIn pot(dp9);

//     sprintf(charArray, "Da li ovo moze %f", floatValue);
char naponText[] = "Napon: %f V";
char otporText[] = "Otpor: %f Ohm";
char text[30];
// 84×48

int x_pos = 8;
int y_pos = int(HEIGHT / 2);


void refreshScreen(float voltage, bool showResistance) {
    lcd.clear();
    if (showResistance) {
        float otpor = voltage * 10000 / 3.3;
        sprintf(text, otporText, otpor);
    } else {
        sprintf(text, naponText, voltage);
    }
    lcd.printString(text, x_pos, y_pos);
}

int main() {
    enable = 1;
    // lcd.printString("Mi volimo US!",0,0);
    float oldVoltage = 0;
    float newVoltage = 0;
    bool showResistance = false;
    bool pressed = false;
    lcd.init();
    while (1) {
        newVoltage = pot.read() * 3.3;
        if (oldVoltage != newVoltage) {
            refreshScreen(newVoltage, showResistance);
        } else if (taster && !pressed) {
            showResistance = !showResistance;
            refreshScreen(newVoltage, showResistance);
        }
        pressed = taster;
    }
}