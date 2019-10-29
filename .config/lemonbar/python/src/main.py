import os
import sys
import configparser

class Bar:
    def __init__(self,keys,values):
        #self.conf_admiral = settings[0]
        #self.width = settings[1]
        #self.height = settings[2]
        #self.bg_color = settings[3]
        #self.fg_color = settings[4]
        #self.click = settings[5]
        #self.font_1 = settings[6]
        #self.font_2 = settings[7]
        #self.perm = settings[8]
        for i in keys:
            self.i = "poo"
        # I want to create a new attribute with the name self.x, where x is an element of keys, and
        # I want that self.x to take the corresponding value of y for all y in values.

    def poonull(self,settings):
        for i in settings:
            if i:
                print("poo")
            else:
                print("got you")

    def stdout(self):
        dimensions = f"-g {self.width}x{self.height}"
        color = f"-B '{self.bg_color}' -F '{self.fg_color}'"
        fonts = f"-f {self.font_1} -f {self.font_2}"
        stdout_msg = f"admiral -c {self.conf_admiral} | lemonbar {dimensions} {color} -a {self.click} {fonts} -p"
        print(stdout_msg)

def fifo():
    path = "/home/sujit/.config/lemonbar/python/fifo/data"
    fifo = open(path, "r")
    print(*fifo, sep="\n")
    fifo.close()

def ini_parser():
    parser = configparser.ConfigParser()
    parser.read('../conf/config.ini')
    section_0 = parser.sections()[0]
    keys = [i for i in parser[section_0]]
    values = [parser[section_0][i] for i in parser[section_0]]
    print(keys,values)
    bar_inst = Bar(keys,values)
    #bar_inst.poonull(keys,values)
    #bar_inst.stdout()

ini_parser()

