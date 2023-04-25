DIR_SRC		=		./src

SRC			=		fill.c  ft_convert.c  \
					ft_printf.c printf_utils.c  \
					print_hex.c  print_int.c  \
					print_pointer.c  print_uint.c \
					fill_zeros.c

SRC_PRNT	=		$(patsubst %.c,$(DIR_SRC)/%.c,$(SRC))

H_SRC	=	./src/ft_printf.h

OBJS	=	${SRC_LIB:.c=.o} ${SRC_PRNT:.c=.o}

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

# Colors
OFF			:= \033[0m
RED			:= \033[0;31m
GREEN		:= \033[0;32m

.c.o:
			@cc ${FLAGS} -c $< -o ${<:.c=.o} -I.

$(NAME):	${OBJS} ${H_SRC}
			@echo "$(GREEN)All object files from $(NAME) were created!$(OFF)"
			@mv ../libft.a ./$(NAME)
			@ar -rcs $@ $^
			@echo "$(GREEN)$(NAME) files were sucessfully linked!$(OFF)"


all: 		${NAME}
	@mv ./$(NAME) ../$(NAME)

bonus:		${NAME}
	@mv ./$(NAME) ../$(NAME)

clean:
			@${RM} ${OBJS}
			@echo "$(RED)The object files from $(NAME) were sucessfully removed!$(OFF)"

fclean:		clean
			@${RM} ../${NAME}
			@echo "$(RED)The $(NAME) was removed!$(OFF)"


re:			fclean all

.PHONY:		all clean fclean re
