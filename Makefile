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
				executor.c \
				in_error.c \
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
				expander.c \
				fill_exp.c \
				fill_exp_value.c \
				expand_str.c \
				echo.c \
				command_exec.c \
				simple_errors.c \
				get_redirects.c \
				is_redirect.c \
				new_command.c \
				simple_exec.c \
				next_pipe.c \
				read_doc.c \
				cd.c \
				mini_exit.c \
				exitin.c \
				pwd.c \
				env.c \
				export.c \
				evars2.c \
				evar_utils.c \
				unset.c \
				error_code.c \
				is_option.c \
				here_signal.c \
				set_signals.c \
				no_command.c \
				transformer.c \
				transformer_utils.c \
				transformer_utils2.c \
				exec_errors.c \
				more_errors.c \
				export_utils.c \
				spipes.c \
				sfiles.c \

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
				./src/builtins \
				./src/heredoc \
				./src/signals \
				./src/transformer


OBJS_DIR	=	./objects

OBJS		:=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Wall -Wextra -I./ -lreadline

NAME		=	minishell

LIBFT_DIR		=	./libft

LIBFT		=	$(LIBFT_DIR)/libftprintf.a

INCLUDES = -I includes

HEADERS	= ./includes/defines.h ./includes/minishell.h ./includes/structs.h

CC			=	cc

# Colors
OFF				:= \033[0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
BLUE			:= \033[0;34m

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c
	@$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	@mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(LIBFT) $(HEADERS)
	@echo "$(GREEN)All object files from $(NAME) were created!$(OFF)"
	@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $@ $(INCLUDES_PATH)
	@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_PATH)
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)The $(NAME) was removed!$(OFF)"
	@make -C $(LIBFT_DIR) fclean

re:	fclean all

val:
	make && valgrind --track-origins=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=sup.supp ./$(NAME)

valgrind: val

.PHONY:	all clean fclean re
