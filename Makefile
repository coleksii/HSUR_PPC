# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coleksii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 13:59:24 by coleksii          #+#    #+#              #
#    Updated: 2018/03/19 14:01:44 by coleksii         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = @clang++

NAME = ft_retro

FILES_NAME = Bullet Enemy Fps Game main Menu NLO Spaceship Window


FILES = $(addsuffix .cpp, $(FILES_NAME))
FILES_OBJ = $(addsuffix .o, $(FILES_NAME))

all: $(NAME)

$(NAME): $(FILES_OBJ)
	@clang++ -o $@ $^ -Wall -Wextra -Werror -lncurses
	@echo "\033[32;1m<<ft_retro done>>\033[0m"

clean:
	@rm -rf $(addsuffix .o, $(FILES_NAME))
	@echo "\033[32;1m<<object files cleaned>>\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[32;1m<<program cleaned>>\033[0m"

re: fclean all
	@echo "\033[32;1m<<re ft_retro succes>>\033[0m"
