#include <iostream>
#include <string>
#include <stdlib.h>
#include <ncurses.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "IMonitorDisplay.hpp"
#include "def.hpp"
#include "Sfml.hpp"
#include "Ncurses.hpp"
#include "Datetime.hpp"
#include "Host.hpp"
#include "Kernel.hpp"
#include "Cpu.hpp"

static void flags(int ac, char **av, UNUSED IMonitorDisplay *display)
{
    if (ac == 1)
    {
        WINDOW *mid;

        initscr();
        mid = subwin(stdscr, LINES / 2, COLS / 2, LINES / 4, COLS / 4);
        box(mid, ACS_VLINE, ACS_HLINE);
        keypad(mid, true);
        mvwprintw(mid, LINES / 8, COLS / 5.5, "Quel version voulez-vous?");
        mvwprintw(mid, LINES / 6, COLS / 6, "NCurses");
        mvwprintw(mid, LINES / 6, COLS / 3.5, "SFML");
        Ncurses ncurses;
        Sfml sfml;

        while (1)
        {
            int c = wgetch(mid);
            switch (c)
            {
            case KEY_LEFT:
                ncurses.displayWallpaper();
                break;
            case KEY_RIGHT:
                sfml.InitWindow();
                break;
            }
            if (c == KEY_UP || c == KEY_DOWN)
                break;
            break;
        }
        endwin();
        exit(0);
    }
    else
    {
        if (strcmp(av[1], "-sfml") == 0)
        {
            Sfml sfml;
            sfml.InitWindow();
            display = &sfml;
        }
        else if (strcmp(av[1], "-ncurses") == 0)
        {
            Ncurses ncurses;
            ncurses.displayWallpaper();
            display = &ncurses;
        }
        else
        {
            std::cout << "Usage: ./MyGKrellm [-sfml | -ncurses]" << std::endl;
            std::cout << "\t-sfml    : launch MyGKrellm in graphical mode" << std::endl;
            std::cout << "\t-ncurses : launch MyGKrellm in terminal mode" << std::endl;
            exit(0);
        }
    }
}

int main(int ac, char **av)
{
    IMonitorDisplay *display = nullptr;
    flags(ac, av, display);
    return (0);
}