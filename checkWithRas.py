import sys
from tkinter import Button
import pygame
from pygame.locals import *

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joysticks = pygame.joystick.Joystick(0)

axis = 0
valueJoy = 0
valueArrow = ""
button = ""

message = ""

while True:

    for event in pygame.event.get():

        # When the button ABXY down
        if event.type == JOYBUTTONDOWN:
            message = str(event)
            print(event)

        # When the button ABXY up
        if event.type == JOYBUTTONUP:
            message = str(event)
            print(event)

        if event.type == JOYAXISMOTION:
            message = str(event)
            print(event)

        if event.type == JOYHATMOTION:
            message = str(event)
            print(event)

        if event.type == QUIT: 
            pygame.quit()
            sys.exit()
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                pygame.quit()
                sys.exit()

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

        if valueArrow == "(1, 0)":
            print("Right")
        elif valueArrow == "(0, 1)":
            print("Up") 
        elif valueArrow == "(-1, 0":
            print("Left")
        elif valueArrow == "(0, -1":
            print("Down")
        elif valueArrow == "(0, 0)":
            print("Sleep")



    clock.tick(60)
