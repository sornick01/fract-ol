NAME = fract-ol

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEP_FLAGS	= -MP -MMD


SRC = main.c start.c mouse.c mandelbrot.c keyboard1.c keyboard2.c \
			hooks.c errors.c draw.c colors.c ft_strcmp.c ft_putendl_fd.c \
			ft_strlen.c burningship.c julia.c\


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -pthread -o $(NAME)

%.o : %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -pthread -c $< -o $@

clean :
	rm -rf $(OBJ) 

fclean:				clean
			rm -rf $(NAME)

re:					fclean all

.PHONY:		all clean fclean re