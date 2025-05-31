# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaso <yaso@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 14:25:04 by yaso              #+#    #+#              #
#    Updated: 2025/05/28 17:47:56 by yaso             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./ft_printf_src
OBJDIR = ./obj

SRC = ft_printf.c ft_printf_utils.c ft_putnbr_hex.c ft_put_uint.c ft_putptr.c libft.c
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

#Rules
all : $(NAME)

$(NAME): $(OBJ)
	ar	rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re