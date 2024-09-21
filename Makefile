NAME = pipex

SOURCES =			main.c pipex.c
SOURCES_BONUS =		main_bonus.c pipex_bonus.c get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3
REMOVE = rm -f
CC = gcc
CACHE = .cache

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) libft/libft.a -o $(NAME)

bonus: .bonus

.bonus: $(OBJECTS_BONUS) libft/libft.a
	@touch .bonus
	$(CC) $(OBJECTS_BONUS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/
	@echo "Make libft"

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)
	$(REMOVE) .bonus
	$(REMOVE) .here_doc
	make -C libft/ fclean

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(CACHE)

re: fclean all

.PHONY: all bonus clean fclean re

