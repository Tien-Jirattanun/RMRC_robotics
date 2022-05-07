import paho.mqtt.client as mqtt 
from random import uniform
import time

mqttBroker ="mqtt.eclipseprojects.io" 

client = mqtt.Client("Joystick_Inside")
client.connect(mqttBroker) 

while True:
    randNumber = uniform(20.0, 21.0)
    client.publish("JOYSTICK", randNumber)
    print("Just published " + str(randNumber) + " to topic JOYSTICK")
    time.sleep(1)
