#!/usr/bin/python
# -*- coding: utf-8 -*-
import os, sys
import smbus
import time

bus = smbus.SMBus(0)

#addresses_dic = {'line1':0x28,'line2':0x29,'line3':0x32,'line_broadcast':0x00} 
addresses_dic = {'line_broadcast':0x00} 
 
bus = smbus.SMBus(1)
 
# try self.bus.write_byte(self.addr, ord(cmd), msg) for writing to arduino

def color_transmitter():

  colors_lst = ['R','G','B']
 
  for address in addresses_dic:
  	bus.write_i2c_block_data(addresses_dic[address],ord('c'),128,128,128)
    

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
