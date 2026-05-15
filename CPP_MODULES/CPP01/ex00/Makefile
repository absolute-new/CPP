#	Programm name
NAME		= brainzz

#	Compiler
CXX			= c++
CXXFLAGS	= -Werror -Wall -Wextra -std=c++98

#	Directories
SRCS_PATH	= ./src/
OBJS_PATH	= ./obj/
INC_PATH	= ./inc/

#	Source files
SRCS		= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
SRCS		:= $(addprefix $(SRCS_PATH), $(SRCS))

#	Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#	Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

#	RULES
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@mkdir -p $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) -I $(INC_PATH) -c $< -o $@
	@echo "  Compiling $<"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED) Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) $(NAME) removed$(RESET)"

re: fclean all

leaks: re
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re leaks
