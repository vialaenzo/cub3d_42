/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:55:53 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:15:58 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "error.h"
# include "keycode.h"
# include "libft.h"
# include "map.h"
# include "mlx.h"
# include "mouse.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define NB_ARGS 2

# define WIN_TITLE "cub3d"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 960

# define MOVESPEED 0.25
# define ROTSPEED 0.30
# define FOV 0.74

typedef enum s_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NB_TEX
}					t_directions;

typedef enum s_tex_fc
{
	FLOOR,
	CEILING,
	NB_COLORS
}					t_tex_fc;

# define RGB_VALUES 3

/*Structures*/
typedef struct s_player
{
	char			dir;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct s_texinfo
{
	char			*dire_tex[4];
	t_img			wall_tex[4];

	int				nb_tex;
	int				nb_colors;
	int				fc_tex[2][3];
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
}					t_texinfo;

typedef struct s_mapinfo
{
	char			**map;
	int				map_width;
	int				map_height;
}					t_mapinfo;

typedef struct s_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
}					t_raycast;

typedef struct s_minimap
{
	char			**map;
	t_img			*img;
	int				size;
	int				offset_x;
	int				offset_y;
	int				view_dist;
	int				tile_size;
}					t_minimap;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			img;
	char			**file;
	bool			mouse;
	char			*file_str;
	char			*path_file;
	t_mapinfo		map;
	t_img			minimap;
	t_player		player;
	t_texinfo		texinfo;
	int				count_line;
}					t_data;

/* srcs/minimap/minimap_utils.c */
int					render_minimap_image(t_data *data, t_minimap *minimap);

/* srcs/minimap/minimap.c */
int					render_minimap(t_data *data);

/* srcs/parsing/check_input.c */
bool				check_input(int argc, char **argv);

/* srcs/parsing/parsing.c */
int					parsing(t_data *data);

/* srcs/parsing/parsing_map.c */
int					fill_map(t_data *data);

/* srcs/parsing/parsing_colrs_tex.c */
int					fill_textures(char *line, t_data *data);
int					fill_colors(char *line, t_data *data);
int					fill_tex_colrs(t_data *data);

/* srcs/parsing/parsing_utils.c */
int					find_tex(char *line);
void				replace_char(char *str, char old_char, char new_char);

/* srcs/parsing/ft_floodfill.c */
int					ft_floodfill(t_data *data);

/* srcs/parsing/check_map.c */
int					check_map(t_data *data);

/* srcs/utils/error.c */
int					ft_error(char *detail, char *str, int code);

/* srcs/utils/ft_free.c */
int					free_everything(t_data *data);

/* srcs/utils/debug.c */
void				display_tex(t_data *data);

/* srcs/utils/utils.c */
int					is_whitespace(char c);
void				skip_whitespace(char **line);
int					check_extensions(char *str, char *ext);

/* srcs/game/game.c */
int					game_init(t_data *data);

/* srcs/render/render.c */
int					render(t_data *data);
void				put_pixel(t_img *img, int x, int y, int color);

/* srcs/render/render_utils.c */
int					init_dda(t_data *data, t_raycast *raycast);
int					ft_dda(t_data *data, t_raycast *raycast);
int					raycast_wall_height(t_raycast *raycast);
int					raycast_touch_part(t_data *data, t_raycast *raycast);

/* srcs/render/render_utils2.c */
int					tab_to_color(char t, char r, char g, char b);
void				put_pixel(t_img *img, int x, int y, int color);
int					which_face(t_data *data, t_raycast *raycast);

/* srcs/player/player.c */
int					player_init(t_player *player, char **map);
void				rotate(t_player *p, double rot);
void				move(t_data *data, double delta_x, double delta_y);

/* srcs/inits/init_data.c */
int					init_all(t_data *data, char **argv);

/* srcs/inits/init_map.c */
int					init_map(t_data *data);

/* srcs/inits/init_file.c */
int					init_file(t_data *data);
size_t				ft_len_split(char **split);

/* srcs/hook/hook.c */
int					handle_quit(t_data *data);
int					handle_loop(t_data *data);
void				hook_init(t_data *data);

/* srcs/inits/init_img_tex.c */
int					init_imgs(t_data *data);
int					init_img_clean(t_img *img);

/* srcs/hook/mouse.c */
int					handle_mouse_press(int button, int x, int y, t_data *data);
int					handle_mouse_move(int x, int y, t_data *data);

/* srcs/hook/focus.c */
int					handle_focus_in(t_data *data);
int					handle_focus_out(t_data *data);

/* srcs/hook/keyboard.c */
int					handle_keypress(int keycode, t_data *data);

#endif
