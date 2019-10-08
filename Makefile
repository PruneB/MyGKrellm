## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

LDFLAGS		=	-lncurses -l c_graph_prog -LLib -linfos -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS  	=	-Iinclude -ILib/include -INcurses/include -IGraphical/include -W -Wall -Wextra -Wshadow 

CC		=	g++

RM		=	rm

SRC_BASE_GRAPHIC	=	./Graphical/src/

SRC_FILES_GRAPHIC	=	*.cpp

SRC_BASE_NCURSES	=	./Ncurses/src/

SRC_FILES_NCURSES	=	*.cpp

SRC		=	$(addprefix $(SRC_BASE_GRAPHIC),$(SRC_FILES_GRAPHIC))	\
			$(addprefix $(SRC_BASE_NCURSES),$(SRC_FILES_NCURSES))	\
			main.cpp


OBJ		=	$(SRC:.cpp=.o)

NAME		=	MyGKrellm

.SILENT:

$(NAME):	$(OBJ)
	make -C ./Lib/
	$(CC)  -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)
		@echo "Compilation faite!"

all:	$(NAME)

clean:
	$(RM) -f $(OBJ)
	make clean -C ./Lib/
		@echo "Clean faite!"

fclean: clean
	$(RM) -f $(NAME)
	make fclean -C ./Lib/
	make fclean -C ./tests/
		@echo "FClean faite!"

re:	fclean all
		@echo "Re fait!"

tests_run:
	make -C tests/

.PHONY: clean fclean re all
