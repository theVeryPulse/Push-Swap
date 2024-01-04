NAME := push_swap
CC := gcc

SRC_DIR := ./src
INC_DIR := ./inc
LIBFT_INC_DIR := ./libft/inc
BIN_DIR := ./bin

CFLAGS := -Wall -Wextra -Werror

STATIC_LIBFT := libft/lib/libft.a

FILES := main.c \
	basic_list_operations_0.c \
	basic_list_operations_1.c \
	input_check.c \
	\
	operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \
	\
	sort_0.c \
	sort_1.c \
	sort_2.c \
	sort_3.c \
	sort_4.c \
	sort_5.c \
	\
	misc.c
SRC := $(addprefix $(SRC_DIR)/, $(FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC))

CK_SRC := checker.c \
	basic_list_operations_0.c \
	basic_list_operations_1.c \
	input_check.c \
	\
	operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \
	\
	misc.c
CK_OBJ := $(CK_OBJ:.c=.o)

all : $(NAME)

$(NAME): $(STATIC_LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS) \
	-I $(INC_DIR) \
	-I $(LIBFT_INC_DIR) \
	$(STATIC_LIBFT) \

checker : $(LIBFT) $(CK_OBJ)
	$(CC) 

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ \
	-I $(INC_DIR) \
	-I $(LIBFT_INC_DIR) \

$(STATIC_LIBFT):
	$(MAKE) -C libft all

clean :
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean :
	rm -f $(OBJ) $(NAME)
	$(MAKE) -C libft fclean

re : fclean all

.PHONY: all clean fclean 