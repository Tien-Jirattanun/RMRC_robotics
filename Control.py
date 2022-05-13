import RPi.GPIO as GPIO
import paho.mqtt.client as mqtt
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(6, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(19, GPIO.OUT)
GPIO.setup(26, GPIO.OUT)

message = ""
axis = 0
valueJoy = 0
valueArrow = ""
button = 0

def on_message(client, userdata, message):
    print(str(message.payload.decode("utf-8")))
    message = str(message.payload.decode("utf-8"))
    if 'JoyAxisMotion' in message:
        axis = int(message[63])
        valueJoy = float(message[75:79])

    elif 'JoyButtonDown' in message:
        button = int(message[64])

        if button == 0:
            print("A")
        elif button == 1:
            print("B")
        elif button == 2:
            print("X")
        elif button == 3:
            print("Y")
        
    elif 'JoyHatMotion' in message:
        valueArrow = message[73:79]
        print(valueArrow)
        if valueArrow == "(1, 0)":
            GPIO.output(6, GPIO.HIGH)
            GPIO.output(13, GPIO.LOW)
            GPIO.output(19, GPIO.LOW)
            GPIO.output(26, GPIO.LOW)
        elif valueArrow == "(0, 1)":
            GPIO.output(6, GPIO.LOW)
            GPIO.output(13, GPIO.HIGH)
            GPIO.output(19, GPIO.LOW)
            GPIO.output(26, GPIO.LOW) 
        elif valueArrow == "(-1, 0":
            GPIO.output(6, GPIO.LOW)
            GPIO.output(13, GPIO.LOW)
            GPIO.output(19, GPIO.HIGH)
            GPIO.output(26, GPIO.LOW)
        elif valueArrow == "(0, -1":
            GPIO.output(6, GPIO.LOW)
            GPIO.output(13, GPIO.LOW)
            GPIO.output(19, GPIO.LOW)
            GPIO.output(26, GPIO.HIGH) 
        elif valueArrow == "(0, 0)":
            GPIO.output(6, GPIO.LOW)
            GPIO.output(13, GPIO.LOW)
            GPIO.output(19, GPIO.LOW)
            GPIO.output(26, GPIO.LOW)

mqttBroker ="mqtt.eclipseprojects.io"

client = mqtt.Client("Raspi")
client.connect(mqttBroker) 

client.loop_start()

client.subscribe("JOYSTICK")
client.on_message=on_message


time.sleep(300)
client.loop_stop()
