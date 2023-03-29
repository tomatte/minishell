SRC			=	temp_functions.c \
				main.c \
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
				read_all.c \
				get_args.c \
				token.c \
				pipe_exec.c \
				next_operator.c \
				is_operator.c \
				get_pipedes.c \
				get_commands.c \
				exec_commands.c \
				close_pipes.c \
				get_paths.c \
				memory_tracker.c \
				evars.c \
				expander.c \

VPATH		=	./src \
				./src/prompt \
				./src/statics \
				./src/lexer \
				./src/parser \
				./src/utils \
				./src/error \
				./src/executor \
				./src/executor/pipe_exec \
				./src/expander \

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