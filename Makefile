NAME	=	minishell
CFLAGS	=	-Wall -Wextra #-Werror
FSAN	=	-g3 -fsanitize=address
OBJS	=	minishell.o \
			ft_exec_cmd.o \
			ft_read_ops.o \
			ft_exit.o \
			utils_basic.o \
			ft_get_env.o \
			ft_print_sort.o	\
			utils_get_env.o	\
			ft_init_term.o \
			ft_buf_to_list.o \
			ft_arrow.o

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	gcc $(CFLAGS)  $^ -o $@
	#gcc $(CFLAGS) -lncurses $^ -o $@
fsan	:	$(OBJS)
	gcc $(CFLAGS) $(FSAN) $^ -o $(NAME)

%.o		:	%.c
	gcc -c $(CFLAGS) $^ 

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

PHONY	:	all clean fclean re
