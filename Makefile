NAME		= libftprintf.a

SRCS_PATH	= srcs/
OBJS_PATH	= objs/
LIBFT_PATH	= libft/

LIBFT_LIB	= libft.a

HEADERS		= -I includes/ -I libft/

SRCS_FILES	= ft_printf.c				\
			  ft_eval_format.c			\
			  ft_tab_utils.c			\
			  ft_tab_update.c			\
			  ft_eval_conv_utils.c		\
			  ft_eval_char.c			\
			  ft_eval_str.c				\
			  ft_print_nbr_utils.c		\
			  ft_eval_int.c				\
			  ft_eval_unsigned_int.c	\
			  ft_eval_hex.c				\
			  ft_eval_pointer.c			\
			  ft_eval_percent.c			\
			  ft_eval_flags_1.c			\
			  ft_eval_flags_2.c			\
			  ft_atoi.c					\
			  ft_isdigit.c				\
			  ft_min.c					\
			  ft_numlen.c				\
			  ft_putchar_fd.c			\
			  ft_strlen.c

OBJS_FILES	= $(SRCS_FILES:.c=.o)

SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS		= $(addprefix $(OBJS_PATH), $(OBJS_FILES))

LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LIBFT_OBJS	= $(LIBFT_PATH)*.o

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJS_PATH):
	mkdir $(OBJS_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS_PATH)

fclean: clean
		rm -rf $(NAME) $(LIBFT_OBJS) $(LIBFT_LIB)

re: fclean all

.PHONY:	all clean fclean re
