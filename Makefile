NAME = pipex

NAME_BONUS = pipex_bonus

HEAD = pipex.h pipex_bonus.h ${LIBFT_PATH}libft.h

LIBFT_PATH = ./libft/

LIBFT = ${LIBFT_PATH}libft.a

FUNC = pipex.c pipex_utils.c

BONUS_FUNC = pipex_bonus.c \
			 pipex_utils_bonus.c \
			 get_next_line.c


BONUS_OBJS = ${BONUS_FUNC:.c=.o}

OBJS	= ${FUNC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.PHONY: all clean fclean re bonus

all: ${NAME}

${LIBFT} :
			@ ${MAKE} -sC ${LIBFT_PATH}

${NAME}	:	${LIBFT} ${OBJS} ${HEAD}
			${CC} ${CFLAGS} ${LIBFT} ${OBJS} -o ${NAME}

bonus:		${LIBFT} ${BONUS_OBJS} ${HEAD}
			${CC} ${CFLAGS} ${LIBFT} ${BONUS_OBJS} -o ${NAME_BONUS}

clean :
			${RM} ${OBJS}
			${RM} ${BONUS_OBJS}
			@ ${MAKE} -C ${LIBFT_PATH} clean

fclean :	clean
			${RM} ${NAME} ${NAME_BONUS}
			@ ${MAKE} -C ${LIBFT_PATH} fclean

re	:	fclean all clean bonus
