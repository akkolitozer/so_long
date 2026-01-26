# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/01/25 18:31:48 by hulescur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c src/map_parser.c src/map_parser2.c src/map_open.c \
		src/minilx_init.c \
		src/get_next_line.c src/get_next_line_utils.c \
		src/ft_putstr.c src/ft_strtrim.c \
		src/minilx_rendermap.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lminilx -lmlx

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C minilx
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(X11_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
