S_DIR := srcs
H_DIR := includes
SOURCE := $(S_DIR)/ft_putchar.c $(S_DIR)/ft_putstr.c $(S_DIR)/ft_strcmp.c $(S_DIR)/ft_strlen.c $(S_DIR)/ft_swap.c
OBJS := $(SOURCE:.c=.o)
NAME := libft.a

CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(S_DIR)/%.o: $(S_DIR)/%.c $(H_DIR)/ft.h
	cc $(CFLAGS) -I$(H_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re