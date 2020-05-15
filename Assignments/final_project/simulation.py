import pygame, sys
import math
import random
from config import Config
black = (0,0,0) 


class Person(pygame.sprite.Sprite):
    """
    This class represents the ball.
    It derives from the "Sprite" class in Pygame
    """
    def __init__(self,
                 color,
                 width=15,
                 height=15,
                 speed=1,inx=None,iny=None):
        """ Constructor. Pass in the color of the block,
        and its size. """
        # Call the parent class (Sprite) constructor
        super().__init__()
        #self.id = Config.pid

        # Helper member variables
        self.contacts = 0
        self.colors = ["yellow","red","green"]
        self.state = random.choice(Config.states)

        self.in_recovery = False
        self.recovered = False
        self.days_infectious = 0

        
        #self.state = Config.states#delete if doesnt work?
        self.color = color# was just color before
        #self.color = random.choice(self.colors)
        
        # screen width and height used to know
        # when to change direction at edge of screen
        self.screen_width = Config.width
        self.screen_height = Config.height

        # size of our sprite
        self.width = width
        self.height = height

        # direction x and direction y
        self.dx = random.choice([-1, 1])
        self.dy = random.choice([-1, 1])

        speeds = range(1,6)
        # pixels per game loop
        #self.speed = random.choice([1,7])
        self.speed = speed

        #self.color = color
        self.social_distance = 0
        #if self.state == "susceptible":
            #self.color = 


        # Create an image of the block, and fill it with a color.
        # This could also be an image loaded from the disk.

        # pygame thing
        self.image = pygame.image.load(Config.sprite_images[self.color])
        # pygame thing
        self.image = pygame.transform.scale(self.image,
                                            (self.width, self.height))

        #assigns a color to each state
        if self.color == "yellow":
            self.state = "susceptible"
        if self.color == "red":
            self.state = "infected"
        if self.color == "green":
            self.state = "recovered"

        # Fetch the rectangle object that has the dimensions of the image.
        # Update the position of this object by setting the values
        # of rect.x and rect.y

        if inx is None:
            # creates a random location between bounds of screen size
            x = int(random.random() * self.screen_width)
        else:
            x = inx

        if iny is None:
            # creates a random location between bounds of screen size
            y = int(random.random() * self.screen_height)
        else:
            y = iny

        # pygame thing
        self.rect = self.image.get_rect(center=(x, y))

        self.lastDirectionChange = 0

    def move(self):
        """move : moves our sprite around the screen
        """
        self.check_bounds()

        # add speed pixels to current location
        # multiplied by direction

        # pygame thing
        self.rect.x += self.speed * self.dx
        self.rect.y += self.speed * self.dy

        if self.in_recovery:
            self.days_infectious -= 1

            if self.days_infectious <= 0:
                self.in_recovery = False
                self.recovered = True

        #self.rect.x = int(random.random() * self.screen_width)
        #self.rect.y = int(random.random() * self.screen_height)

    def check_bounds(self):# put in simulaton class??
        """check_bounds: checks to see if we are still on the screen.
           If not, we reverse direction.
        """
        # if our x goes less than zero or more than width negate dx.
        if self.rect.x >= self.screen_width-self.width or self.rect.x <= 0:
            self.dx *= -1

        #
        if self.rect.y >= self.screen_height-self.width or self.rect.y <= 0:
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
        
        #print(f"{self.color} {sides}")
        if "right" in sides:
            self.dx = -1
            #self.rect.x -= 5
        if "left" in sides:
            self.dx = 1
            #self.rect.x += 5
        if "top" in sides:
            self.dy = -1
            #self.rect.y -= 5
        if "bottom" in sides:
            #self.rect.y += 5
            self.dy = 1

    #method to check two peoples state, returns true only when one is susceptible and the other infected 
    def checkstate(self,other):

        if self.state == other.state:
            return False
        if self.state == "infected" and other.state == "susceptible":
            return True
        if self.state == "susceptible" and other.state == "infected":
            return True
        if self.state == "recovered" and other.state == "susceptible":
            return False
        if self.state == "susceptible" and other.state == "recovered":
            return False
        if self.state == "infected" and other.state == "recovered":
            return False
        if self.state == "recovered" and other.state == "infected":
            return False


    def collide(self, other,social_distance,infection_rate):
        """collide : check to see of we hit another sprite
           Params:
               other [Person] : other person getting checked for collision
        """
        # if not other.state == "infected":
        #     return

        # getting x,y for both sprites
        x1, y1 = self.rect.center
        x2, y2 = other.rect.center

        # distance
        d = math.sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
        
        
        if d < social_distance:
            self.changeDirection(other)
            #print(f"d:{d} collision:{self.width*1.2}")

        # if distance is less than some threshold , then do something
        if d < self.width*1 and infection_rate > Config.infection_rate:
            self.contacts += 1
            
            if self.contacts >= Config.contacts and self.checkstate(other):
               #if self.checkstate(other) == True:
                self.image = pygame.image.load(Config.sprite_images["red"])
                self.image = pygame.transform.scale(self.image,
                                               (self.width, self.height))
                self.state = "infected"
            
  
    #function to respawn a person after becoming infected
    def respawn(self,color):
        return Person(self.color,self.width,self.height,self.speed)

    #function to 
    def road_to_recovery(self,days):
        self.in_recovery = True
        self.days = days


class Simulation:
    def __init__(self,n_sus,n_inf,time):#pass in values for simulation instead of nums of people
        self.infection_rate = None
        self.social_distance = None

        self.sus_container = pygame.sprite.Group()
        self.inf_container = pygame.sprite.Group()
        self.rec_container = pygame.sprite.Group()
        self.pop_container = pygame.sprite.Group()

        self.n_sus = n_sus
        self.n_inf = n_inf
        self.num_people = self.n_sus + self.n_inf
        self.days = int (time / 7)
        self.days_to_recovered = 14
        self.recovery_rate = 0.2

    def RunSim(self,social_distance,infection_rate):
        #self.num_people = self.n_sus + self.n_inf

        pygame.init()

            # Set up the drawing window
        screen = pygame.display.set_mode([Config.width, Config.height])

            # sprites should be in a sprite group
        people = []
        recovered = []
            # list of colors
            #pythonic
        
        for i in range(self.n_sus):
            # add a "person" to our list of people
            # create an "instance" of our class
            p = Person("yellow",15,15,3)
            self.sus_container.add(p)
            self.pop_container.add(p)
            print(p.state)

        for i in range(self.n_inf):

            p = Person("red",15,15,3)
            self.inf_container.add(p)
            self.pop_container.add(p)
            print(p.state)

        clock=pygame.time.Clock()

        # Run until the user asks to quit
        for i in range(self.days):
            # Did the user click the window close button?
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.days = 0
                # handle MOUSEBUTTONUP
                if event.type == pygame.MOUSEBUTTONUP:
                    pos = pygame.mouse.get_pos()
                        #print(pos)

                        # Add last person to our sprites list
                        # list[-1] give you the last item
                    self.pop_container.add(Person(random.choice(Config.colors),15,15,3))

            # Fill the background with blackish
            screen.fill(black)

            for p in self.pop_container:
                p.move()

                for sp in self.pop_container:
                    if not p == sp:
                        p.collide(sp,social_distance,infection_rate)
                        if p.checkstate(sp) and p.days_infectious < self.days_to_recovered:
                            new_person = p.respawn("red")
                            self.n_inf += 1
                            new_person.road_to_recovery(self.days_to_recovered)
                
                            self.inf_container.add(new_person)
        
                    
                for p in self.inf_container:
                    if p.recovered:
                        new_person = p.respawn("green")
                        self.rec_container.add(new_person)
                        recovered.append(p)
                
                    if len(recovered) > 0:
                        self.inf_container.remove(*recovered)
            self.pop_container.update()
            self.pop_container.draw(screen)
                    
            pygame.display.flip()
                
                #Number of frames per secong e.g. 60
            clock.tick(30)
            # Done! Time to quit.
        pygame.quit()
       
if __name__=='__main__':
   
  
   S = Simulation(3,15,15000)
   S.RunSim(20,.58)
