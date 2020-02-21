// screen emulator for kolibri

#include <stdlib.h>
#include <ncurses.h>
#include "main.h"

int Win_Rows = 26;
int Win_Cols = 80;

WINDOW *BoW;
WINDOW *BoD;
WINDOW *Win;
WINDOW *Deb;

void Init_SEM()
{
   printf("Init SEM\n");
   initscr();
   nocbreak();
   keypad(stdscr,TRUE);
   clear();
   atexit(Exit_SEM);

   // Create outer windows for borders

   BoW = newwin(Win_Rows+2, Win_Cols+2, 0, 0);
   BoD = newwin(Win_Rows+2, Win_Cols+2, Win_Rows+2, 0);
   box(BoW,ACS_VLINE,ACS_HLINE);
   box(BoD,ACS_VLINE,ACS_HLINE);
   mvwaddstr(BoW,0,33,"Kolibri Window");
   mvwaddstr(BoD,0,34,"Debug Window");

   // Create inner windows for content

   Win = derwin(BoW, Win_Rows, Win_Cols, 1, 1);
   Deb = derwin(BoD, Win_Rows, Win_Cols, 1, 1);
   immedok(Win,TRUE);
   scrollok(Win,TRUE);
   immedok(Deb,TRUE);
   scrollok(Deb,TRUE);
   wclear(Win);
   wclear(Deb);

   // Display borders

   wrefresh(BoW);
   wrefresh(BoD);

}

void Exit_SEM()
{
   endwin();
}
