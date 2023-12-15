# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 06:14:49 by ibertran          #+#    #+#              #
#    Updated: 2023/12/15 15:05:55 by ibertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BUFF = 545
FILE = files/bible

fsanitize	=	#-fsanitize=address

# **************************************************************************** #

NAME = gnl.out

# *** SOURCES **************************************************************** #

SRC			=	get_next_line.c get_next_line_utils.c
SRCS		=	$(addprefix ../, $(SRC)) main.c

SRC_BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_BONUS	=	$(addprefix ../, $(SRC_BONUS)) main_bonus.c

# *** CONFIG ***************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 -D BUFFER_SIZE=$(BUFF) $(fsanitize)
CPPFLAGS	= 	$(addprefix -I, $(INCS))
LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

INCS		=	../

VALGRIND	= 	valgrind --leak-check=full

RM			=	rm -f

# *** TARGETS **************************************************************** #

all :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"
	$(VALGRIND) ./$(NAME) $(FILE)

bonus :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS_BONUS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"
	$(VALGRIND) ./$(NAME)

novalgrind :
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRCS) -o $(NAME) $(LDFLAGS) $(LDLIBS) 
	@echo "$(BLUE) $(NAME) has been created! $(RESET)"
	./$(NAME) $(FILE)

clean :
	$(RM) $(NAME)

re	: clean
	$(MAKE)

rebonus : clean
	$(MAKE) bonus

# *** SPECIAL TARGETS ******************************************************** #

.PHONY : all bonus novalgrind clean re rebonus

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m