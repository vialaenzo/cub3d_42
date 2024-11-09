/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:59:29 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:00:17 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_data *data, double delta_x, double delta_y)
{
	t_player *(p) = &data->player;
	char **(map) = data->map.map;
	if (map[(int)p->pos_y][(int)(p->pos_x + delta_x)] != '1')
		p->pos_x += delta_x;
	if (map[(int)(p->pos_y + delta_y)][(int)p->pos_x] != '1')
		p->pos_y += delta_y;
}

void	rotate(t_player *p, double rot)
{
	double (old_dir_x) = p->dir_x;
	p->dir_x = p->dir_x * cos(-rot) - p->dir_y * sin(-rot);
	p->dir_y = old_dir_x * sin(-rot) + p->dir_y * cos(-rot);
	double (old_plane_x) = p->plane_x;
	p->plane_x = p->plane_x * cos(-rot) - p->plane_y * sin(-rot);
	p->plane_y = old_plane_x * sin(-rot) + p->plane_y * cos(-rot);
}

static int	player_set_direction(t_player *p)
{
	if (p->dir == MAP_PLAYER_LEFT)
		return (p->dir_x = -1, p->dir_y = 0, p->plane_x = 0, p->plane_y = -FOV,
			1);
	if (p->dir == MAP_PLAYER_RIGHT)
		return (p->dir_x = +1, p->dir_y = 0, p->plane_x = 0, p->plane_y = +FOV,
			1);
	if (p->dir == MAP_PLAYER_NORTH)
		return (p->dir_x = 0, p->dir_y = -1, p->plane_x = +FOV, p->plane_y = 0,
			1);
	if (p->dir == MAP_PLAYER_SOUTH)
		return (p->dir_x = 0, p->dir_y = +1, p->plane_x = -FOV, p->plane_y = 0,
			1);
	return (0);
}

static int	player_set_location(t_player *player, char **map)
{
	int (x) = 0;
	int (y) = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr(MAP_PLAYER_CHARS, map[y][x]))
			{
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				return (1);
			}
		}
	}
	return (0);
}

int	player_init(t_player *player, char **map)
{
	if (!player_set_location(player, map))
		return (ft_error(NULL, ERR_PLAYER_LOCATION, 0));
	if (!player_set_direction(player))
		return (ft_error(NULL, ERR_PLAYER_DIRECTION, 0));
	return (1);
}
