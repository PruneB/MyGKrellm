##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

INCLUDE		=	-I ../../Lib/include

CXXFLAGS	=	--coverage $(INCLUDE) -W -Wall -Wextra -Wshadow 

LDFLAGS	=	--coverage -lcriterion -L../../Lib -linfos

CXX		=	g++

SRC	=	tests_Cpu.cpp


OBJ	=	$(SRC:.cpp=.o)

NAME	=	units_tests

.SILENT:

$(NAME):	clean $(OBJ)
	make -C ../../Lib/
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(INCLUDE)
	@echo "Units tests **Lib** CPU"
	./units_tests
	@echo "END Units tests **Lib** CPU"

all:	$(NAME)

clean:
	find ../../ -name "*.gcda" -delete
	find ../../ -name "*.gcno" -delete
	rm -f $(OBJ)
#		@echo Clean Units tests Little Pony and Teddy end!

fclean: clean
	rm -f units_tests
#		@echo Fclean Units tests Little Pony and Teddy end!

re:	fclean all
#		@echo RE Units tests Little Pony and Teddy end!

.PHONY: clean fclean re all