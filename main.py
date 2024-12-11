# imports
import os
import sys
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
# i will not reinvent the wheel i will not reinvent the wheel i will n
import pygame as pg
import pygame.image

# ddr imports
from src.window import *
import src.entities as ent


##########################################

FONT = pygame.font.SysFont('res/courierstuck.ttf', 30)

background = pygame.image.load(IMGPATH + 'bkg.png')
fore1 = pygame.image.load(IMGPATH + 'bottom_bar.png')
fore2 = pygame.image.load(IMGPATH + 'top_bar.png')

bgl = {
    0: {'image': background, 'pos': (0, 0)},
    1: {'image': fore1, 'pos': (0, SCREEN_HEIGHT - fore1.get_rect().bottom)},
    2: {'image': fore2, 'pos': (0, 0)}
}

receptors = []
arrows = {
    'L': [],
    'R': [],
    'D': [],
    'U': []
}


# Main function
def main():
    # Left receptor (arrow), player 1
    receptors.append(ent.receptor('L', coords['L']))
    receptors.append(ent.receptor('D', coords['D']))
    receptors.append(ent.receptor('U', coords['U']))
    receptors.append(ent.receptor('R', coords['R']))

    arrows['L'].append(ent.arrow('L', (coords['L'][0], 400), 1))
    arrowbuffer = 30
    points = 0

    # frame loop
    while True:
        keys = pg.key.get_pressed()
        # if left arrow key pressed
        if keys[pg.K_LEFT]:
            for i in range(len(arrows['L'])):
                delta = abs(arrows['L'][i].pos.centery - r_center[1])
                if delta <= arrowbuffer:
                    points += arrowbuffer - delta
                    arrows['L'].pop(i)
                    arrows['L'].append(ent.arrow('L', (coords['L'][0], 400), 1))

        # update graphics in window
        for i in bgl:
            WINDOW.blit(bgl[i]['image'], bgl[i]['pos'])
        for r in receptors:
            WINDOW.blit(r.image, r.pos)
        for a in arrows['L']:
            a.move()
            WINDOW.blit(a.image, a.pos)

        WINDOW.blit(FONT.render(str(int(points)), True, BLACK), (30, SCREEN_HEIGHT-50))

        # exit if closed
        for event in pygame.event.get():
            if event.type == pygame.locals.QUIT:
                print(f'Points: {points:.0f}')
                pg.quit()
                sys.exit()

        pygame.display.update()


# Execute main function
if __name__ == '__main__':
    main()
