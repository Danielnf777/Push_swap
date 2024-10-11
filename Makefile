NAME = push_swap.a 

SRCS = push_swap.c algorithm.c control_errors.c files.c utils.c split.c


OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

CC = gcc

all: $(NAME) compile

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c push_swap.h Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

compile: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all
