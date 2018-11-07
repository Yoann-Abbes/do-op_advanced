##
## EPITECH PROJECT, 2018
## Makefile day10
## File description:
## 
##

NAME = my_advanced_do-op	

SRC =	src/my_advanced_do_op.c \
	src/operations.c
OBJ =	$(SRC:.c=.o)

INC =	-I./include/ \

CFLAGS= $(INC)	\
	-W	\
	-Wall	\
	-Wextra	\

LDFLAGS= -lmy   \
         -L./lib/my/ \

CC =	gcc

RULE =	all

all:    $(NAME)


$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
