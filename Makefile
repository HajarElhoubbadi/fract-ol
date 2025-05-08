NAME = fractol

SRCS = draw.c fractol.c init.c  keys.c  utils.c  fractals.c

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