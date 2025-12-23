NAME = AnNagram
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = sources/checker.c sources/error_handling.c sources/main.c sources/utility_functions.c sources/word_comb.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
rm -f $(OBJS)

fclean: clean
rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
