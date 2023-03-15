SRC			=	main.c \
				prompt.c \
				get_directory.c \
				get_username.c \
				get_hostname.c \
				get_prompt_msg.c \
				operators.c \
				state.c \
				lexer.c \
				new_token.c \
				identify_operator.c \
				identify_quotes.c \
				identify_word.c \
				parser.c \
				categorize_word.c \
				cleaner.c \
				syntax.c \
				nut_error.c \
				executor.c \
				in_error.c \
				get_files.c \
				clear_files.c \
				create_task.c \
				command_task.c \

VPATH		=	./src \
				./src/prompt \
				./src/statics \
				./src/lexer \
				./src/parser \
				./src/utils \
				./src/error \
				./src/executor \
				./src/executor/task \

OBJS_DIR	=	./objects

OBJS		:=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Wall -Wextra -I./ -lreadline

NAME		=	minishell

LIBFT_DIR		=	./libft

LIBFT		=	$(LIBFT_DIR)/libftprintf.a

CC			=	cc

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re