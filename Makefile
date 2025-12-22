NAME = push_swap
CC = gcc
CFLAG = -Wall -Wextra -Werror -I.
RM = rm -f

# This finds every .c file in the root, aux_func, and src_sort
SRCS =  $(wildcard *.c) \
		$(wildcard aux_func/*.c) \
		$(wildcard src_sort/*.c)

# --- Object Files ---
# Replaces .c extension with .o for all discovered sources
OBJS        = $(SRCS:.c=.o)

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "🚀 $(NAME) built and ready!"

# Standard rule for compiling .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "🧹 Cleaned up object files."

fclean: clean
	$(RM) $(NAME)
	@echo "🗑️ Cleaned up executable."

re: fclean all

.PHONY: all clean fclean re