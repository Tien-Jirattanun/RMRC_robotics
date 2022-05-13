import sys
import pygame
from pygame.locals import *
import paho.mqtt.client as mqtt 

mqttBroker ="mqtt.eclipseprojects.io" 
client = mqtt.Client("Joystick_Inside")
client.connect(mqttBroker) 

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joysticks = pygame.joystick.Joystick(0)

message = ""

while True:

    for event in pygame.event.get():

        # When the button ABXY down
        if event.type == JOYBUTTONDOWN:
            message = str(event)

        # When the button ABXY up
        if event.type == JOYBUTTONUP:
            message = str(event)


        if event.type == JOYAXISMOTION:
            message = str(event)


        if event.type == JOYHATMOTION:
            message = str(event)

        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                pygame.quit()
                sys.exit()

        client.publish("JOYSTICK", message)
        print("Just published " + str(message) + " to topic JOYSTICK")

    clock.tick(60)
