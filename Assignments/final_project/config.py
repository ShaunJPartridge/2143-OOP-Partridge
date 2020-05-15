class Config:
    width = 1024
    height = 768
    sprite_images = {
        "red" : "./images/pac_red_30x30.png",
        "yellow" : "./images/pac_yellow_30x30.png",
        "green" : "./images/pac_green_30x30.png"
    }
    social_distancing = False
    infection_radius = 10
    infection_rate = .20
    population_count = 16
    sprite_width = 15
    sprite_height = 15
    sprite_speed = 2
Config.contacts = 5
Config.colors = ["yellow","red","green"]
Config.states = ["susceptible","infected","recovered"]
Config.width = 400
Config.height = 400
Config.pid = 1
Config.loops = 0
Config.days = 0

if __name__=='__main__':
    print("I'm testing config!")
