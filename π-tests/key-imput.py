 #!/usr/bin/python
# -*- coding: utf-8 -*-
import os, sys


def color_transmitter():
  color_change_dic = {}
  x = 1
  while x == 1 :
    choice = raw_input("> ")
    print choice;
    input_lst = choice.split(" ")
    for elem in input_lst:
      if elem[0] == 'L':
        color_change_dic['L'] = elem[1:]
      if elem[0] == 'R':
        color_change_dic['R'] = elem[1:]
      if elem[0] == 'G':
        color_change_dic['G'] = elem[1:]
      if elem[0] == 'B':
        color_change_dic['B'] = elem[1:]
      if elem[0] == 'D':
        color_change_dic['D'] = elem[1:]
      if elem[0] == 'X':
        sys.exit(0)
    print color_change_dic

def main():
  # This Commandline provides the ability to controll a ToMsRGB controller with I2C
  # Enter the Line 1,2,3, 0 for all; Color R, G or B with number 0-255 - R128; dimmingtime in seconds 0.5, 1, 10…
  # This will send the Color and Dimming info to the controllers and will set your color
  # The script can be quitted by entering just X 

  
  args = sys.argv[1:]

  if args:
    print 'you don\'t need arguments just enter Line and Color like:L2 R255 G0 B126 D1'
    sys.exit(1)
  
  # +++your code here+++
  # For each filename, get the names, then either print the text output
  # or write it to a summary file
  color_transmitter()

  
  
if __name__ == '__main__':
  main()
