# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sglass <sglass@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:27:33 by sglass            #+#    #+#              #
#    Updated: 2021/01/25 13:08:26 by sglass           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_strcmp.c initscheckexitsscreen.c screen.c ft_memset.c initimgskeys.c arraysprite.c controller.c controller2.c sprite.c floors.c textureswalls.c  textureswalls2.c calcheight.c initplayer.c gamecalc.c validmap.c parser2.c getfloor.c getresolutionandceil.c gettextures.c startparser.c checkerrors.c ft_calloc.c ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_putendl_fd.c get_next_line_utils.c get_next_line.c ft_lstlast.c ft_strlen.c ft_memmove.c ft_atoi.c ft_strdup.c ft_substr.c ft_putnbr_fd.c
OBJS	= ${SRCS:.c=.o}

CFLAGS 	= -Wall -Wextra -Werror -I.

NAME	= cub3D

GCC		= gcc

RM		= rm -f

FT_H  	= cub.h


all:	${NAME}

norm:
	norminette ${SRCS}

.c.o:
			${GCC} ${CFLAGS} -c  $< -o ${<:.c=.o}



$(NAME):	${OBJS}

			${GCC} ${CFLAGS} -o ${NAME} ${OBJS} -L. libmlx.a -framework OpenGL -framework AppKit

clean:
			${RM} ${OBJS}



fclean:		clean
			${RM} ${NAME}


re:			fclean all

bonus:		all
