# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/08/22 10:50:09 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m
RED=\033[4;91m
YELLOW=\033[4;93m
BG=\033[0;94m

NAME = push_swap

SRCS = main.c instruc.c ft_use_chain.c ft_utils.c ft_algo_for_3.c ft_algo_for_5.c ft_check.c ft_algo_for_100.c ft_algo_for_100_utils.c

BONUS = 

GCC = gcc -Wall -Werror -Wextra -g 
LIBFT_FLAGS = -Llibft -lft -Ilibft

OBJS = ${SRCS:.c=.o}

all :	$(NAME)

%.o	:	%.c
	@$(GCC) -Ilibft -c $< -o $@

$(NAME): ${OBJS}
	@make -s -C libft
	@$(GCC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)
	clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${BLUE}Compilation_Complete${BG} 	         *"
	@echo "*              ${BLUE}File name ${RED}< ${NAME} >${BG} 	         *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"

BONUS_OBJS = $(BONUS:.c=.o)

bonus : $(BONUS_OBJS)
	@make -s -C libft
	@$(GCC) $(BONUS_OBJS) $(LIBFT_FLAGS) -o $(NAME)
	clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${BLUE}Compilation_Complete${BG} 	         	 *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"
	
clean:
	@make -s -C libft clean
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${YELLOW}File Cleaned${BG} 	          	 *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re
