#	Programm name
NAME		= Sed_is_for_losers

#	Compiler
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

#	Directories
SRCS_PATH	= ./source/
OBJS_PATH	= .
INC_PATH	= .

#	Sources files
SRCS		= main.cpp
SRCS		:= $(addprefix $(SRCS_PATH), $(SRCS))

#	Object files
OBJS		= $(SRCS:$(SRCS_PATH)%.cpp=$(OBJS_PATH)%.o)

#	Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $<"

clean:
	@rm -rf $(OBJS)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all

.PHONY: all clean fclean re