# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:54:44 by saragar2          #+#    #+#              #
#    Updated: 2023/10/21 20:35:54 by saragar2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BONUS_NAME = .bonus

SOURCES =		ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c \
				ft_atoi.c ft_isprint.c ft_striteri.c ft_strnstr.c \
				ft_bzero.c ft_itoa.c ft_strjoin.c ft_strrchr.c \
				ft_calloc.c ft_memchr.c ft_strlcat.c ft_strtrim.c \
				ft_isalnum.c ft_memcmp.c ft_strlcpy.c ft_substr.c \
				ft_isalpha.c ft_memcpy.c ft_strlen.c ft_tolower.c ft_split.c \
				ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJECTS = $(SOURCES:.c=.o)

BONUSS =		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
BONUS_OBJS = $(BONUSS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_NAME)

clean:
	$(REMOVE) $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	$(REMOVE) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(OBJECTS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re
