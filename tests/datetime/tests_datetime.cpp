/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <ctime>
#include "Datetime.hpp"

Test(datetime, test_day)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetDay() == newTime1->tm_mday);
	std::cout << "Units Tests **Lib** datetime: Day ====> \tOK" << std::endl;
}

Test(datetime, test_mounth)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetMounth() == 1 + newTime1->tm_mon);
	std::cout << "Units Tests **Lib** datetime: Mounth ====> \tOK" << std::endl;
}

Test(datetime, test_year)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetYear() == 1900 + newTime1->tm_year);
	std::cout << "Units Tests **Lib** datetime: Year ====> \tOK" << std::endl;
}

Test(datetime, test_second)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetSeconds() == newTime1->tm_sec);
	std::cout << "Units Tests **Lib** datetime: Seconds ====> \tOK" << std::endl;
}

Test(datetime, test_minutes)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetMinutes() == newTime1->tm_min);
	std::cout << "Units Tests **Lib** datetime: Minutes ====> \tOK" << std::endl;
}

Test(datetime, test_hours)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetHours() == newTime1->tm_hour);
	std::cout << "Units Tests **Lib** datetime: Hours ====> \tOK" << std::endl;
}

Test(datetime, test_refresh)
{
    Datetime datime;
	time_t timer1;
	std::time(&timer1);
	struct tm *newTime1;
	newTime1 = std::localtime(&timer1);

	cr_assert(datime.GetHours() == newTime1->tm_hour);
	datime.refreshInfos();
	newTime1 = localtime(&timer1);
	cr_assert(datime.GetHours() == newTime1->tm_hour);
	std::cout << "Units Tests **Lib** datetime: Refresh ====> \tOK" << std::endl;
}