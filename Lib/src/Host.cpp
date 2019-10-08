/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Host.hpp
** hpp contain class Host for stock information rush3
*/

#include "Host.hpp"

Host::Host()
{
	this->_name = "Host";
	this->setActive(true);
    this->refreshInfos();
}

Host::~Host()
{
}

std::string Host::GetUser()
{
    return (this->_username);
}

std::string Host::GetHost()
{
    return (this->_hostname);
}

void Host::refreshInfos()
{
    this->_hostname = std::getenv("HOSTNAME");
    this->_username = std::getenv("LOGNAME");
    if (this->_hostname == nullptr) {
        this->_hostname = (char*)"ERROR";
    }
    if (this->_username == nullptr) {
        this->_username = (char*)"ERROR";
    }
	this->_infos = "";
	this->_infos.append("User: ");
	this->_infos.append(this->_username);
	this->_infos.append("\n");
	this->_infos.append("Hostname: ");
	this->_infos.append(this->_hostname);
}

std::string Host::getInfos() const
{
    return (this->_infos);
}

void Host::setActive(bool active)
{
	this->_active = active;
}

bool Host::getActive() const
{
    return (this->_active);
}

std::string Host::getName() const
{
    return (this->_name);
}