NAME		= libftprintf.a

SRCS_PATH	= srcs/
OBJS_PATH	= objs/
HEAD_PATH	= includes/

HEAD_FILES	= ft_printf.h

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
HEAD		= $(addprefix $(HEAD_PATH), $(HEAD_FILES))

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD_PATH)

$(OBJS_PATH):
	mkdir $(OBJS_PATH)

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all bonus clean fclean re
