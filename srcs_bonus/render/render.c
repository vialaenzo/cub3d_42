/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:57:40 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 11:58:16 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel(t_img *img, int x, int y)
{
	int		color;
	int		i;
	char	*pixel;

	color = 0;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			color |= ((unsigned char)(*pixel++) << i);
		else
			color |= ((unsigned char)(*pixel++) << (img->bpp - 8 - i));
		i -= 8;
	}
	return (color);
}

void	render_textured(t_data *data, t_raycast *raycast, int x)
{
	int (y) = 0;
	int (face) = which_face(data, raycast);
	t_img (texture) = data->texinfo.wall_tex[face];
	double (step) = 1 * (double)64 / raycast->line_height;
	double (tex_pos) = (raycast->draw_start - (double)WIN_HEIGHT / 2
			+ raycast->line_height / 2) * step;
	int *(floor_tab) = data->texinfo.fc_tex[FLOOR];
	int *(ceiling_tab) = data->texinfo.fc_tex[CEILING];
	int (floor_color) = tab_to_color(0, floor_tab[0], floor_tab[1],
			floor_tab[2]);
	int (ceiling_color) = tab_to_color(0, ceiling_tab[0], ceiling_tab[1],
			ceiling_tab[2]);
	while (y < raycast->draw_start)
		put_pixel(&data->img, x, y++, ceiling_color);
	while (y < raycast->draw_end)
	{
		put_pixel(&data->img, x, y, get_pixel(&texture, raycast->tex_x,
				tex_pos));
		tex_pos += step;
		if (tex_pos >= 64)
			tex_pos = 63;
		y++;
	}
	while (y < WIN_HEIGHT)
		put_pixel(&data->img, x, y++, floor_color);
}

int	init_raycast(t_data *data, t_raycast *raycast, int x)
{
	raycast->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	raycast->ray_dir_x = data->player.dir_x + data->player.plane_x
		* raycast->camera_x;
	raycast->ray_dir_y = data->player.dir_y + data->player.plane_y
		* raycast->camera_x;
	raycast->map_x = (int)data->player.pos_x;
	raycast->map_y = (int)data->player.pos_y;
	raycast->side_dist_x = 0.0;
	raycast->side_dist_y = 0.0;
	raycast->delta_dist_x = 1e30;
	raycast->delta_dist_y = 1e30;
	if (raycast->ray_dir_x != 0)
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	if (raycast->ray_dir_y != 0)
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	raycast->perp_wall_dist = 0.0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->hit = 0;
	raycast->side = 0;
	return (SUCCESS);
}

int	raycast(t_data *data)
{
	int (x) = 0;
	t_raycast(raycast);
	while (x < WIN_WIDTH)
	{
		init_raycast(data, &raycast, x);
		init_dda(data, &raycast);
		ft_dda(data, &raycast);
		raycast_wall_height(&raycast);
		raycast_touch_part(data, &raycast);
		render_textured(data, &raycast, x);
		x++;
	}
	return (SUCCESS);
}

int	render(t_data *data)
{
	raycast(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}
