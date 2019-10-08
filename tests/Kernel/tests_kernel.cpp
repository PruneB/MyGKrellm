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
#include "Kernel.hpp"

Test(Kernel, Kernel_getInfos)
{
    Kernel kernel;
    std::string contenu = "ERROR";
	std::string infos;
    std::ifstream fichier("/proc/version", std::ios::in);
    int index = 0;

	getline(fichier, contenu);
	while (contenu[index++] != ' ');
	contenu[index - 1] = '\n';
	while (contenu[index++] != ' ');
	while (contenu[index++] != ' ');
	contenu.substr(1, index);
	fichier.close();
	infos = "";
	infos.append("Kernel: ");
	infos.append(contenu.substr(0, index));

	cr_assert(kernel.getInfos() == infos);
	std::cout << "Units Tests **Lib** Kernel: getInfos ====> \tOK" << std::endl;
}

Test(Kernel, Kernel_getInfos_two)
{
    Kernel kernel;
    std::string contenu = "ERROR";
	std::string infos;
    std::ifstream fichier("/proc/version", std::ios::in);
    int index = 0;

	getline(fichier, contenu);
	while (contenu[index++] != ' ');
	contenu[index - 1] = '\n';
	while (contenu[index++] != ' ');
	while (contenu[index++] != ' ');
	contenu.substr(1, index);
	fichier.close();
	infos = "";
	infos.append("Kernel: ");
	infos.append(contenu.substr(0, index));

	cr_assert(kernel.getInfos() == infos);
	std::cout << "Units Tests **Lib** Kernel: getInfos two ====> \tOK" << std::endl;
}

Test(Kernel, Kernel_setActive)
{
    Kernel kernel;

	kernel.setActive(false);
	cr_assert(kernel.getActive() == false);
	std::cout << "Units Tests **Lib** Kernel: setActive ====> \tOK" << std::endl;
}

Test(Kernel, Kernel_getActive)
{
    Kernel kernel;

	cr_assert(kernel.getActive() == true);
	std::cout << "Units Tests **Lib** Kernel: getActive ====> \tOK" << std::endl;
}

Test(Kernel, Kernel_getName)
{
    Kernel kernel;

	cr_assert(kernel.getName() == "Kernel");
	std::cout << "Units Tests **Lib** Kernel: getName ====> \tOK" << std::endl;
}