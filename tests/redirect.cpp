/*
** EPITECH PROJECT, 2017
** Test Criterion
** File description:
** Units of task 01 day 06
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <string>

void redirect_all_std(void)
{
	cr_redirect_stderr();
	cr_redirect_stdin();
	cr_redirect_stdout();
}
