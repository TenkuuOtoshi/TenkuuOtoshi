# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2023/05/05 17:30:08 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE=\033[4;96m
RED=\033[4;91m
BIGRED=\033[31m
YELLOW=\033[4;93m
BG=\033[0;94m
GREEN=\033[32m
ORANGE=\033[34m

NAME = Animal

SRCS = main.cpp Animal.cpp Dog.cpp

INCLUDE = m04.h Animal.hpp Dog.hpp

GCC = c++ -std=c++98 -g -Wall -Werror -Wextra

OBJS = ${SRCS:.cpp=.o}

all :	$(NAME)

%.o:%.cpp $(INCLUDE)
	$(GCC) -c $< -o $@

$(NAME): ${OBJS}
	@$(GCC) $(SRCS) -o $(NAME)
	@clear
	@echo "${GREEN}	_______        ${BIGRED}  _ 	      ${ORANGE}  _    "
	@echo "${GREEN}	(  ____ \     ${BIGRED}  ( )   	     ${ORANGE}  ( )   "
	@echo "${GREEN}	| (    \/     ${BIGRED}  | |   	     ${ORANGE}  | |   "
	@echo "${GREEN}	| |         ${BIGRED}____| |____    ${ORANGE}____| |____ "
	@echo "${GREEN}	| |        ${BIGRED}(____   ____)  ${ORANGE}(____   ____)"
	@echo "${GREEN}	| |           ${BIGRED}  | |   	     ${ORANGE}  | |   "
	@echo "${GREEN}	| (____/\     ${BIGRED}  | |   	     ${ORANGE}  | |   "
	@echo "${GREEN}	(_______/     ${BIGRED}  (_)   	     ${ORANGE}  (_)   "
	@echo "${GREEN}		  ${BLUE}Compilation_Complete${BG}"
	@echo "${GREEN}		 ${BLUE}File name ${RED}< ${NAME} >${BG}"

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f $(NAME)
	@clear
	@echo "${BG}**************************************************"
	@echo "${BG}*                                                *"
	@echo "*              ${YELLOW}File Cleaned${BG} 	          	 *"
	@echo "${BG}*                                                *"
	@echo "${BG}**************************************************"

re: fclean all


.PHONY: all clean fclean re

