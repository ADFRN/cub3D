# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 14:02:54 by afournie          #+#    #+#              #
#    Updated: 2026/05/05 14:29:08 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS     += -s

NAME          = cub3D
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -g
INC           = -I includes -I $(LIBFT_DIR) -I $(MINILIBX_DIR)

INC_DIR       = includes
MINILIBX_DIR  = minilibx
LIBFT_DIR     = libft
SRC_DIR       = src
OBJ_DIR       = obj

LIBFT         = $(LIBFT_DIR)/libft.a
MINILIBX      = $(MINILIBX_DIR)/libmlx_Linux.a
OBJS          = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS          = $(SRC_DIR)/main.c

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -L$(MINILIBX_DIR) -lXext -lX11 -lm -o $(NAME)
	@echo "$(NAME) generated"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "libft generated"

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	@echo "minilibx generated"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
