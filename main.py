import sys
import tkinter as tk
import pygame

from pygame.locals import *
pygame.init()
clock = pygame.time.Clock()

pygame.joystick.init()
joysticks = pygame.joystick.Joystick(0)

window = tk.Tk();
window.title('ROBOT GUI')

joy = tk.Label(
    text='JoyStick',
    font=("Arial", 25)
)


joy.pack()
window.mainloop()

while True:

    for event in pygame.event.get():

        # When the button ABXY down
        if event.type == JOYBUTTONDOWN:
            print(event)
            if event.button == 0:
                print("button 'A' press")
            elif event.button == 1:
                print("button 'B' press")
            elif event.button == 2:
                print("button 'X' press")
            elif event.button == 3:
                print("button 'Y' press")
            elif event.button == 6:
                print("button 'back' press")
            elif event.button == 7:
                print("button 'Right' press")
            elif event.button == 8:
                print("Left joy button")
            elif event.button == 9:
                print("Right joy button")

        # When the button ABXY up
        if event.type == JOYBUTTONUP:
            print(event)


        if event.type == JOYAXISMOTION:
            print(event)


        if event.type == JOYHATMOTION:
            print(event)

        if event.type == QUIT:
            pygame.quit()
            sys.exit()
        if event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                pygame.quit()
                sys.exit()

    clock.tick(60)