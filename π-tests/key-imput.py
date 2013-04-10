#keyboard inputs

#import curses
#stdscr = curses.initscr()
#c = stdscr.getch()
#print 'you entered', chr(c)
#curses.endwin()

color_change_dic = {}

x = 1
while x == 1 :
    print ('enter Line and Color like:L2 R255 G0 B126 D1')
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
    print color_change_dic

#raw_input("Press Enter to continue...")