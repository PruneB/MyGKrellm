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
#include "Kernel.hpp"

Kernel::Kernel()
{
	this->_name = "Kernel";
    this->_kernel = "ERROR";
    this->_version = "ERROR";
	this->setActive(true);
    this->refreshInfos();
}

Kernel::~Kernel()
{
}

void Kernel::refreshInfos()
{
    std::string contenu = "ERROR";
    std::ifstream fichier("/proc/version", std::ios::in);
    int index = 0;

    this->_kernel = "ERROR";
    this->_version = "ERROR";
    if (fichier) {
        this->_kernel = "";
        this->_version = "";
        getline(fichier, contenu);
        while (contenu[index++] != ' ');
        contenu[index - 1] = '\n';
        while (contenu[index++] != ' ');
        while (contenu[index++] != ' ');
        contenu.substr(1, index);
        fichier.close();
        this->_infos = "";
        this->_infos.append("Kernel: ");
        this->_infos.append(contenu.substr(0, index));
    } else {
        this->_infos = "";
        this->_infos.append("Kernel: ");
        this->_infos.append("ERROR");
    }
}

std::string Kernel::getInfos() const
{
    return (this->_infos);
}

void Kernel::setActive(bool active)
{
	this->_active = active;
}

bool Kernel::getActive() const
{
    return (this->_active);
}

std::string Kernel::getName() const
{
    return (this->_name);
}