NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx  -framework OpenGL -framework AppKit

SRC = draw.c fractol.c init.c julia.c keys.c mandelbrot.c utils.c utils2.c tricorn.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
