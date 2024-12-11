from src.utils import *
from src.window import WINDOW

#########################################


class arrow(pygame.sprite.Sprite):

    def __init__(self, d, xycoords, speed):
        super().__init__()
        texture = f'res/images/{d}_arrow_active.png'
        self.image = pygame.image.load(texture)
        # speed needs to be calc'd from bpm
        self.speed = speed
        self.rect = self.image.get_rect()
        self.pos = self.image.get_rect().move(xycoords)

        WINDOW.blit(self.image, self.pos)

    def move(self, max_y):
        self.pos.top -= self.speed
        if self.pos.top < 0:
            self.pos.top = 0
        if self.pos.top < max_y:
            self.pos.top = max_y

    def get_area(self):
        area = (int(self.rect.left), int(self.rect.top),
                int(self.rect.width), int(self.rect.height))
        return area

    def retexture(self, texture):
        self.image = pygame.image.load(texture)
        self.rect = self.image.get_rect()


class receptor(pygame.sprite.Sprite):

    def __init__(self, d, xycoords):
        super().__init__()
        texture = f'res/images/{d}_arrow.png'
        self.image = pygame.image.load(texture)
        self.rect = self.image.get_rect()
        self.rect.center = xycoords
        self.pos = self.rect.center
        self.area = (self.rect.left, self.rect.top, self.rect.width, self.rect.height)

        WINDOW.blit(self.image, self.pos)

    def retexture(self, texture):
        self.image = pygame.image.load(texture)
        self.rect = self.image.get_rect()

########################################

