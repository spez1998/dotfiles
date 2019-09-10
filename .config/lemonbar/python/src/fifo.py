import os
import sys

path = "/home/sujit/.config/lemonbar/python/data"
fifo = open(path, "r")
for i in fifo:
    print(i)
fifo.close()

