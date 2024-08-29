NAME = pipex

SOURCES =			main.c pipex.c
SOURCES_BONUS =		main_bonus.c pipex_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = gcc
CACHE = .cache

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) libft/libft.a -o $(NAME)

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJECTS_BONUS) libft/libft.a
	$(CC) $(OBJECTS_BONUS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/
	@echo "Make libft"

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)
	make -C libft/ fclean

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(CACHE)

re: fclean all

.PHONY: all bonus clean fclean re

