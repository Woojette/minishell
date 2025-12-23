CC = clang

CFLAGS = -Wall -Wextra -Werror  -I$(INC_DIR) -I$(LIBFT_DIR)

INC_DIR 	= includes
LIBFT_DIR 	= $(INC_DIR)/ft_libft
SRC_DIR 	= srcs
OBJ_DIR     = objs

NAME = minishell

SRCS = $(SRC_DIR)/test_main.c \
		$(SRC_DIR)/test_fonction.c \
		$(SRC_DIR)/ft_init.c \
		$(SRC_DIR)/bi_cd.c \
		$(SRC_DIR)/bi_echo.c \
		$(SRC_DIR)/bi_env.c \
		$(SRC_DIR)/bi_exit.c \
		$(SRC_DIR)/bi_exit_ft.c \
		$(SRC_DIR)/bi_export.c \
		$(SRC_DIR)/bi_pwd.c \
		$(SRC_DIR)/bi_unset.c \
		$(SRC_DIR)/bi_free.c \


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBS = -lreadline -lncurses -ltinfo $(LIBFT_DIR)/libft.a 

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) 

re	:	fclean all

.PHONY: all clean fclean re