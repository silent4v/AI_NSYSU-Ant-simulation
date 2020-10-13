import sys,time,random,pygame
import pygame.locals as game
from Cell import Cell,no_game_no_life,rewrite
#pixel
win_height = 720
win_width = 1280
cell_width = 10
#color
white = (255,255,255)
black = (0,0,0)
#initialize
pygame.init()
win_size = (win_width,win_height)
win = pygame.display.set_mode(win_size)
pygame.display.set_caption('Convey No Game No Life')
win.fill(white)
data = [[Cell(random.randint(0,1),cell_width) for j in range(win_width//cell_width)]for i in range(win_height//cell_width)]
temp = [[random.randint(0,1) for j in range(win_width//cell_width)]for i in range(win_height//cell_width)]
#
while True:
    for event in pygame.event.get():
        if event.type == game.QUIT:
            pygame.quit()
            sys.exit()
    for i in range(win_height//cell_width):
        for j in range(win_width//cell_width):
            no_game_no_life(data,temp,i,j,win_height//cell_width,win_width//cell_width)
            if temp[i][j]:
                pygame.draw.rect(data[i][j].surface,black,data[i][j].surface.get_rect(),10)
            else:
                pygame.draw.rect(data[i][j].surface,white,data[i][j].surface.get_rect(),10)
            win.blit(data[i][j].surface,(j*10,i*10))
    pygame.display.update()
    rewrite(data,temp,win_width//cell_width,win_height//cell_width)
    time.sleep(1/60)    #fps = 60