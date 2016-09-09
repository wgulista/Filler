#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgulista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/12 16:11:57 by wgulista          #+#    #+#              #
#*   Updated: 2016/07/20 15:50:13 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = wgulista.filler
LIBFT = libft.a
SRC_NAME = 	main.c env.c player.c map.c piece.c solver.c tools.c error.c

OBJ_PATH = obj
SRC_PATH = srcs

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc -Llibft $(OBJ) -lft -o $(NAME)
	@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(LIBFT):
	@make -C ./libft/

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
	@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) -o $@ -c $^
	@echo "\033[33mLinking" [ $< ] "\033[0m"

clean:
	@rm -fv $(OBJ)
	@rm -Rf $(OBJ_PATH)
	@make clean -C ./libft/
	@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@make fclean -C ./libft/
	@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all
