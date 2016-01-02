# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoignet <jcoignet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/17 18:32:43 by jcoignet          #+#    #+#              #
#    Updated: 2015/11/26 19:30:35 by jcoignet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_traceroute
GCC = gcc -Wall -Wextra -Werror
INCLUDES = ./includes/
SRCDIR = ./srcs/
SRCNAMES = main.c \
		   ft_sqrt.c \
		   pinger.c \
		   catcher.c \
		   options.c
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ = $(patsubst $(SRCDIR)%.c,%.o,$(SRC))
LFTDIR = ./libft
LFT = $(LFTDIR)/libft.a

all: $(LFT) $(NAME)

$(LFT):
	make -C $(LFTDIR)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) -L$(LFTDIR) -lft

$(OBJ): $(SRC)
	$(GCC) -c $(SRC) -I$(INCLUDES) -I$(LFTDIR)/includes

clean:
	make -C $(LFTDIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LFTDIR) fclean
	rm -rf $(NAME)

re: fclean all
	make -C $(LFTDIR) re

.PHONE: clean fclean all re
