/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Kernel.hpp
** hpp contain class Kernel for stock information rush3
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "Cpu.hpp"

Cpu::Cpu()
{
	this->_name = "Cpu";
	this->setActive(true);
    this->refreshInfos();
}

Cpu::~Cpu()
{
}

void Cpu::refreshInfos()
{
    std::string contenu = "ERROR";
    std::ifstream fichier("/proc/cpuinfo", std::ios::in);
    int position = 0;
    std::string stock = "";
    int idx = 0;
    int stk = 0;
    int index = 0;
    std::string::npos;
    float val = 0;
    std::size_t pos = 0;

    if (!fichier) {
        this->_infos = "ERROR";
        return;
    }
    this->_infos = "";
    while (getline(fichier, contenu)) {
        if (position == 0) {
            pos = contenu.find("model name");
            if (pos != std::string::npos) {
                std::string name = contenu.substr(13);
                this->_infos.append(name);
                this->_infos.append("\n");
                position = 1;
            }
        }
        pos = contenu.find("cpu MHz");
        if (pos != std::string::npos) {
            stock = "";
            val = std::stod(contenu.substr(10)) / 100;
            stock.append("CPu");
            stock.append(std::to_string(index));
            stock.append(" [                                        ]");
            while (stock[idx + 7] && val * 2.7 > stk * 2) {
                stk++;
                stock[idx + 6] = '|';
                idx++;
            }
            this->_infos.append(stock);
            this->_infos.append(std::to_string(val));
            this->_infos.append("%\n");
            index++;
            idx = 0;
            stk = 0;
        }
    }

}

std::string Cpu::getInfos() const
{
    return (this->_infos);
}

void Cpu::setActive(bool active)
{
	this->_active = active;
}

bool Cpu::getActive() const
{
    return (this->_active);
}

std::string Cpu::getName() const
{
    return (this->_name);
}