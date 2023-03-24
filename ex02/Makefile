NAME		=	account

SRC			=	main.cpp Account.cpp
INC			=	Account.hpp
OBJ			=	$(SRC:.cpp=.o)

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -pedantic

VALGRIND	=	valgrind -q --leak-check=full --show-leak-kinds=all

all: $(NAME)

%.o: %.cpp %(INC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

leaks: ./$(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re leaks