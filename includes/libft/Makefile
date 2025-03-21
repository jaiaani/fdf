# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 20:18:44 by jados-sa          #+#    #+#              #
#    Updated: 2024/10/30 11:58:20 by jados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := liblibft.a

CC := cc

CCFLAGS := -Wall -Wextra -Werror

RM := rm -f

AR := ar rcs

SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRCS += ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c	ft_memmove.c
SRCS += ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c
SRCS += ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c
SRCS += ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c
SRCS += ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c
SRCS += ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
