/*
** EPITECH PROJECT, 2019
** pool
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <string>
#include "Datetime.hpp"
#include "Host.hpp"
#include "Kernel.hpp"
#include "Cpu.hpp"
#include "Ram.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Ncurses : virtual public IMonitorDisplay
{
  public:
    Ncurses();
    ~Ncurses();

    void addModule(const std::string &);
    void deleteModule(const std::string &);
    void displayWallpaper();

  protected:
  private:
};

#endif /* !NCURSES_HPP_ */
