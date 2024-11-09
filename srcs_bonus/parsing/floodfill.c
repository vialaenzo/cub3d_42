/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:00:59 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:01:00 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_floodfill_rec(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->map.map_width || y < 0 || y >= data->map.map_height)
		return (SUCCESS);
	if (data->map.map[y][x] != MAP_WALL && data->map.map[y][x] != MAP_SPACE
		&& data->map.map[y][x] != MAP_VOID)
		return (FAILURE);
	if (data->map.map[y][x] == MAP_SPACE || data->map.map[y][x] == MAP_WALL)
		return (SUCCESS);
	data->map.map[y][x] = MAP_SPACE;
	if (!ft_floodfill_rec(data, x + 1, y))
		return (FAILURE);
	if (!ft_floodfill_rec(data, x - 1, y))
		return (FAILURE);
	if (!ft_floodfill_rec(data, x, y + 1))
		return (FAILURE);
	if (!ft_floodfill_rec(data, x, y - 1))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_floodfill(t_data *data)
{
	int (x) = -1;
	int (y) = -1;
	while (++y < data->map.map_height)
	{
		x = -1;
		while (++x < data->map.map_width)
		{
			if (y == 0 || y == data->map.map_height - 1 || x == 0
				|| x == data->map.map_width - 1)
			{
				if (data->map.map[y][x] != MAP_WALL
					&& data->map.map[y][x] != MAP_VOID
					&& data->map.map[y][x] != MAP_SPACE)
					return (ft_error(NULL, ERR_FLOODFILL_BORDER, FAILURE));
			}
			if (data->map.map[y][x] == MAP_VOID)
			{
				if (!ft_floodfill_rec(data, x, y))
					return (ft_error(NULL, ERR_FLOODFILL, FAILURE));
			}
		}
	}
	return (SUCCESS);
}
