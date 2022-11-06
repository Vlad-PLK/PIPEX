# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:27:56 by vpolojie          #+#    #+#              #
#    Updated: 2022/11/06 16:29:37 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SRCS = pipex.c pipex_end.c\
		printf/libft/ft_putchar_fd.c printf/libft/ft_strdup.c printf/ft_base16.c printf/ft_base16M.c printf/ft_base16UL.c\
		printf/ft_printf.c printf/ft_putnbru.c printf/ft_string.c printf/ft_char.c printf/ft_check_type.c printf/ft_putnbr_fd2.c \
		printf/ft_addr.c printf/libft/ft_isdigit.c printf/ft_nbrdec.c printf/ft_nbrnsigne.c \
		printf/libft/ft_putstr_fd.c printf/ft_nbrtohexa.c printf/ft_nbrtohexamaj.c \
		printf/libft/ft_atoi.c printf/libft/ft_substr.c printf/libft/ft_strnstr.c printf/libft/ft_split.c printf/libft/ft_strlen.c printf/libft/ft_strjoin.c \

SRCS_BONUS = pipex_bonus.c pipex_part2_bonus.c\
				printf/libft/ft_putchar_fd.c printf/libft/ft_strdup.c printf/ft_base16.c printf/ft_base16M.c printf/ft_base16UL.c\
				printf/ft_printf.c printf/ft_putnbru.c printf/ft_string.c printf/ft_char.c printf/ft_check_type.c printf/ft_putnbr_fd2.c \
				printf/ft_addr.c printf/libft/ft_isdigit.c printf/ft_nbrdec.c printf/ft_nbrnsigne.c \
				printf/libft/ft_putstr_fd.c printf/ft_nbrtohexa.c printf/ft_nbrtohexamaj.c printf/libft/ft_strncmp.c printf/libft/ft_putnbr_fd.c \
				printf/libft/ft_atoi.c printf/libft/ft_substr.c printf/libft/ft_strnstr.c printf/libft/ft_split.c printf/libft/ft_strlen.c printf/libft/ft_strjoin.c \

OBJS = ${SRCS:.c=.o};

B_OBJS = ${SRCS_BONUS:.c=.o};

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS}
						@gcc ${CFLAGS} -o ${NAME} ${OBJS}

${NAME_BONUS}:	${B_OBJS}
						@gcc ${CFLAGS} -o ${NAME_BONUS} ${B_OBJS}

bonus : ${NAME_BONUS};

all:		${NAME};

clean:
				${RM} ${B_OBJS} ${RM} ${OBJS} 

fclean:		clean
				${RM} ${NAME} ${RM} ${NAME_BONUS}

re:				fclean all bonus

.PHONY:		all bonus clean fclean re