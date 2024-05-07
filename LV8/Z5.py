import time
import RPi.GPIO as GPIO

LED_PIN = 0
TASTER_PIN = 0
duty = 0

GPIO.setmode(GPIO.BOARD)
GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(TASTER_PIN, GPIO.IN)

led = GPIO.PWM(LED_PIN, 100)  
led.start(0)

def povecaj_duty():
    global duty
    duty += 10
    
    if duty > 100:
        duty = 0

    led.ChangeDutyCycle(duty)

GPIO.add_event_detect(TASTER_PIN, GPIO.RISING, callback=povecaj_duty, bouncetime=200)

while True:
    pass

GPIO.remove_event_detect(BUTTON_PIN)
GPIO.cleanup()