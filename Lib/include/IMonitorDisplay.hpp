/*
** EPITECH PROJECT, 2019
** pool
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <vector>
#include "IMonitorModule.hpp"

class IMonitorDisplay
{
  public:
    virtual ~IMonitorDisplay(){};

    virtual void addModule(const std::string &name) = 0;
    virtual void deleteModule(const std::string &name) = 0;

  protected:
    IMonitorModule *_host;
    IMonitorModule *_time;
    IMonitorModule *_kernel;
    IMonitorModule *_cpu;
    IMonitorModule *_ram;
    // IMonitorModule *_host;
  private:
};

#endif /* !IMONITORDISPLAY_HPP_ */
