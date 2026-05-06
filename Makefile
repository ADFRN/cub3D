# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 14:02:54 by afournie          #+#    #+#              #
#    Updated: 2026/05/06 18:27:12 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS     += -s

RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
MAGENTA = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m
RESET   = \033[0m

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
	@printf "$(GREEN)$(NAME) est compilé avec succès !           $(RESET)\n"


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	@printf "$(GREEN)Minilibx compilé avec succès !           $(RESET)\n"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)Objets nettoyés.$(RESET)\n"


fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) supprimé.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
