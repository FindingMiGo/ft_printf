LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

NAME = libftprintf.a

SRCS =	ft_printf.c ft_printf_utils.c ft_printf_spcf.c ft_printf_spcf2.c ft_printf_calc.c	\
		ft_printf_fix.c ft_printf_put.c ft_printf_put_field.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean :
	if [ -d $(LIBFT_DIR) ]; then $(MAKE) clean -C $(LIBFT_DIR); fi
	rm -f $(OBJS)

fclean : clean
	if [ -d $(LIBFT_DIR) ]; then $(MAKE) fclean -C $(LIBFT_DIR); fi
	rm -f $(NAME)

bonus : $(NAME)

re : fclean all

.PHONY: all clean fclean bonus re
