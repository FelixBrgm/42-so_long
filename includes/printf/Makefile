CC = cc
CFLAGS = -Wall -Werror -Wextra
CFILES = $(shell find functions/*.c)
OFILES = $(CFILES:.c=.o)


NAME = printf.a

LIBFT = ../libft

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	ar rcs $(NAME) $(LIBFT)/*.o
	ar rc $(NAME) $(OFILES)


clean: 
	rm -f ./functions/*.o 
	make fclean -C $(LIBFT)
	rm -f *.o 

fclean: clean
	rm -f *.a

re: fclean all