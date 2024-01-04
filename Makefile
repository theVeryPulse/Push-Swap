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
	operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \
	sort_0.c \
	sort_1.c \
	sort_2.c \
	sort_3.c \
	sort_4.c \
	sort_5.c \
	misc.c
SRC := $(addprefix $(SRC_DIR)/, $(FILES))
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC))

CK_FILES := checker.c \
	basic_list_operations_0.c \
	basic_list_operations_1.c \
	input_check.c \
	operation_push.c \
	operation_reverse_rotate.c \
	operation_rotate.c \
	operation_swap.c \
	sort_0.c \
	sort_1.c \
	sort_2.c \
	sort_3.c \
	sort_4.c \
	sort_5.c \
	misc.c
CK_SRC := $(addprefix $(SRC_DIR)/, $(CK_FILES))
CK_OBJ := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(CK_SRC))

all : $(NAME)

# Build push_swap executable
$(NAME): $(STATIC_LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) \
	$(STATIC_LIBFT)

# Build checker for bonus
bonus : checker 

checker : $(STATIC_LIBFT) $(CK_OBJ)
	$(CC) $(CK_OBJ) -o $@ $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) \
	$(STATIC_LIBFT)

# Compile source files from ./src into ./bin
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ \
	-I $(INC_DIR) \
	-I $(LIBFT_INC_DIR)

# Build libft.a using its Makefile
$(STATIC_LIBFT):
	$(MAKE) -C libft all

clean :
	rm -f ./bin/*.o
	$(MAKE) -C libft clean

fclean : clean
	rm -f $(NAME) checker
	$(MAKE) -C libft fclean

re : fclean all

.PHONY: all clean fclean 