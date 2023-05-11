# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/10/26 13:20:55 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m
RED=\033[4;91m
YELLOW=\033[4;93m
BG=\033[0;94m

NAME = pipex

NB	= 0

SRCS = main.c ft_utils.c ft_utils2.c

SRCS_B = main_bonus.c ft_utils_bonus.c ft_utils_2_bonus.c here_doc_utils.c

GCC = gcc -Wall -Werror -Wextra -g

LIBFT_FLAGS = -Llibft -lft -Ilibft

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${SRCS_B:.c=.o}

ifdef	BONUS
			SRCS	=
			SRCS	+= $(SRCS_B)
endif

all :	$(NAME)

%.o	:	%.c
	@$(GCC) -Ilibft -c $< -o $@

$(NAME): ${OBJS}
	@$(MAKE) --no-print-directory -s -C libft
	@$(GCC) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@clear
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

bonus :		${NAME}
	@$(MAKE) --no-print-directory BONUS=1
	
clean:
	@$(MAKE) --no-print-directory -s -C libft clean
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	@$(MAKE) --no-print-directory -s -C libft fclean
	@rm -f $(NAME)
	clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${YELLOW}File Cleaned${BG} 	          	 *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus
