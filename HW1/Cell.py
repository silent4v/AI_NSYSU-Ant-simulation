import pygame

class Cell():
    def __init__(self,status,width):
        self.state = bool(status)
        self.width = width     #state is for live or dead,true for live,false for dead
        self.surface = pygame.Surface((self.width,self.width))
    def size(self):
        return (self.width,self.width)
    def Width(self):
        return self.width
    def status(self):
        return self.state
    def live(self):
        self.state = True
    def die(self):
        self.state = False

def no_game_no_life(Data,Temp,x,y,limit_d,limit_r):  #limit N,E,W,S
    
    count = 0       #count the number of cells neighbor
    if(y < limit_r - 1):    #Right
        if x == 0:          #Right,UP
            if Data[x][y+1].status():
                count += 1
            if Data[x+1][y+1].status():
                count += 1
        elif x == limit_d-1:    #Right,DOWN
            if Data[x][y+1].status():
                count += 1
            if Data[x-1][y+1].status():
                count += 1    
        else:
            if Data[x][y+1].status():
                count += 1
            if Data[x-1][y+1].status():
                count += 1
            if Data[x+1][y+1].status():
                count += 1
    if(y > 0):    #left
        if x == 0:      #Left,UP
            if Data[x][y-1].status():
                count += 1
            if Data[x+1][y-1].status():
                count += 1
        elif x == limit_d-1:    #Left,DOWN
            if Data[x][y-1].status():
                count += 1
            if Data[x-1][y-1].status():
                count += 1
        else:
            if Data[x][y-1].status():
                count += 1
            if Data[x-1][y-1].status():
                count += 1
            if Data[x+1][y-1].status():
                count += 1
    if x > 0:    #UP
        if Data[x-1][y].status():
            count += 1
    if x < limit_d - 1:     #DOdataWN
        if Data[x+1][y].status():
            count += 1

    if Data[x][y].status() and count != 2 and count != 3:
        Temp[x][y] = False
    elif not Data[x][y].status() and count == 3:
        Temp[x][y] = True

def rewrite(Data,Temp,limit_r,limit_d):
    for i in range(limit_d):
        for j in range(limit_r):
            if(Temp[i][j]):
                Data[i][j].live()
            else:
                Data[i][j].die()