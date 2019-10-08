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
#include "Ram.hpp"

Ram::Ram()
{
    this->_name = "Ram";
    this->setActive(true);
    this->refreshInfos();
}

Ram::~Ram()
{
}

void Ram::refreshInfos()
{
    std::string contenu = "ERROR";
    float val1 = 0;
    float val2 = 0;
    std::ifstream fichier("/proc/meminfo", std::ios::in);
    int read = 0;
    int index = 4;
    std::size_t pos;
    std::string::npos;

    if (!fichier)
    {
        this->_infos = "ERROR";
        return;
    }
    this->_infos = "";
    while (read != 2 && getline(fichier, contenu))
    {
        pos = contenu.find("MemTotal:");
        if (pos != std::string::npos)
        {
            std::string toto = contenu.substr(16);
            this->_infos.append(toto);
            this->_infos.append(" ");
            read++;
        }
        pos = contenu.find("MemAvailable:");
        if (pos != std::string::npos)
        {
            std::string toto = contenu.substr(16);
            this->_infos.append(toto);
            this->_infos.append("\n");
            read++;
        }
    }
    std::string stock = this->_infos;
    val1 = (std::stod(this->_infos.substr(1, 7)) / 1024) / 1000;
    val2 = (std::stod(this->_infos.substr(13, 18)) / 1024) / 1000;
    this->_infos = "Mem[                                        ]";
    int test = ((val1 - val2) * 100) / val1;
    while (this->_infos[index + 1])
    {
        if ((index - 4) * 2 < test)
        {
            this->_infos[index] = '|';
        }
        index++;
    }
    this->_infos.append("\n");
    this->_infos.append(std::to_string(val1 - val2));
    this->_infos.append("G/");
    this->_infos.append(std::to_string(val1));
    this->_infos.append("G");
}

std::string Ram::getInfos() const
{
    return (this->_infos);
}

void Ram::setActive(bool active)
{
    this->_active = active;
}

bool Ram::getActive() const
{
    return (this->_active);
}

std::string Ram::getName() const
{
    return (this->_name);
}