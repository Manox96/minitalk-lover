# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 14:40:45 by aennaqad          #+#    #+#              #
#    Updated: 2024/02/12 16:30:56 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_C = mondatory/client.c mondatory/tools.c
SRC_S = mondatory/server.c mondatory/tools.c

SRC_B_C = bonus/client_bonus.c bonus/tools_bonus.c
SRC_B_S = bonus/server_bonus.c bonus/tools_bonus.c

OBJS_B_C = $(SRC_B_C:.c=.o)
OBJS_B_S = $(SRC_B_S:.c=.o)

OBJS_C = $(SRC_C:.c=.o)
OBJS_S = $(SRC_S:.c=.o)

NAME_B_C = client_bonus
NAME_B_S = server_bonus

NAME_C = client
NAME_S = server

RM = rm -rf

%.o: %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(OBJS_S) -o $(NAME_S)

clean:
	$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_B_C) $(OBJS_B_S)

fclean: clean
	$(RM) $(NAME_S) $(NAME_C) $(NAME_B_C) $(NAME_B_S)

re: fclean all

bonus : $(NAME_B_C) $(NAME_B_S)

$(NAME_B_C): $(OBJS_B_C)
	$(CC) $(OBJS_B_C) -o $(NAME_B_C)

$(NAME_B_S): $(OBJS_B_S)
	$(CC) $(OBJS_B_S) -o $(NAME_B_S)

.PHONY: clean