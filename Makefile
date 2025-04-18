CC      =  cc
LIBS 	= -Lmlx_linux -lmlx_Linux -Llibs/minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -Llibs/get_next_line -lget_next_line -Llibs/libft -llibft
CFLAGS  = -Wall -Wextra -Werror

SRCS    = $(wildcard fdf_matrix/*.c) $(wildcard draw/*c) $(wildcard menu/*.c) $(wildcard events_handler/*.c) $(wildcard *.c)
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = libs/libft
GNL_DIR = libs/get_next_line
MLX_DIR = libs/minilibx-linux

LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_A = $(GNL_DIR)/get_next_line.a
MLX_A = $(MLX_DIR)/libmlx.a

COMP = make -C

NAME    = fdf

all: $(LIBFT_A) $(GNL_A) $(MLX_A) $(NAME)

$(LIBFT_A):
	$(COMP) $(LIBFT_DIR)

$(GNL_A):
	$(COMP) $(GNL_DIR)

$(MLX_A):
	$(COMP) $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(COMP) $(LIBFT_DIR) clean
	$(COMP) $(GNL_DIR) clean
	$(COMP) $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(COMP) $(LIBFT_DIR) fclean
	$(COMP) $(GNL_DIR) fclean
	$(COMP) $(MLX_DIR) fclean


re: fclean all

.PHONY: all clean fclean re

