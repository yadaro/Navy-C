##
## Makefile for Makefile in /home/Yadaro/CPE_2016_BSQ
##
## Made by Yadaro YUN
## Login   <Yadaro@epitech.net>
##
## Started on  Tue Dec 13 12:04:04 2016 Yadaro YUN
## Last update Sun Feb 19 18:53:12 2017 Yadaro YUN
##

CC	=	gcc -g3


RM	=	rm -f

NAME	=	navy

SRC	=	main.c			\
		./Lib/my_putstr.c	\
		./Lib/my_puterror.c	\
		./Lib/my_atoi.c		\
		./Lib/my_strcmp.c	\
		./Lib/my_put_nbr.c	\
		my_signal.c		\
		map.c			\
		./Lib/doubletab2.c	\
		boat_placement.c	\
		./Lib/my_strlen.c	\
		attack_signal.c		\
		timer.c			\
		hit.c			\
		my_signal2.c		\
		send_signal.c

LIBS	=	-L. -lgnl

CFLAGS	+=	-Iinclude -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	 $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
