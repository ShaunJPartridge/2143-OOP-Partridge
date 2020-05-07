import pygame, sys
import math
import random
from config import Config

YELLOW = (255,255,51) #RGB values here
RED = (255,51,51)
GREEN = (51,255,51)
BLACK = (0,0,0) 
Background = BLACK

class Person(pygame.sprite.Sprite):
    def __init__(self):
        #self.x
        #self.y
        #self.width
        #self.height
        self.n
        self.color
        self.state = []
        self.daily_interactions = 0
        self.travel_radius = 0.0
        self.symptomatic = True
        self.days_infectious = 0

    def set_state(self,i=0):
        if i == 1:
            self.state.append("susceptible")
        if i == 2:
            self.state.append("infected")
        if i == 3:
            self.state.append("recovered")

    def get_state(self):
        return self.state

    def move(self):    


class Community:
    def __init__(self):
        self.People = []
        self.community = []
        self.screen
        self.boundaries = [200,200,200,200]
        self.image
        self.social_distancing = True
        self.social_distance = 0
        P = Person()

        #super().__init__()
        #self.image = pygame.Surface([boundaries])
        #self.image.fill(Background)
        #pygame.draw.circle


    def create_community(self,num = 0):
        
        pygame.init()

        self.community = pygame.sprite.Group()
        self.screen = pygame.display.set_mode([Config.height,Config.width])

        for i in range(num):
            x = random.randint(1,3)
            person = Person(x,color=RED)
            community.add(person)
        
        T = 200
        clock = pygame.time.Clock()
        for i in range(T):
            foe event


    


class Simulation:

    def __init__(self):
        # get these values from Population class
        
        self.N = 0
        self.I0 = 1
        self.R0 = 0
        self.S0 = 0
    
        self.beta = 0.0
        self.gamma = 0.0
        self.People = []
        P = Person()

    def get_Sim(self):
        #values = [self.N, self.I0, self.R0, self.S0, self.beta, self.gamma]
        
        return self.N, self.I0, self.R0, self.S0, self.beta, self.gamma


    def Set_Sim(self,n,i,r,s,b,g):
        self.N = n
        self.I0 = i
        self.R0 = r
        self.S0 = s
        self.beta = b
        self.gamma = g
        
    
    def addPeople(self,num = 0):
        for i in range(0,num):
            self.People.append(i)
            self.N += 1
        

    def Equations(self):
        dSdt = -(self.beta) * self.S0 * self.I0 / self.N
        dIdt = self.beta * self.S0 * self.I0 / (self.N - (self.gamma * self.I0))
        dRdt = self.gamma * self.I0
        return dSdt, dIdt, dRdt

    def Run_Sim(self):
        pygame.init()

        # Set up the drawing window
        screen = pygame.display.set_mode([Config.width, Config.height])
        pygame.quit()
        



if __name__=='__main__':

    #pygame.init()

    sim = Simulation()        
    sim.Set_Sim(100,10,5,85,.2,.25) 
    sim.get_Sim()
    sim.Equations()
    print(sim.Equations())
    
    sim.Run_Sim()
    
    #s.append(sim.Get_Sim(self))
    peeps = []
   
    i = " "
    p = Person()
    c = Community()

    for j in range(10):
        j = random.randint(1,3)
        p.set_state(j)
        i = p.get_state()
        #c.create_community(p)
        #print(c)
        peeps.append(i)
        print(p.state)
    #print(len(peeps))
    
    for i in range(14):
        sim.People.append(i)
    print(len(sim.People))

    #print(sim.People)
    #print(sim.N)