#			Program name
NAME		= bureaucrat

#			Compiler
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -g -std=c++98

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

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

valgrind: fclean all
	@$(VG) $(VGFLAGS) ./$(NAME)

.PHONY: all clean fclean re valgrind
