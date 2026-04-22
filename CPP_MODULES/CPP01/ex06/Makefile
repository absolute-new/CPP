#	Programm name
NAME		= harlFilter

#	Compiler
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

#	Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#	Source files
SRCS		= main.cpp Harl.cpp
SRCS		:= $(addprefix $(SRCS_PATH), $(SRCS))

#	Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#	Colors for output
RED			= \033[0;31m
GREEN		= \033[0;32m
RESET		= \033[0m;

#	Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)Objects files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

leaks: re
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re leaks