SRC			=	main.c \
				prompt.c 

VPATH		=	./src \
				./src/core \

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