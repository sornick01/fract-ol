NAME = fract-ol

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEP_FLAGS	= -MP -MMD


SRC = main.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -rf $(OBJ) 

fclean:				clean
			rm -rf $(NAME)

re:					fclean all

.PHONY:		all clean fclean re