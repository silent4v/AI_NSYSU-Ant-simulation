from Cell import Cell,no_game_no_life
import pygame

data = [[Cell(True,10) for j in range(3)]for i in range(3)]
for i in range(3):
    for j in range(3):
        if(i%2 == 0):
            data[i][j].live()
        else:
            data[i][j].die()
no_game_no_life(data,1,0,3,3)