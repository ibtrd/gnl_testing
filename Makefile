# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 06:14:49 by ibertran          #+#    #+#              #
#    Updated: 2023/12/21 14:06:09 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE 	= 42					#Define BUFFER_SIZE
FILE 			= files/bible.txt		#Filepath of mandatory part test

BONUS_MAX_LINES = 50	#Set the max amout of gnl calls of bonus part test

# **************************************************************************** #

NAME = gnl.out

# *** SOURCES **************************************************************** #

SRC			=	get_next_line.c get_next_line_utils.c
SRCS		=	$(addprefix ../, $(SRC)) main.c

SRC_BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS	=	$(addprefix ../, $(SRC_BONUS)) main_bonus.c

# *** CONFIG ***************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
CPPFLAGS	= 	$(addprefix -I, $(INCS))
LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

INCS		=	../

VALGRIND	= 	valgrind -q --leak-check=full --show-reachable=yes

RM			=	rm -f

# *** TARGETS **************************************************************** #

all :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	$(VALGRIND) ./$(NAME) $(FILE)

bonus :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS_BONUS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	$(VALGRIND) ./$(NAME) $(BONUS_MAX_LINES)

novalgrind :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	./$(NAME) $(FILE)

clean :
	$(RM) $(NAME)

re	: clean
	$(MAKE)

rebonus : clean
	$(MAKE) bonus

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all bonus novalgrind clean re rebonus