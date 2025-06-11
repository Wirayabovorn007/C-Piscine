S_DIR := srcs
H_DIR := includes
SOURCE := $(S_DIR)/ft_putchar.c $(S_DIR)/ft_putstr.c $(S_DIR)/ft_strcmp.c $(S_DIR)/ft_strlen.c $(S_DIR)/ft_swap.c
OBJS := $(SOURCE:.c=.o)
NAME := libft.a

CFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs libft.a $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c -I $(H_DIR) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all