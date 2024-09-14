# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 02:39:39 by greus-ro          #+#    #+#              #
#    Updated: 2024/03/13 00:16:33 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_DIR	= ../../inc
SRC_DIR	= ./src


NAME	= ${INC_DIR}/ft_types.h

all: ${NAME}

${NAME}: Makefile
	cp ${SRC_DIR}/ft_utils.h ${INC_DIR}/

clean:
	rm -f ${NAME}
	
re: clean all

.PHONY: all clean re
