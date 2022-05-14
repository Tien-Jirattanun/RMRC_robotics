import RPi.GPIO as GPIO
from time import sleep

global PWM1
global PWM2

#define pins
PIN_IN1 = 20
PIN_IN2 = 21
PIN_PWM1 = 12
PIN_IN3 = 23
PIN_IN4 = 24
PIN_PWM2 = 13

#define data for PWM
DutyCycle = 0
Freq = 500

#general setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(PIN_IN1 ,GPIO.OUT)
GPIO.setup(PIN_IN2 ,GPIO.OUT)
GPIO.setup(PIN_PWM1 ,GPIO.OUT)
GPIO.setup(PIN_IN3 ,GPIO.OUT)
GPIO.setup(PIN_IN4 ,GPIO.OUT)
GPIO.setup(PIN_PWM2 ,GPIO.OUT)

#pwm setup
PWM1 = GPIO.PWM(PIN_PWM1, Freq) 
PWM2 = GPIO.PWM(PIN_PWM2, Freq) 
PWM1.start(0)
PWM2.start(0)

#test
PWM1.ChangeDutyCycle(20)
PWM2.ChangeDutyCycle(20)
GPIO.output(PIN_IN1, GPIO.HIGH)
GPIO.output(PIN_IN2, GPIO.LOW)
sleep(1)
GPIO.output(PIN_IN1, GPIO.LOW)
GPIO.output(PIN_IN2, GPIO.LOW)
sleep(1)
PWM1.ChangeDutyCycle(100)
PWM2.ChangeDutyCycle(100)
GPIO.output(PIN_IN1, GPIO.HIGH)
GPIO.output(PIN_IN2, GPIO.LOW)
sleep(1)
GPIO.output(PIN_IN1, GPIO.LOW)
GPIO.output(PIN_IN2, GPIO.LOW)
sleep(1)

GPIO.cleanup()









