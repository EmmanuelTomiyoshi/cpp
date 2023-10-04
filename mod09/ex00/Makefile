NAME 		=	btc

SRC 		=	main.cpp parse.cpp

CXX 		=	c++
CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++98 -g
CPPFLAGS 	=	-MMD -MP
BUILD_DIR 	=	build

OBJ 		=	$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))
DEP 		=	$(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.d))

TESTER		=	tests.out
SRC_TEST	=	$(wildcard $(SRC:.cpp=_test.cpp))
OBJ_TEST	=	$(addprefix $(BUILD_DIR)/, $(SRC_TEST:.cpp=.o))

VALGRIND 	=	valgrind -q --leak-check=full --show-leak-kinds=all

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(BUILD_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR):
	mkdir -p $@

$(TESTER): $(NAME) $(OBJ_TEST)
	$(CXX) $(filter-out %main.o, $(OBJ)) $(OBJ_TEST) -o $@ $(CXXFLAGS)

tests:	$(TESTER)
	$(VALGRIND) ./$(TESTER)

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

.PHONY: all clean fclean rerun leaks debug redebug