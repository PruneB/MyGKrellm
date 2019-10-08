##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Lib htop
##

CXXFLAGS	=	-Iinclude

AR	=	ar rc

RM	=	rm

SRC_BASE	=	src/

SRC_FILES	=	Datetime.cpp	\
				Host.cpp		\
				Kernel.cpp		\
				Cpu.cpp			\
				Ram.cpp

SRC		=	$(addprefix $(SRC_BASE),$(SRC_FILES))

OBJ	=	$(SRC:.cpp=.o)

NAME	=	libinfos.a

.SILENT:

$(NAME):	$(OBJ)
	$(AR) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:	$(OBJ)
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

tests_run:
	make -C tests/

.PHONY: clean tests_run re clean
