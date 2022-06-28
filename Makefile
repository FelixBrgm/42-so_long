CC = cc
CFLAGS = -Wall -Werror -Wextra

CFILES = $(shell find src/*.c)
OFILES = $(CFILES:.c=.o)


NAME = so_long.a

LIBFT = ./includes/libft
GET_NEXT_LINE = ./includes/get_next_line
PRINTF = ./includes/printf

all: $(NAME)

$(NAME): $(OFILES) so_long.o
	make -C $(LIBFT)
	ar rcs $(NAME) $(LIBFT)/*.o
	make -C $(GET_NEXT_LINE)
	ar rcs $(NAME) $(GET_NEXT_LINE)/*.o
	make -C $(PRINTF)
	ar rcs $(NAME) $(PRINTF)/functions/*.o
	ar rcs $(NAME) $(OFILES)  
	gcc so_long.c $(NAME) -o so_long -Wall -Wextra -Werror -L ./includes/minilibx -lmlx -framework OpenGL -framework AppKit

main: $(NAME)
	make re
	gcc so_long.c $(NAME) -o so_long -Wall -Wextra -Werror -L ./includes/minilibx -lmlx -framework OpenGL -framework AppKit

clean: 
	make clean -C $(LIBFT)
	make clean -C $(GET_NEXT_LINE)
	make clean -C $(PRINTF)
	rm -f src/*.o
	rm -f *.o
	rm -f so_long

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(GET_NEXT_LINE)
	make fclean -C $(PRINTF)
	rm -f *.a

re: fclean all

