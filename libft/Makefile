# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlarraze <tlarraze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:52:27 by tlarraze          #+#    #+#              #
#    Updated: 2022/06/09 11:53:49 by tlarraze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putstr.c ft_putchar.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_printf.c ft_putchar2.c ft_putstr2.c ft_putnbr2.c ft_putunbr2.c ft_puthexmaj.c ft_puthexmin.c ft_voidp.c ft_puthexminp.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

all: $(NAME)

CC = gcc -Wall -Werror -Wextra

BONUS_OBJS = $(BONUS:.c=.o)

bonus: ${BONUS_OBJS}
		ar rc ${NAME} ${BONUS_OBJS}
		ranlib ${NAME}

OBJS = ${SRCS:.c=.o}

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

