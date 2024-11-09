/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:04 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:03:05 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_str_skipper(t_data *data, char **map_start)
{
	char *(file_str) = data->file_str;
	int (count) = 0;
	while (count != 6 && *file_str != '\0')
	{
		while (*file_str == '\n')
			file_str++;
		if (*file_str != '\n' && *file_str != '\0')
		{
			count++;
			while (*file_str != '\n' && *file_str != '\0')
				file_str++;
		}
		if (*file_str != '\0')
			file_str++;
	}
	if (count != 6)
		return (FAILURE);
	while (*file_str == '\n')
		file_str++;
	if (*file_str == '\0')
		return (FAILURE);
	*map_start = file_str;
	return (SUCCESS);
}

static int	check_map_extra(t_data *data, char *map_s, int len_map)
{
	char (c)[2] = {0, 0};
	char (last_c) = '1';
	int (i) = -1;
	while (map_s[++i] != '\0' && i < len_map)
	{
		if (ft_strchr(MAP_PLAYER_CHARS, map_s[i]))
		{
			if (data->player.dir == MAP_VOID)
				data->player.dir = map_s[i];
			else
				return (c[0] = map_s[i], ft_error(c, ERR_PLAYER_MULT, 0));
		}
		last_c = MAP_VOID;
		if (!ft_strchr(VALID_CHARACTERS, map_s[i]) && map_s[i] != '\n')
			return (c[0] = map_s[i], ft_error(c, ERR_INVALID_CHAR, 0));
		if (map_s[i] == '\n' && map_s[i + 1] == ' ')
		{
			last_c = map_s[i++];
			while (map_s[i] == ' ')
				i++;
		}
		if (map_s[i] == '\n' && (map_s[i + 1] == '\n' || last_c == '\n'))
			return (ft_error("Find double \\n", ERR_JUMP_MAP, FAILURE));
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	char *(map_start) = NULL;
	if (!map_str_skipper(data, &map_start))
		return (ft_error(NULL, ERR_CHECK_MAP, FAILURE));
	int (len_map) = ft_strlen(map_start) - 1;
	while (map_start[len_map] == '\n' && map_start[len_map - 1] == '\n')
		len_map--;
	if (!check_map_extra(data, map_start, len_map))
		return (FAILURE);
	if (!ft_strchr(MAP_PLAYER_CHARS, data->player.dir))
		return (ft_error(NULL, ERR_PLAYER_NF, FAILURE));
	return (ft_floodfill(data));
}
