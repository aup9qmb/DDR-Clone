# imports
import os
import sys
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
# i will not reinvent the wheel i will not reinvent the wheel i will n
import pygame.image

# ddr imports
from src.window import *
import src.entities as ent


##########################################


background = pygame.image.load(IMGPATH + 'bkg.png')
fore1 = pygame.image.load(IMGPATH + 'bottom_bar.png')
fore2 = pygame.image.load(IMGPATH + 'top_bar.png')

bgl = {
    0: {'image': background, 'pos': (0, 0)},
    1: {'image': fore1, 'pos': (0, SCREEN_HEIGHT - fore1.get_rect().bottom)},
    2: {'image': fore2, 'pos': (0, 0)}
}

receptors = []
arrows = []


# Main function
def main():
    # Left receptor (arrow), player 1
    receptors.append(ent.receptor('L', coords['L']))
    receptors.append(ent.receptor('D', coords['D']))
    receptors.append(ent.receptor('U', coords['U']))
    receptors.append(ent.receptor('R', coords['R']))

    arrows.append(ent.arrow('L', (coords['L'][0], 400), 1))

    while True:
        # update background assets
        # blit(source, dest, area) -> Rect
        for i in bgl:
            WINDOW.blit(bgl[i]['image'], bgl[i]['pos'])
        for r in receptors:
            WINDOW.blit(r.image, r.pos)
        for a in arrows:
            WINDOW.blit(a.image, a.pos)

        arrows[0].move(coords['L'][1])

        # exit if closed
        for event in pygame.event.get():
            if event.type == pygame.locals.QUIT:
                pygame.quit()
                sys.exit()

        pygame.display.update()


# Execute main function
if __name__ == '__main__':
    main()
