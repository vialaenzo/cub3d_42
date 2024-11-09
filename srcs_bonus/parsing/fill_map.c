/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:01:07 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:01:08 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_width(t_data *data, int file_i)
{
	int (i) = file_i;
	int (j) = -1;
	int (max) = 0;
	while (data->file[++i])
	{
		j = -1;
		while (data->file[i][++j])
		{
			if (ft_strchr(VALID_CHARACTERS, data->file[i][j]) && j > max)
				max = j;
		}
	}
	data->map.map_width = max + 1;
	return (SUCCESS);
}

static void	memcpy_data(int file_i, int map_i, t_data *data)
{
	if (ft_strlen(data->file[file_i]) > (size_t)data->map.map_width)
		ft_memcpy(data->map.map[map_i], data->file[file_i],
			data->map.map_width);
	else
		ft_memcpy(data->map.map[map_i], data->file[file_i],
			ft_strlen(data->file[file_i]));
}

int	fill_map(t_data *data)
{
	data->map.map = malloc(sizeof(char *) * ((data->count_line - (NB_COLORS
						+ NB_TEX)) + 1));
	int (file_i) = NB_COLORS + NB_TEX - 1;
	int (map_i) = -1;
	get_map_width(data, file_i);
	while (++file_i < data->count_line)
	{
		data->map.map[++map_i] = malloc(sizeof(char) * (data->map.map_width
					+ 1));
		if (!data->map.map[map_i])
		{
			while (map_i >= 0)
				free(data->map.map[map_i--]);
			free(data->map.map);
			return (ft_error(data->file[file_i], ERR_MALLOC, FAILURE));
		}
		ft_memset(data->map.map[map_i], MAP_VOID, data->map.map_width);
		memcpy_data(file_i, map_i, data);
		data->map.map[map_i][data->map.map_width] = '\0';
	}
	data->map.map[++map_i] = NULL;
	return (data->map.map_height = map_i, SUCCESS);
}
