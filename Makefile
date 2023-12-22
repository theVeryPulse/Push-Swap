NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC := main.c \
	basic_list_operations.c \
	operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \

OBJ := $(SRC:.c=.o)

LIBFT := libft/libft.a
INC_DIR := -L libft
LIB_DIR := -l ft


all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(INC_DIR) $(LIB_DIR) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(LIBFT): libft
	$(MAKE) -C libft


clean :
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean :
	rm -f $(OBJ) $(NAME)
	$(MAKE) -C libft fclean

merge: $(LIBFT)
	cc mains/main_merge_sort.c \
	main.c operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \
	basic_list_operations.c \
	-L libft/ -l ft -g

.PHONY: all clean fclean 