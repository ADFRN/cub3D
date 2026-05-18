# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 14:02:54 by afournie          #+#    #+#              #
#    Updated: 2026/05/15 17:04:47 by afournie         ###   ########.fr        #
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
INC           = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

INC_DIR       = includes
MINILIBX_DIR  = minilibx
LIBFT_DIR     = libft
SRC_DIR       = src
OBJ_DIR       = obj

LIBFT         = $(LIBFT_DIR)/libft.a
MINILIBX      = $(MINILIBX_DIR)/libmlx_Linux.a
OBJS          = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS          =	$(SRC_DIR)/main.c								\
				$(SRC_DIR)/DEBUG.c								\
				$(SRC_DIR)/parsing/textures.c					\
				$(SRC_DIR)/parsing/colors.c						\
				$(SRC_DIR)/parsing/parsing.c					\
				$(SRC_DIR)/parsing/verify.c						\
				$(SRC_DIR)/player/mouse_action.c				\
				$(SRC_DIR)/player/player_action.c				\
				$(SRC_DIR)/player/player.c						\
				$(SRC_DIR)/raycast/raycaster.c					\
				$(SRC_DIR)/render/draw.c						\
				$(SRC_DIR)/render/render.c						\
				$(SRC_DIR)/structures/t_data.c					\
				$(SRC_DIR)/structures/t_game.c					\
				$(SRC_DIR)/structures/t_keys.c					\
				$(SRC_DIR)/structures/t_map.c					\
				$(SRC_DIR)/structures/t_player.c				\
				$(SRC_DIR)/structures/t_ray.c					\
				$(SRC_DIR)/utils/mlx_utils.c					\
				$(SRC_DIR)/utils/utils.c						\

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -L$(MINILIBX_DIR) -lXext -lX11 -lm -o $(NAME)
	@printf "$(GREEN)$(NAME) est compilé avec succès !           $(RESET)\n"


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	@printf "$(GREEN)Minilibx compilé avec succès !           $(RESET)\n"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/cub3D.h
	@mkdir -p $(dir $@)
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
