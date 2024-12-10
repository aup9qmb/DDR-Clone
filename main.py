# imports
import sys

import pygame.image

# ddr imports
from src.utils import *
import src.entities as ent

# initialize engine, create window
pygame.init()

WINDOW = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
WINDOW.fill(WHITE)
ICON = pygame.image.load(IMGPATH + "R_arrow_active.png")
pygame.display.set_caption("DDR-Clone")
pygame.display.set_icon(ICON)

##########################################
background = pygame.image.load(IMGPATH + 'bkg.png')
fore1 = pygame.image.load(IMGPATH + 'bottom_bar.png')
fore2 = pygame.image.load(IMGPATH + 'top_bar.png')

bgl = {
    0: {'image': background, 'pos': (0, 0)},
    1: {'image': fore1, 'pos': (0, SCREEN_HEIGHT - fore1.get_rect().bottom)},
    2: {'image': fore2, 'pos': (0, 0)}
}
arrows = []


# Main function
def main():
    print(bgl[1]['pos'])
    while True:
        for i in bgl:
            WINDOW.blit(bgl[i]['image'], bgl[i]['pos'])

        for a in arrows:
            WINDOW.blit(background, a.pos, a.pos)

        ent.arrow('U').draw(WINDOW)

        for event in pygame.event.get():
            if event.type == pygame.locals.QUIT:
                pygame.quit()
                sys.exit()

        pygame.display.update()


# Execute main function
if __name__ == '__main__':
    main()
