NAME		=	account

SRC			=	Account.cpp tests.cpp
INC			=	Account.hpp
OBJ			=	$(SRC:.cpp=.o)

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -Wno-used -std=c++98 -g -pedantic

VALGRIND	=	valgrind -q --leak-check=full --show-leak-kinds=all

all: $(NAME)

%.o: %.cpp %(INC)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.txt

re: fclean all

leaks: ./$(NAME)
	$(VALGRIND) ./$(NAME)

compare: ./$(NAME)
	cat 19920104_091532.log | cut -d ' ' -f 2 > log.txt
	./account | cut -d ' ' -f 2 > output.txt
	diff log.txt output.txt

.PHONY: all clean fclean re leaks