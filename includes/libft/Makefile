CC = cc
CFLAGS = -Wall -Werror -Wextra
CFILES = $(shell find *.c)
OFILES = $(CFILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)

clean: 
	rm -f *.o

fclean: clean
	rm -f *.a

re: fclean all