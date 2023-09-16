##
## EPITECH PROJECT, 2023
## nanotekspice
## File description:
## Makefile
##

NAME	=	nanotekspice

SRC	=	$(wildcard src/Gates/*.cpp)	\
		$(wildcard src/Parser/*.cpp)	\
		$(wildcard src/Components/*.cpp)	\
		$(wildcard src/Advanced/*.cpp)	\
		$(wildcard src/*.cpp)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I./inc -std=c++20

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
