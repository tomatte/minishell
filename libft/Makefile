SRC			=	./ft_bzero.c ft_isalnum.c ft_isalpha.c \
				ft_isdigit.c ft_isprint.c ft_memcpy.c \
				ft_memset.c ft_strlen.c ft_isascii.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_memchr.c ft_memcmp.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_lowest.c ft_highest.c \


BONUS_SRC	=	ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c \


MORE_SRC	=	ft_putchar.c ft_putstr.c \
				ft_putnbr.c ft_put_uint.c \
				ft_itohex.c ft_strtoupper.c \
				ft_uitoa.c ft_abs.c \
				ft_isnumber.c ft_isspace.c \
				ft_issign.c \
				ft_str_push_char.c \
				ft_pow.c \
				ft_streq.c \

GNL_SRC		=	./get_next_line/get_next_line_bonus.c \
				./get_next_line/get_next_line_utils_bonus.c \


H_SRC		=	libft.h

OBJS		=	${SRC:.c=.o} ${MORE_SRC:.c=.o} ${GNL_SRC:.c=.o}

BONUS_OBJS	=	${BONUS_SRC:.c=.o}

NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

# Colors
OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m

.c.o:
		@cc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${H_SRC}
			@echo "$(GREEN)All object files from $(NAME) were created!$(OFF)"
			@ar -rcs $@ $^
			@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"

all: ${NAME}
	@make -C ./ft_printf bonus

bonus_objs: ${OBJS} ${BONUS_OBJS} ${H_SRC}
	@ar -rcs libft.a $^

bonus: bonus_objs
	@make -C ./ft_printf bonus
	@echo "$(GREEN)All bonus functions were added to the $(NAME)!$(OFF)"

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}
		@make -C ./ft_printf clean
		@echo "$(RED)The object files from $(NAME) were sucessfully removed!$(OFF)"

fclean:	clean
		@${RM} ${NAME}
		@make -C ./ft_printf fclean
		@echo "$(RED)The $(NAME) was removed!$(OFF)"

re:		fclean all

.PHONY:	all clean fclean re bonus
