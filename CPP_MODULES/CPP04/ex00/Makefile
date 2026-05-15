#			Program name
NAME		= Polymorphism

#			Compiler
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#			Source files
SRCS		= $(wildcard $(SRCS_PATH)*.cpp)

#			Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#			Colors for output
RED			= \033[1;31m
GREEN		= \033[1;32m
RESET		= \033[0m

#			RULES
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I$(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re