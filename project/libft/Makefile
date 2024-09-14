# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 01:34:53 by greus-ro          #+#    #+#              #
#    Updated: 2024/09/12 20:48:01 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# Colours
################################################################################

RST				= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

################################################################################
# Compiler stuff
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
ifdef	CSANITIZE
	SANITIZE_FLAGS	=	-g3 -fsanitize=address -fsanitize=leak
endif
DEP_FLAGS		=	-MMD -MP
CFLAGS			+=	${DEP_FLAGS}

################################################################################
#Folders
################################################################################

SRC_DIR		=	./src
INC_DIR		=	./include
BUILD_DIR	=	./build

################################################################################
# Name of exec
################################################################################

NAME		=	libft.a

################################################################################
# Files
################################################################################

SRC			=	ft_atoi				\
				ft_atol				\
				ft_bzero			\
				ft_calloc			\
				ft_dtoh				\
				ft_iputchar_fd		\
				ft_iputendl_fd		\
				ft_iputnbr_fd		\
				ft_iputstr_fd		\
				ft_isalnum			\
				ft_isalpha			\
				ft_isascii			\
				ft_isdigit			\
				ft_islower			\
				ft_isupper			\
				ft_isprint			\
				ft_itoa				\
				ft_memchr			\
				ft_memcmp			\
				ft_memcpy			\
				ft_memmove			\
				ft_memset			\
				ft_pointer			\
				ft_putchar_fd		\
				ft_putendl_fd		\
				ft_putnbr_fd		\
				ft_putstr_fd		\
				ft_split			\
				ft_strchr			\
				ft_strdup			\
				ft_striteri			\
				ft_strjoin			\
				ft_strlcat			\
				ft_strlcpy			\
				ft_strlen			\
				ft_strmapi			\
				ft_strncmp			\
				ft_strnstr			\
				ft_strrchr			\
				ft_istrchr 			\
				ft_strtrim			\
				ft_substr			\
				ft_tolower			\
				ft_toupper			\
				ft_utoa				\
				ft_lstadd_front_bonus	\
				ft_lstadd_back_bonus	\
				ft_lstclear_bonus		\
				ft_lstcontains			\
				ft_lstdelone_bonus		\
				ft_lstdel_back			\
				ft_lstdel_front			\
				ft_lstiter_bonus		\
				ft_lstlast_bonus		\
				ft_lstmap_bonus			\
				ft_lstnew_bonus			\
				ft_lstsize_bonus

HEADERS		= libft.h

SRCS		=	$(addprefix ${SRC_DIR}/, $(addsuffix .c, ${SRC}))
OBJS		=	$(addprefix ${BUILD_DIR}/, $(addsuffix .o, ${SRC}))
DEPS		=	$(addprefix ${BUILD_DIR}/, $(addsuffix .d, ${SRC}))

################################################################################
# Rules 
################################################################################

all					:	${NAME}

${NAME}				:	${OBJS} 
	@echo "\t${CYAN}Linking ${NAME}${RST}"
	@ar -rcs ${NAME} ${OBJS}
	
${BUILD_DIR}/%.o	:	${SRC_DIR}/%.c  Makefile
	@echo "\t${YELLOW}Compiling ${RST} $<"
	@mkdir -p ${BUILD_DIR}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -c $< -o $@ 
#	@${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@ 

clean				:
	@echo "${RED}${NAME} -> Cleaning build folder${RST}"
	@rm -rf ${BUILD_DIR}

fclean: clean 
	@echo "${RED}${NAME} -> Cleaning ${NAME}${RST}"
	@rm -f ${NAME}
	
re: fclean all

#bonus:${BONUS_OBJ_FILES} ${LIBFT_OBJ_FILES}
#	ar -rcs ${NAME} ${LIBFT_OBJ_FILES} ${BONUS_OBJ_FILES}
#	@touch bonus

-include ${DEPS}

################################################################################
# Phony
################################################################################

.PHONY= all clean fclean re
