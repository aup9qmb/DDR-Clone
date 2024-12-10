from src.utils import *

#########################################


class arrow(pygame.sprite.Sprite):

    def __init__(self, direction):
        super().__init__()
        texture = f'res/images/{direction}_arrow_active.png'
        self.image = pygame.image.load(texture)
        self.rect = self.image.get_rect()

        # center object in window
        self.rect.center = (SCREEN_WIDTH/2, SCREEN_HEIGHT/2)

    def retexture(self, texture):
        self.image = pygame.image.load(texture)
        self.rect = self.image.get_rect()

    def move(self):
        self.rect.move_ip(0, 10)
        if (self.rect.bottom > 600):
            self.rect.top = 0
            self.rect.center = (SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)

    def draw(self, surface):
        surface.blit(self.image, self.rect)


########################################

