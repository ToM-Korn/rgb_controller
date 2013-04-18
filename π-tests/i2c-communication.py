#!/usr/bin/python
# -*- coding: utf-8 -*-
import os, sys
import smbus
import time

bus = smbus.SMBus(0)

addresses_dic = {'line1':0x32,'line2':0x28,'line3':0x29,'bc':0x0} 
 
bus = smbus.SMBus(1)
 

def color_transmitter():
  j = 0
  colors_lst = ['R','G','B']
  i = 0
  while i < 10:
    print j
    j+=1
    for address in addresses_dic:
      print address
      for color in colors_lst: 
        bus.write_byte(addresses_dic[address],ord("C"))
        bus.write_byte(addresses_dic[address],ord(color))
        bus.write_byte(addresses_dic[address],255)
        
        time.sleep(0.1)        
        
        bus.write_byte(addresses_dic[address],ord("C"))
        bus.write_byte(addresses_dic[address],ord(color))      
        bus.write_byte(addresses_dic[address],0)
    
        time.sleep(0.1)
     
  

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