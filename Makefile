# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:35:13 by tpereira          #+#    #+#              #
#    Updated: 2022/05/20 19:53:44 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g
SRCS 		= $(wildcard ./srcs/*.c)
LIB_SRCS	= mv $(LIB_NAME)/libft.a ./$(NAME)
OBJS 		= $(SRCS:.c=.o)
LIB_OBJS	= $(LIB_SRCS:.c=.o)
LIB_NAME	= libft
LIB_HEADER	= -I libft/includes
INC_PATH 	= includes $(LIB_HEADER)

.c.o:
	@$(CC) $(CFLAGS) -c $^ -o $(<:.c=.o) -I $(INC_PATH)

all:        $(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIB_NAME)
	@mv $(LIB_NAME)/libft.a ./$(NAME)
	@ar -rcs $(NAME) $(OBJS)
clean:
	@make clean -C $(LIB_NAME)/
	@rm -f $(OBJS)
fclean:     clean
	@make fclean -C $(LIB_NAME)/
	@rm -f $(NAME)
re:         fclean all
bonus:		$(NAME)

cc:
	@$(CC) $(CFLAGS) -g main.c libftprintf.a && ./a.out

.PHONY: bonus re fclean clean all
