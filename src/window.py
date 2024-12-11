import pygame.image
from src.utils import *


# initialize engine, create window
pygame.init()

WINDOW = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
WINDOW.fill(WHITE)
ICON = pygame.image.load(IMGPATH + "R_arrow_active.png")
pygame.display.set_caption("DDR-Clone")
pygame.display.set_icon(ICON)