NAME		=	phonebook

SRC			=	main.cpp Contact.cpp PhoneBook.cpp Format.cpp
INC			=	Contact.hpp PhoneBook.hpp Format.hpp
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
	rm $(NAME)

fclean: clean

re: fclean all

leaks: ./$(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re leaks