SRC_DIR				=	src/
SRC_FILES			=	enemies_list.c			enemies_movement.c		\
						file_check.c			free_img.c				\
						free_mem.c				game_results.c			\
						get_anim_images.c		get_images.c			\
						keypress_handler.c		point_to_image.c		\
						so_long.c				validate_map.c			\
						window_functions.c
SRC					=	$(addprefix $(SRC_DIR), $(SRC_FILES))

UTILS_DIR			=	utils/
UTILS_FILES			=	ft_itoa.c				ft_putstr.c				\
						ft_split.c				ft_strlcpy.c			\
						ft_strlen.c				ft_strncmp.c
UTILS				=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ_DIR				=	obj/
OBJ					=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))		\
						$(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))

MLX_DIR				=	libraries/minilibx-linux/
MLX_LIB				=	libmlx.a
MLX					=	$(addprefix $(MLX_DIR), $(MLX_LIB))
MLX_INCLUDE			=	mlx.h
MLXFLAGS			=	-lX11 -lXext

INCLUDES_DIR		=	includes/
INCLUDES_FILES		=	so_long.h
INCLUDES			=	$(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES))	\
						$(addprefix $(MLX_DIR), $(MLX_INCLUDE))
NAME				=	so_long
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) -o $@
	@echo "\n\n\
<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n\
<                                                    >\n\
<            YOUR GAME IS READY TO PLAY              >\n\
<      Type \033[45m\"./so_long <map_name>.ber\"\033[m to play       >\n\
< Type \033[45m\"ls -1 maps/*ber\"\033[m to see the available maps   >\n\
<                                                    >\n\
<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n\n"


$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR)%.o: */%.c $(INLCUDES) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(INCLUDES_DIR) -I$(MLX_DIR)

clean:
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re