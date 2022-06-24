# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/06/10 13:10:26 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRCS = ft_so_long.c ft_map.c

all: $(NAME)

CC = gcc -Wall -Werror -Wextra -L. -lft -I. -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJS = ${SRCS:.c=.o}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
