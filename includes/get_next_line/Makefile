
NAME := libget_next_line.a

CC := cc

LIB := -L../libft -lft

CCFLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=1

RM := rm -f

AR := ar rcs

SRCS =  get_next_line.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
