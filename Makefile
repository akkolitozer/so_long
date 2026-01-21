# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:34:37 by hulescur          #+#    #+#              #
#    Updated: 2026/01/20 17:27:17 by hulescur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c src/map_parser.c src/map_parser2.c src/map_open.c \
		src/minilx_init.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \
		libft/ft_putstr.c libft/ft_strtrim.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
X11_LIB = -lXext -lX11 -lm -lz
MLXLIB = -Lmlx -lmlx

NAME = so_long
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(MLXLIB) $(X11_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
