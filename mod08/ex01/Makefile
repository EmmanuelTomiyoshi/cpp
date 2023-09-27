NAME 		=	Span

SRC 		=	main.cpp

CXX 		=	c++
CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++98 -g
CPPFLAGS 	=	-MMD -MP
BUILD_DIR 	=	build

OBJ 		=	$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEP 		=	$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.d))

VALGRIND 	=	valgrind -q --leak-check=full --show-leak-kinds=all

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(BUILD_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d

fclean: clean
	$(RM) *.out $(NAME)
	$(RM) -rf $(BUILD_DIR)

re: fclean all

run: $(NAME)
	@clear; ./$(NAME)

leaks: $(NAME)
	$(VALGRIND) ./$(NAME) a

debug: CXXFLAGS = -std=c++98 -g
debug: all

redebug: fclean debug

-include $(DEP)

.PHONY: all clean fclean leaks debug redebug