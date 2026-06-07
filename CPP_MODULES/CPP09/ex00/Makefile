#			Program name
NAME		= btc

#			Compiler
CXX			= c++
CXXFLAGS	= -g -Wall -Werror -Wextra

#			Directories
SRCS_PATH	= ./source/
OBJS_PATH	= ./object/
INC_PATH	= ./include/

#			Sources files
SRCS		= $(wildcard $(SRCS_PATH)*.cpp)

#			Objects files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#			Valgrind
VG			= valgrind
VGFLAGS		= --leak-check=full --show-leak-kinds=all

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
	@echo "$(RED)Objects files removed$(RESET)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

valgrind: re
	@$(VG) $(VGFLAGS) ./$(NAME) input.txt

.PHONY: all clean fclean re valgrind