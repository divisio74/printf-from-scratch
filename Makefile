##
## EPITECH PROJECT, 2024
## B-CPE-101-LYN-1-1-myprintf-pierre.baud
## File description:
## Makefile
##

SRC		=		print_double1.c \
				annexe.c \
				mini_countf.c \
				annexecount.c \
				annexecountdouble.c \
				my_printf.c \
				print_double_s1.c \
				my_u.c\
				my_flag_o.c\
				annexecountscience.c\
				annexe_double_s1.c\
				annexe_base_flags.c\



OBJ 	=		$(SRC:.c=.o)

NAME    = 		libmy.a

NAME2   =       my_printf.h

all: 	$(NAME)

$(NAME): 		$(OBJ)
		gcc -c $(SRC)
		ar rc libmy.a $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
