# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 14:40:45 by aennaqad          #+#    #+#              #
#    Updated: 2024/02/07 11:55:12 by aennaqad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = client.c server.c

RM = rm -rf
OBJS = $(SRC:.c=.o)
NAME = minitalk.a
AR = ar -rcs

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus : $(OBJS_BNS)
	$(AR) $(NAME) $(OBJS_BNS)

.PHONY: all clean fclean re