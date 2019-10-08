/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "Host.hpp"

Test(Host, test_User)
{
    Host name;

	cr_assert(name.GetUser() == std::getenv("LOGNAME"));
	std::cout << "Units Tests **Lib** Host: Username ====> \tOK" << std::endl;
}

Test(Host, test_Host)
{
    Host name;

	cr_assert(name.GetHost() == std::getenv("HOSTNAME"));
	std::cout << "Units Tests **Lib** Host: HOSTNAME ====> \tOK" << std::endl;
}

Test(Host, Host_setActive)
{
    Host name;

	name.setActive(false);
	cr_assert(name.getActive() == false);
	std::cout << "Units Tests **Lib** Host: setActive ====> \tOK" << std::endl;
}

Test(Host, Host_getActive)
{
    Host name;

	cr_assert(name.getActive() == true);
	std::cout << "Units Tests **Lib** Host: getActive ====> \tOK" << std::endl;
}

Test(Host, Host_getName)
{
    Host name;

	cr_assert(name.getName() == "Host");
	std::cout << "Units Tests **Lib** Host: getName ====> \tOK" << std::endl;
}