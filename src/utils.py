import pygame.locals

FPS = pygame.time.Clock()
FPS.tick(60)

IMGPATH = 'res/images/'

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Screen information
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480



delx = 5
w = 32
r_center = (int(SCREEN_WIDTH / 6), 70)
L_coord = r_center[0] - 1.5 * (w + delx), r_center[1]
D_coord = r_center[0] - 0.5 * (w + delx), r_center[1]
U_coord = r_center[0] + 0.5 * (w + delx), r_center[1]
R_coord = r_center[0] + 1.5 * (w + delx), r_center[1]

coords = {'L': L_coord, 'D': D_coord, 'U': U_coord, 'R': R_coord}
