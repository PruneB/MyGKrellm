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
#include "Cpu.hpp"

Test(Cpu, Cpu_getInfos)
{
    Cpu kernel;

	cr_assert(kernel.getInfos()[0] == 'I');
	std::cout << "Units Tests **Lib** Cpu: getInfos ====> \tOK" << std::endl;
}

Test(Cpu, Cpu_setActive)
{
    Cpu kernel;

	kernel.setActive(false);
	cr_assert(kernel.getActive() == false);
	std::cout << "Units Tests **Lib** Cpu: setActive ====> \tOK" << std::endl;
}

Test(Cpu, Cpu_getActive)
{
    Cpu kernel;

	cr_assert(kernel.getActive() == true);
	std::cout << "Units Tests **Lib** Cpu: getActive ====> \tOK" << std::endl;
}

Test(Cpu, Cpu_getName)
{
    Cpu kernel;

	cr_assert(kernel.getName() == "Cpu");
	std::cout << "Units Tests **Lib** Cpu: getName ====> \tOK" << std::endl;
}