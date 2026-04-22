/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   Makefile					   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/09 14:52:56 by absolute     ##               #+#        */
/*   Updated: 2026/04/09 14:52:56 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */


SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)
NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
