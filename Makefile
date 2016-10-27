# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgulista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 16:13:34 by wgulista          #+#    #+#              #
#*   Updated: 2016/10/20 16:34:45 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = wgulista.filler
LIBFT = libft.a
MINILIBX = libmlx.a
SRC_NAME = 	main.c check.c math.c filler.c tools.c parse.c solver.c display.c
OBJ_PATH = obj
SRC_PATH = srcs

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LIBX = -L ./libft/ -lft -I/usr/local/include -I/usr/local/lib \
		-L ./minilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	@gcc $(LIBX) $(OBJ) -o $(NAME)
	@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(LIBFT):
	@make -C ./libft/

$(MINILIBX):
	@make -C ./minilibx/

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
	@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) -o $@ -c $^
	@echo "\033[33mLinking" [ $< ] "\033[0m"

norme:
	@echo "\033[32mNorminette LIBFT\033[0m"
	@norminette ./libft/
	@echo "\033[32mNorminette FILLER HEADER\033[0m"
	@norminette ./includes/filler.h
	@echo "\033[32mNorminette FILLER SOURCES\033[0m"
	@norminette ./srcs/

clean:
	@rm -fv $(OBJ)
	@rm -Rf $(OBJ_PATH)
	@make clean -C ./libft/
	@make clean -C ./minilibx/
	@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@make fclean -C ./libft/
	@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all

.PHONY: all clean fclean re
