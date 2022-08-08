# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 20:55:27 by hhenriqu          #+#    #+#              #
#    Updated: 2022/07/28 14:54:23 by hhenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	gcc

AR				=	ar -r

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

MK_LIBFT		=	cd libft && make

LIBFT			=	mv ./libft/libft.a $(NAME)

FCL_LIBFT		=	cd libft && make fclean

SRCS			=	ft_printf.c \
					ft_printf_utils.c

OBJS			=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MK_LIBFT)
	$(LIBFT)
	$(FCL_LIBFT)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re