LIBFT = libft/

SRCS = ft_check_type.c ft_base16.c ft_base16UL.c ft_base16M.c ft_char.c ft_string.c ft_addr.c ft_nbrdec.c ft_nbrnsigne.c ft_nbrtohexa.c ft_nbrtohexamaj.c ft_putnbru.c ft_putnbr_fd2.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				make -C ${LIBFT}
				cp libft/libft.a ${NAME}
				ar src ${NAME} ${OBJS}

all:		${NAME}

clean:	
				make clean -C ${LIBFT}
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}
				make fclean -C ${LIBFT}

re:				fclean all

.PHONY:		all clean fclean re
