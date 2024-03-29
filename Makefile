NAME			=	libftprintf.a

SRCS			=	ft_printf.c			\
					ft_printf_utils.c	\

MKDIR			=	mkdir -p

OBJ_DIR			=	obj/

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CFLAGS			=	-Wall -Wextra -Werror

$(OBJ_DIR)%.o	:	%.c ft_printf.h
	@$(MKDIR) $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
	@ar rcs $(NAME) $(OBJS)

all				:	$(NAME)

clean			:
	rm -rf $(OBJ_DIR)

fclean			:	clean
	rm -rf $(NAME)

re				:	fclean all

.PHONY: all clean fclean re