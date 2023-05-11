# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make --no-print-directoryfile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:32:22 by tlarraze          #+#    #+#              #
#    Updated: 2023/02/24 15:23:00 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m
RED=\033[4;91m
YELLOW=\033[4;93m
BG=\033[0;94m


NAME = cub3d

SRCS = main.c

BONUS = main.c
GCC = gcc -Wall -Werror -Wextra -g
LIBFT_FLAGS = -Llibft -lft -Ilibft
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJS = ${SRCS:.c=.o}

all :	$(NAME)

%.o	:	%.c
	@$(GCC) -Imlx_linux -Ilibft -c $< -o $@

$(NAME): ${OBJS}
	@make --no-print-directory -sC libft
	@make --no-print-directory -sC mlx_linux
	@$(GCC) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	##@clear
	@echo "${BG}                                  /   \   "
	@echo "${BG} _                        )      ((   ))     ( "
	@echo "${BG}(@)                      /|\      ))_((     /|\ "
	@echo "${BG}|-|                     / | \    (/\|/\)   / | \                      (@) "
	@echo "${BG}| | -------------------/--|-voV---\'|'/--Vov-|--\---------------------|-| "
	@echo "${BG}|-|                         '^'   (o o)  '^'                          | | "
	@echo "${BG}| |                               '\Y/'                               |-| "
	@echo "${BG}|-|                                                                   | | "
	@echo "${BG}| |             	   ${BLUE}Compilation_Complete${BG}	  		      |-|  "
	@echo "${BG}|-|            		   ${BLUE}File name ${RED}< ${NAME} >${BG}			      | | "
	@echo "${BG}| |                                                                   |-| "
	@echo "${BG}|_|___________________________________________________________________| | "
	@echo "${BG}(@)              l   /\ /         ( (       \ /\   l                 \|-| "
	@echo "${BG}                 l /   V           \ \       V   \ l                  (@) "
	@echo "${BG}                 l/                _) )_          \I"
	@echo "${BG}                                   '\ /'"
	@echo "${BG}                                     '"

BONUS_OBJS = $(BONUS:.c=.o)

bonus : $(BONUS_OBJS)
	@make --no-print-directory -sC libft
	@make --no-print-directory -sC mlx_linux
	@$(GCC) $(BONUS_OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

clean:
	@make --no-print-directory -sC libft clean
	@make --no-print-directory -sC mlx_linux clean
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	@make --no-print-directory -C libft fclean
	@rm -f $(NAME)
	@clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${YELLOW}File Cleaned${BG} 	          	 *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re
