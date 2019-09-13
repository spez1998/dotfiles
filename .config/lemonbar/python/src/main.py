import os
import sys
import configparser

class Bar:
    def __init__(self,settings):
        self.conf_admiral = settings[0]
        self.width = settings[1]
        self.height = settings[2]
        

def fifo():
    path = "/home/sujit/.config/lemonbar/python/fifo/data"
    fifo = open(path, "r")
    for i in fifo:
        print(i)
    fifo.close()

def ini_parser():
    parser = configparser.ConfigParser()
    parser.read('../conf/config.ini')
    print(parser.sections())
    sections = parser.sections()[0]
    settings = [parser.get(sections,i) for i in parser[sections]]
    bar_inst = Bar(settings)

ini_parser()
