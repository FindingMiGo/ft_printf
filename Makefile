LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =	ft_printf.c ft_printf_utils.c ft_printf_spcf.c ft_printf_spcf2.c ft_printf_calc.c	\
		ft_printf_fix.c ft_printf_put.c ft_printf_put_field.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

bonus : $(NAME)

re : fclean all

.PHONY: all clean flcean bonus re
