#	Programm name
NAME		= main

# Compiler
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

#	Directories
SRCS_PATH	= ./
OBJS_PATH	= ./obj/
INC_PATH	= ./

#	Sources files
SRCS		= main.cpp
SRCS		:= $(addprefix $(SRCS_PATH), $(SRCS))

#	Objects files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#	Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

#	Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I $(INC_PATH) -c $< -o $@
	@echo "Compiling $<"

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
