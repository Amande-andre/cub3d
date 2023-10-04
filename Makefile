# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmande <anmande@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:46:06 by anmande           #+#    #+#              #
#    Updated: 2023/09/30 18:39:59 by anmande          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR		= 	srcs/
SRC			=	cub3d.c	windows.c tools.c	\

B_SRCDIR	= 	bonus/
B_SRC		=	cub3d.c	\

OBJDIR		= 	obj/
OBJ			= 	$(addprefix $(OBJDIR), $(SRC:.c=.o))

B_OBJDIR	= 	bonus_obj
B_OBJ		= 	$(addprefix $(B_OBJDIR), $(B_SRC:.c=.o))

NAME		= 	cub3D
B_NAME		= 	cub3D_bonus

LIBFT		=	./libft
MLX			=	./mlx

CC			= 	cc
RM			= 	rm -f
CFLAGS		= 	-Wall -Wextra -Werror -g

$(OBJDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(B_OBJDIR)%.o:	$(B_SRCDIR)%.c
					@mkdir -p $(B_OBJDIR)
					$(CC) -c -I $(LIBFT) $< -o $@
					$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME):		$(OBJ)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(B_NAME):		$(B_OBJ)
					cd $(LIBFT) && $(MAKE)
					cd $(MLX) && $(MAKE)
					$(CC) $(B_OBJ) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(B_NAME)

all:			$(NAME) $(B_NAME)

bonus:			$(B_NAME)

clean:
					$(RM) -r $(OBJDIR)
					$(RM) -r $(B_OBJDIR)
					cd $(LIBFT) && $(MAKE) clean
					cd $(MLX) && $(MAKE) clean

fclean:			clean
					$(RM) $(NAME)
					$(RM) $(B_NAME)
					touch a.o
					rm *.o

re:				fclean all

.PHONY:			all bonus clean fclean re norminette