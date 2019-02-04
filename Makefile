# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/06 18:02:33 by nkuchyna          #+#    #+#              #
#    Updated: 2018/08/06 18:05:28 by nkuchyna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d
LIBFT	= -L ./libft/ -lft
INC		= -I ./inc/ -I ./SDL/SDL2.framework/Headers\
		-I ./SDL/SDL2_image.framework/Headers\
		-I ./SDL/SDL2_ttf.framework/Headers \
		-I ./SDL/SDL2_mixer.framework/Headers
FRM		= -F ./SDL/ -framework SDL2 -framework SDL2_image -framework SDL2_ttf\
		-framework SDL2_mixer
GCC		= clang -Wall -Wextra -Werror -g -O3
SRC		= ./src/main.c \
		./src/init.c \
		./src/parse/ft_parse_scene.c \
		./src/parse/ft_create_surf_array.c \
		./src/parse/ft_create_map_array.c \
		./src/parse/ft_check_surf_components.c \
		./src/additional_functions.c \
		./src/loop.c \
		./src/ft_rotate_camera.c \
		./src/ft_raycasting.c \
		./src/ft_draw_pillar.c \
		./src/ft_apply_texture.c \
		./src/ft_draw_torch.c \
		./src/ft_load_cover.c \
		./src/ft_manage_movements.c \
		./src/free_functions.c
		
OBJ 	= $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(GCC)  -o $(NAME) $(OBJ) $(LIBFT) $(FRM) -rpath @loader_path/SDL
%.o : %.c ./inc/wolf3d.h
	 $(GCC) -c  $< -o $@ $(INC)
clean:
	rm -f $(OBJ)
	make clean -C libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
re: fclean all
