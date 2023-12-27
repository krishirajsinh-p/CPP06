# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:34:27 by kpuwar            #+#    #+#              #
#    Updated: 2023/12/27 17:05:49 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=  Identify

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

INCLUDES	= Class.hpp
SRCS		= main.cpp
OBJS		= ${SRCS:.cpp=.o}

RM			= rm -rf

$(NAME): $(SRCS) $(OBJS) $(INCLUDES)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
