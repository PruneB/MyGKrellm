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
#include "Ram.hpp"

Test(Ram, Ram_getInfos)
{
    Ram kernel;

	cr_assert(kernel.getInfos()[0] == 'M');
	std::cout << "Units Tests **Lib** Ram: getInfos ====> \tOK" << std::endl;
}

Test(Ram, Ram_setActive)
{
    Ram kernel;

	kernel.setActive(false);
	cr_assert(kernel.getActive() == false);
	std::cout << "Units Tests **Lib** Ram: setActive ====> \tOK" << std::endl;
}

Test(Ram, Ram_getActive)
{
    Ram kernel;

	cr_assert(kernel.getActive() == true);
	std::cout << "Units Tests **Lib** Ram: getActive ====> \tOK" << std::endl;
}

Test(Ram, Ram_getName)
{
    Ram kernel;

	cr_assert(kernel.getName() == "Ram");
	std::cout << "Units Tests **Lib** Ram: getName ====> \tOK" << std::endl;
}