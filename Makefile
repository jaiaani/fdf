CC      =  cc
LIBS 	= -Lmlx_linux -lmlx_Linux -Llibs/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -Llibs/get_next_line -lget_next_line -Llibs/libft -llibft
CFLAGS  = -Wall -Wextra -Werror

SRCS    = $(wildcard fdf_matrix/*.c) $(wildcard draw/*c) $(wildcard menu/*.c) $(wildcard events_handler/*.c) $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)
NAME    = fdf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



