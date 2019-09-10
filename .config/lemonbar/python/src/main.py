import os
import sys

path = "/home/sujit/.config/lemonbar/python/fifo/data"
fifo = open(path, "r")
for i in fifo:
    print(i)
fifo.close()

