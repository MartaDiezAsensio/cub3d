# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/08/22 22:40:31 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR=./include
BIN_DIR=./build
SRC_DIR=./src
LIBFT_DIR= ../libft

NAME		= libgnl.a

CC			= cc
ifdef	CSANITIZE
	SANITIZE_FLAGS	=	-g3 -fsanitize=address -fsanitize=leak
endif
CFLAGS		= -Wall -Werror -Wextra -MMD -MP
DFLAGS		= -D BUFFER_SIZE=30

SRC_FILES	= 	ft_get_next_line.c 				\
				ft_get_next_line_bonus.c 		\

OBJ_FILES	= $(SRC_FILES:%.c=${BIN_DIR}/%.o)
DEP_FILES	= $(SRC_FILES:%.c=${BIN_DIR}/%.d)

all: ${NAME}
	
${NAME}: ${OBJ_FILES}
	ar -rcs ${NAME} ${OBJ_FILES}
	
${BIN_DIR}/%.o:${SRC_DIR}/%.c Makefile
	@mkdir -p ${BIN_DIR} 
	${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${DFLAGS} -I ${INC_DIR} -I ${LIBFT_DIR}/include -o $@ -c $<
#	${CC} ${CFLAGS} ${DFLAGS} -I ${INC_DIR} -I ${LIBFT_DIR}/include -o $@ -c $<

clean:
	rm -f ${BIN_DIR}/*.o
	rm -f ${BIN_DIR}/*.d

fclean: clean 
	rm -f ./*.a

re: fclean all

-include ${DEP_FILES}

.PHONY: all clean fclean re
