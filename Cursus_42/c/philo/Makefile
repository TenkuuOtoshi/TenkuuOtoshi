# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/12/15 17:58:21 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m
RED=\033[4;91m
YELLOW=\033[4;93m
BG=\033[0;94m

NAME = philo

NB	= 0

SRCS = philo.c ft_utils.c ft_utils_2.c ft_utils_3.c ft_state.c

SRCS_B = philo_bonus/philo_bonus.c philo_bonus/ft_utils_bonus.c philo_bonus/ft_utils_2_bonus.c philo_bonus/ft_utils_3_bonus.c philo_bonus/ft_state_bonus.c philo_bonus/ft_check_succes.c

GCC = gcc -Wall -Werror -Wextra -g -pthread

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
	@$(GCC) $(SRCS) -o $(NAME)
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
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
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
