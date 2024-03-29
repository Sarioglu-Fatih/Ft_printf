NAME			=	exec

SRCS			=	main.c	\

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

LDFLAGS			=	-L./../. -lftprintf

RM				=	rm -rf

OBJ_DIR			=	obj/

MKDIR			=	mkdir -p

GET_LIB			=	make -C ..



all				:	makelib $(NAME)

makelib			:
	$(GET_LIB)

$(OBJ_DIR)%.o	:	%.c
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			:	$(OBJS)
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean			:
	$(RM) $(OBJ_DIR)
	make clean -C ..

fclean			:	clean
	$(RM) $(NAME)
	make fclean -C ..

re				:	fclean all

.PHONY			:	all clean fclean re