# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/07/04 15:18:27 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ft_so_long.c ft_map.c ft_utils.c ft_utils2.c ft_errors.c ft_img.c

BONUS = ft_so_long_bonus.c ft_map_bonus.c ft_utils_bonus.c ft_utils2_bonus.c ft_errors_bonus.c ft_img_bonus.c

GCC = gcc -Wall -Werror -Wextra -g -L/usr/local/lib -I/usr/local/include
LIBFT_FLAGS = -Llibft -lft -Ilibft
MLX_FLAGS = -Lmlx_linux -lmlx -Imlx_linux -L/usr/local/lib -lXext -lX11 -lm -lz

OBJS = ${SRCS:.c=.o}

all :	$(NAME)

%.o	:	%.c
	$(GCC) -Imlx_linux -Ilibft -c $< -o $@

$(NAME): ${OBJS}
	make -C libft
	$(GCC) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

BONUS_OBJS = $(BONUS:.c=.o)

bonus : $(BONUS_OBJS)
	make -C libft
	$(GCC) $(BONUS_OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	
clean:
	make -C libft clean
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
