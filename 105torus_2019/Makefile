##
## EPITECH PROJECT, 2020
## 105torus
## File description:
## makefile
##

NAME	=	105torus

SRC	=	src/main.c		\
		src/compute_eq.c	\
		src/bisection.c		\
		src/newton.c		\
		src/secant.c		\
		src/help_display.c	\
		src/error_handling.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

LDFLAGS	=	-lm

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
