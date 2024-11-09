/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:08 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:09 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_dda(t_data *data, t_raycast *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (data->player.pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - data->player.pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (data->player.pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - data->player.pos_y)
			* raycast->delta_dist_y;
	}
	return (SUCCESS);
}

int	ft_dda(t_data *data, t_raycast *raycast)
{
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (data->map.map[raycast->map_y][raycast->map_x] == '1')
			raycast->hit = 1;
	}
	if (raycast->side == 0)
		raycast->perp_wall_dist = (raycast->map_x - data->player.pos_x
				+ (double)(1 - raycast->step_x) / 2) / raycast->ray_dir_x;
	else
		raycast->perp_wall_dist = (raycast->map_y - data->player.pos_y
				+ (double)(1 - raycast->step_y) / 2) / raycast->ray_dir_y;
	return (SUCCESS);
}

int	raycast_wall_height(t_raycast *raycast)
{
	raycast->line_height = (int)(WIN_HEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + WIN_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + WIN_HEIGHT / 2;
	if (raycast->draw_end >= WIN_HEIGHT)
		raycast->draw_end = WIN_HEIGHT - 1;
	return (SUCCESS);
}

int	raycast_touch_part(t_data *data, t_raycast *raycast)
{
	if (raycast->side == 0)
		raycast->wall_x = data->player.pos_y + raycast->perp_wall_dist
			* raycast->ray_dir_y;
	else
		raycast->wall_x = data->player.pos_x + raycast->perp_wall_dist
			* raycast->ray_dir_x;
	raycast->wall_x -= floor(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x * (double)64);
	if ((raycast->side == 0 && raycast->ray_dir_x > 0) || (raycast->side == 1
			&& raycast->ray_dir_y < 0))
		raycast->tex_x = 64 - raycast->tex_x - 1;
	return (SUCCESS);
}
