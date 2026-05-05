# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 14:02:54 by afournie          #+#    #+#              #
#    Updated: 2026/05/05 14:09:52 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

NAME          = cub3D
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -g


LIBFT_DIR     = libft
LIBFT         = $(LIBFT_DIR)/libft.a

PRINTF_DIR    = printf
PRINTF        = $(PRINTF_DIR)/libftprintf.a

MINILIBX      = minilibx/libmlx_Linux.a

INC           = -I includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MINILIBX_DIR)

SRC_DIR       = src
OBJ_DIR		  = obj
INC_DIR		  = includes

SRCS          = $(SRCS_DIR)/main.c

OBJS		  =	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MINILIBX) -L.. -Lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(NAME) generated"

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "libft generated"

$(PRINTF):
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@echo "printf generated"

$(MINILIBX):
	@make -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "minilibx generated"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@make -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@make -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
