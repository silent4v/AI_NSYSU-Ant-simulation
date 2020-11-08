import sys,time,random,pygame
import pygame.locals as game
from Cell import Cell,no_game_no_life,rewrite
#pixel
win_height = 1000
win_width = 1000
cell_width = 10
#color
white = (255,255,255)
black = (0,0,0)
blue = (0,0,255)
red = (255,0,0)
green = (0,255,0)
#initialize
pygame.init()
win_size = (win_width,win_height)
win = pygame.display.set_mode(win_size)
pygame.display.set_caption('Ant model')
win.fill(white)


data = [[Cell(random.randint(0,1),cell_width) for j in range(win_width//cell_width)]for i in range(win_height//cell_width)]
#temp = [[random.randint(0,1) for j in range(win_width//cell_width)]for i in range(win_height//cell_width)]
#
while True:
    for event in pygame.event.get():
        if event.type == game.QUIT:
            pygame.quit()
            sys.exit()
    f = open("data.txt")
    data1 = []
    cache = []
    for i in range(3):
        f.readline()
    for i in range(100):
        t = f.readline()
        for j in t.split():
            if int(j) != -1:
                cache.append(int(j))
        data1.append(cache)
        cache = []
    f.close()
    for i in range(win_height//cell_width):
        for j in range(win_width//cell_width):
            #no_game_no_life(data,temp,i,j,win_height//cell_width,win_width//cell_width)
            if data1[i][j]==1:
                pygame.draw.rect(data[i][j].surface,red,data[i][j].surface.get_rect(),10)
            elif data1[i][j]==2:
                pygame.draw.rect(data[i][j].surface,black,data[i][j].surface.get_rect(),10)
            elif data1[i][j]==3:
                pygame.draw.rect(data[i][j].surface,blue,data[i][j].surface.get_rect(),10)
            elif data1[i][j]==4 or data1[i][j]==5 or data1[i][j]==6 :
                pygame.draw.rect(data[i][j].surface,green,data[i][j].surface.get_rect(),10)
            else:
                pygame.draw.rect(data[i][j].surface,white,data[i][j].surface.get_rect(),10)
            win.blit(data[i][j].surface,(j*10,i*10))
    pygame.display.update()
    #input()
    #rewrite(data,temp,win_width//cell_width,win_height//cell_width)
    time.sleep(2)    #fps = 60