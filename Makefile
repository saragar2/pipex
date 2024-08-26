NAME = pipex

SOURCES =			main.c pipex.c

# SOURCES_BONUS =		pipex_bonus.c strjoin_bonus.c strncmp_bonus.c \
# 					split_bonus.c errors_bonus.c child_bonus.c \
# 					utils_bonus.c heredoc_bonus.c gnl_pipex_bonus.c \
# 					gnl_ut_pipex_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = gcc
CHACHE = .cache

all : $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/
	@echo "Make libft"

bonus: $(CHACHE)

$(CHACHE) : $(OBJECTS_BONUS)
	touch $(CHACHE)
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)
	$(CC) $(OBJECTS_BONUS) $(CFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean re 