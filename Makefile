# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 08:27:56 by vpolojie          #+#    #+#              #
#    Updated: 2023/08/24 12:10:57 by vpolojie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SRCS = pipex_files/pipex.c pipex_files/pipex_end.c\

SRCS_BONUS = pipex_bonus_files/pipex_bonus.c pipex_bonus_files/pipex_end_bonus.c\

# > MESSAGES COLORS <<<<<<

MSG_BCOLOR_FAILURE		:=	\001\e[1;31m\002
MSG_BCOLOR_PRIMARY		:=	\001\e[1;36m\002
MSG_BCOLOR_SUCCESS		:=	\001\e[1;32m\002
MSG_BCOLOR_WARNING		:=	\001\e[1;33m\002
MSG_NCOLOR_FAILURE		:=	\001\e[0;31m\002
MSG_NCOLOR_PRIMARY		:=	\001\e[0;36m\002
MSG_NCOLOR_SUCCESS		:=	\001\e[0;32m\002
MSG_NCOLOR_WARNING		:=	\001\e[0;33m\002

# > TERMINAL <<<<<<<<<<<<<

TERM_CONTROL_CLEAR		:=	\001\e[1;1H\e[2J\002
TERM_CONTROL_RESET		:=	\001\e[0m\002

CC = gcc

CFLAGS = -Wall -Werror -Wextra

# > COMPILING C FILES <<<<
OBJS = ${SRCS:.c=.o};

# > COMPILING C BONUS FILES <<<<
B_OBJS = ${SRCS_BONUS:.c=.o};

LIBFOLDER_PRINTF = printf
LIBFOLDER_LIBFT = libft

INCLUDE = -I./${LIBFOLDER_PRINTF}
INCLUDE_LIBFT = -I./${LIBFOLDER_LIBFT}

LIBRARY1 = -L./${LIBFOLDER_PRINTF} -lftprintf
LIBRARY2 = -L./${LIBFOLDER_LIBFT} -lft

RM = rm -rf

%.o:	%.c
	@printf "$(MSG_BCOLOR_PRIMARY) COMPILING C FILES FROM LIBRARIES: "
	@printf "$(TERM_CONTROL_RESET)"
	${CC} ${CFLAGS} -DONE=1 $(INCLUDE) $(INCLUDE_LIBFT) -c $< -o $@

${NAME}:	${OBJS}
	@printf "\n\n"
	@printf "$(MSG_BCOLOR_SUCCESS) LINKING LIBRARIES WITH MANDATORY: "
	@printf "$(TERM_CONTROL_RESET)"
	make -s -C ${LIBFOLDER_PRINTF}
	${CC} ${CFLAGS} $^ ${LIBRARY1} ${LIBRARY2} -o $@
	@printf "\n"

${NAME_BONUS}:	${B_OBJS}
	@printf "\n\n"
	@printf "$(MSG_BCOLOR_SUCCESS) LINKING LIBRARIES WITH BONUS: "
	@printf "$(TERM_CONTROL_RESET)"
	make -s -C ${LIBFOLDER_PRINTF}
	${CC} ${CFLAGS} $^ ${LIBRARY1} ${LIBRARY2} -o $@
	@printf "\n"

bonus : ${NAME_BONUS}

all:		${NAME};

clean_libft:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING LIBFT FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} libft/*.o libft/libft.a

clean_printf:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING PRINTF FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} printf/*.o printf/libftprintf.a

clean_libs:	clean_libft clean_printf

clean:
				@printf "$(MSG_BCOLOR_WARNING) CLEANING OBJECT FILES : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} ${B_OBJS} ${RM} ${OBJS}
				@printf "\n"

fclean:		clean
				@printf "$(MSG_BCOLOR_WARNING) CLEANING OBJECT EXECUTABLE : "
				@printf "$(TERM_CONTROL_RESET)"
				${RM} ${NAME} ${RM} ${NAME_BONUS}
				@printf "\n"

re:				fclean all

.PHONY:		all bonus clean fclean re
