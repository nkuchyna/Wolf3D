/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:05:50 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/06 18:09:26 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF3D_H
# define FT_WOLF3D_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include <errno.h>
# include <time.h>
# define WIDTH	640
# define H		400
# define SHIFT	0.03
# define SIZE	10
# define NUM_THREADS			1
# define INIT_LIB_ERROR			0
# define NO_BLOCK_ERROR			-1
# define BLOCK_IND_ERROR		-2
# define SCENE_IND_ERROR		-3
# define ARR_ALLOC_ERROR		-4
# define WRONG_PATH				-5
# define VECTOR_ERROR			-6
# define ERROR_DESCR			-7
# define FLOOR					22
# define CEILING				33
# define EXIT					42
# define MULT(v, k)	(v * (t_vector){k, k})
# define MULT_C(v, k)	(v * (t_color){k, k, k})
# define DOT(v1, v2) (v1[0] * v2[0] + v1[1] * v2[1])
# define LEN(v) (sqrt(v[0] * v[0] + v[1] * v[1]))
# define NORM(v) (MULT(v, (1 / LEN(v))))

typedef double		t_vector __attribute__((vector_size(sizeof(double)*2)));
typedef double		t_color __attribute__((vector_size(sizeof(double)*3)));

typedef struct		s_surf
{
	SDL_Surface		*text;
	t_color			color;
	int				id;
	int				count;
	int				visible;
}					t_surf;

typedef struct		s_level
{
	t_vector		pos;
	t_vector		exit;
	t_surf			floor_surf;
	int				**map;
	int				w;
	int				h;
}					t_level;

typedef struct		s_sd
{
	SDL_Window		*window;
	SDL_Surface		**torch;
	SDL_Surface		*screen;
	SDL_Surface		*cover;
	SDL_Surface		*fire;
	SDL_Surface		*info;
	SDL_Surface		*finish;
	SDL_Surface		*l_text;
	SDL_Event		event;
	Mix_Music		*music;
	Mix_Chunk		*sound1;
	Mix_Chunk		*sound2;
	Mix_Chunk		*win_sound;
	Mix_Chunk		*level_sound;
	TTF_Font		*font;
	SDL_Rect		text_place;
	SDL_Color		text_col;
	t_surf			*surf;
	t_surf			ceiling_surf;
	t_surf			exit_surf;
	t_level			*levels;
	t_vector		map_pos;
	t_vector		dir;
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		plane;
	t_vector		draw;
	t_color			color;
	double			wall_dist;
	double			wall_x;
	clock_t			time;
	int				line_height;
	int				pgm_run;
	int				surf_nbr;
	int				sprite_nbr;
	int				wall_id;
	int				side_text;
	int				go;
	int				rotate;
	int				l_nbr;

}					t_sd;

void				ft_init_sd(t_sd *sd);
int					ft_init_sdl(t_sd *sd);
void				ft_init_music(t_sd *sd);
void				ft_init(const Uint8 **kb_state, int *cover,
								int *c, int *info);
int					ft_count_elements(char *str);
int					ft_parse_scene(int *fd, t_sd *sd);
int					ft_check_map(t_vector map_pos, int **map,
								int width, int height);
int					ft_check_surf_components(char *line, int str_nbr);
int					**ft_create_map_array(t_level *level, char *str_scene);
t_surf				*ft_create_surf_array(int fd, int *surf_nbr);
void				ft_delete_int_array(int **array, int size);
void				ft_free_surf_array(t_surf *surf, int size);
void				ft_loop(t_sd *sd);
void				ft_manage_movements(t_sd *sd, t_level *level);
int					ft_load_cover(t_sd *sd);
t_vector			ft_rotate_vector(t_vector dir, double ang);
void				ft_rotate_camera(t_sd *sd, double ang);
void				*ft_raycasting(t_sd *sd);
void				ft_draw_pillar(t_sd *sd, int side, t_vector step, int x);
void				ft_draw_torch(SDL_Surface **torch, t_sd *sd);
t_color				ft_apply_wall_text(t_sd *sd, double y,
										t_surf *surf, int side);
t_color				ft_apply_text(t_sd *sd, double y, t_surf *surf,
										t_vector floor_wall);
t_color				ft_color_from_texture(int t_x, int t_y, SDL_Surface *text);
void				ft_putpixel(int x, int y, SDL_Surface *screen,
										t_color color);
void				ft_exit(t_sd sd, int surf_nbr);
void				ft_print_img(SDL_Surface *img, SDL_Surface *screen,
										int dx, int dy);

#endif
