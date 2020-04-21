
# Import and initialize the pygame library
import pygame
import random
import math
from config import Config

"""
Pygame hello world: Print a circle in middle of screen.
dictionary {} key value pairs
list [] collection of anything
tuple () a "set" immutable
L = [10,"hello","goodbye",3.14159,[0,1,2,3,4]]
print(L[4][2])
Data = {"infected":3456789,"immune":9,"susceptible":74747474,"dead_names":["terry","whoever"]}
print(Data["dead_names"][0])
x,y = (34,78)
"""


class Person(pygame.sprite.Sprite):
    """
    This class represents the ball.
    It derives from the "Sprite" class in Pygame
    """
 
    def __init__(self,screen_width,screen_height,color,width=15,height=15,speed=7):
        """ Constructor. Pass in the color of the block,
        and its size. """
         # Call the parent class (Sprite) constructor
        super().__init__()

        self.state = "susceptible"

        self.screen_width = screen_width
        self.screen_height = screen_height

        self.width = width
        self.height = height

        self.dx = random.choice([-1,1])
        self.dy = random.choice([-1,1])

        # pixels per game loop
        self.speed = speed
        self.speed = speed

        self.color = color

        # Create an image of the block, and fill it with a color.
        # This could also be an image loaded from the disk.

    
        self.image = pygame.image.load(Config.sprite_images[self.color]) 

        self.image = pygame.transform.scale(self.image, (self.width, self.height))
 
        # Fetch the rectangle object that has the dimensions of the image.
        # Update the position of this object by setting the values
        # of rect.x and rect.y

        x = int(random.random()*self.screen_width)
        y = int(random.random()*self.screen_height)

        self.rect = self.image.get_rect(center=(x,y))


    def move(self):
        # ones = [1] * 10
        # negs = [-1] * 5

        # rdx = ones+negs
        # rdy = ones+negs

        # random.shuffle(rdx)
        # random.shuffle(rdy)

        self.check_bounds()

        self.rect.x += self.speed * self.dx
        self.rect.y += self.speed * self.dy

    def check_bounds(self):

        if self.rect.x >= self.screen_width or self.rect.x <= 0:
            self.dx *= -1
        
        if self.rect.y >= self.screen_height or self.rect.y <= 0:
            self.dy *= -1

    def determineSides(self, other):
        """ Determines where the sprite is in relation to other, kind of like
            "top left" or "bottom right".
            Returns: List of sides  (e.g ['right','bottom'])
        """
        d = []
        if self.rect.midtop[1] < other.rect.midtop[1]:
            d.append("top")
        if self.rect.midleft[0] < other.rect.midleft[0]:
            d.append("left")
        if self.rect.midright[0] > other.rect.midright[0]:
            d.append("right")
        if self.rect.midbottom[1] > other.rect.midbottom[1]:
            d.append("bottom")

        return d
    
    def changeDirection(self,other):
        sides = self.determineSides(other)
        if "right" in sides:
            self.dx *= -1
        if "left" in sides:
            self.dx *= -1
        if "top" in sides:
            self.dy *= -1
        if "bottom" in sides:
            self.dy *= -1

    def collide(self,other, social_distance=20):

        # if not other.state == "infected":
        #     return

        x1, y1 = self.rect.center
        x2, y2 = other.rect.center

        d = math.sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))

        if d < social_distance:
            self.changeDirection(other)

        if d < self.width:
            self.image = pygame.image.load(Config.sprite_images["red"]) 
            self.image = pygame.transform.scale(self.image, (self.width, self.height))


        # if abs(self.rect.x - other.rect.x) < self.width and abs(self.rect.y - other.rect.y) < self.height:
        #     self.image = pygame.image.load(sprite_images["red"]) 
        #     self.image = pygame.transform.scale(self.image, (self.width, self.height))
            


if __name__=='__main__':
    pygame.init()

    # Set up the drawing window
    screen = pygame.display.set_mode([Config.width, Config.height])

    # sprites should be in a group
    sprites_list = pygame.sprite.Group()

    # a list to hold all of our people sprites
    people = []

    # list of colors
    colors = ["blue","light_blue","white","yellow","orange","green"]
    speeds = [x for x in range(1,3)]


    for i in range(100):
        # add a "person" to our list of people
        # create an "instance" of our class
        people.append(Person(Config.width, Config.height, random.choice(colors),15,15,1)) #random.choice(speeds)

        # Add last person to our sprites list
        # list[-1] give you the last item
        sprites_list.add(people[-1])  

        clock=pygame.time.Clock()

    # Run until the user asks to quit
    running = True

    while running:

        # Did the user click the window close button?
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        # Fill the background with white
        screen.fill( (30, 30, 30) )

        red = 0
        green = 0
        blue = 255

        sprites_list.draw(screen)

        for p in people:
            p.move()
            for sp in people:
                if not p == sp:
                    p.collide(sp)


        # Flip the display
        pygame.display.flip()

        #Number of frames per secong e.g. 60
        clock.tick(40)

    # Done! Time to quit.
    pygame.quit()