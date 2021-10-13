NAME		= libftprintf.a

SRCS_PATH	= srcs/

LIBFT_PATH	= libft/

LIBFT_LIB	= libft.a

HEADERS		= -I includes/ -I libft/

SRCS		= $(shell find $(SRCS_PATH) -name "*c")

#SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -g

LIBFT_OBJS	= $(LIBFT_PATH)*.o

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	ranlib $(NAME)

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

bonus:	$(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME) $(LIBFT_OBJS) $(LIBFT_LIB)

re: fclean all

.PHONY:	all pmake clean fclean re