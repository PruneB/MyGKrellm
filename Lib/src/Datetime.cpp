/*
** Epitech Bordeaux Promo 2022
** Gau Florian
** Datetime.hpp
** hpp contain class datetime for stock information rush3
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include "Datetime.hpp"

Datetime::Datetime()
{
	this->_name = "Datetime";
	this->setActive(true);
	this->refreshInfos();
}

Datetime::~Datetime()
{}

std::string Datetime::getInfos() const
{
	return (this->_infos);
}

void Datetime::refreshInfos()
{
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);
	this->_day = newTime1->tm_mday;
	this->_hours = newTime1->tm_hour;
	this->_minutes = newTime1->tm_min;
	this->_mounth = newTime1->tm_mon + 1;
	this->_seconds = newTime1->tm_sec;
	this->_year = newTime1->tm_year + 1900;
	this->_infos = "";
	this->_infos.append(std::to_string(this->_day));
	this->_infos.append("/");
	this->_infos.append(std::to_string(this->_mounth));
	this->_infos.append("/");
	this->_infos.append(std::to_string(this->_year));
	this->_infos.append("\n");
	this->_infos.append(std::to_string(this->_hours));
	this->_infos.append(":");
	this->_infos.append(std::to_string(this->_minutes));
	this->_infos.append(":");
	this->_infos.append(std::to_string(this->_seconds));
}

void Datetime::setActive(bool active)
{
	this->_active = active;
}

bool Datetime::getActive() const
{
	return (this->_active);
}

int Datetime::GetYear()
{
	return (this->_year);
}

int Datetime::GetMounth()
{
	return (this->_mounth);
}

int Datetime::GetDay()
{
	return (this->_day);
}

int Datetime::GetHours()
{
	return (this->_hours);
}

int Datetime::GetMinutes()
{
	return (this->_minutes);
}

int Datetime::GetSeconds()
{
	return (this->_seconds);
}

std::string Datetime::getName() const
{
	return (this->_name);
}