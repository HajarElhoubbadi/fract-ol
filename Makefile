NAME = fractol

SRCS = draw.c fractol.c init.c julia.c keys.c mandelbrot.c utils.c utils2.c tricorn.c

OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = cc

HEADER = fractol.h 

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all