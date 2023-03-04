# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jmetzger <jmetzger@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 07:17:37 by jmetzger      #+#    #+#                  #
#    Updated: 2023/02/10 14:37:05 by jmetzger      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRC = so_long.c make_window.c render_map.c check_map_valid.c keyBoard_hooks.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@ar -rcs $(NAME) $(OBJ) 
	
clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
