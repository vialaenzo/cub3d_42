/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:57:20 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 11:57:21 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_tex(t_data *data)
{
	ft_printf(2, "Nombre de lignes du fichier : %d\n\n", data->count_line);
	char *(direction_names)[] = {"NORTH", "SOUTH", "EAST", "WEST"};
	char *(colors_name)[] = {"FLOOR", "CELLING"};
	int (i) = -1;
	while (++i < 4)
	{
		if (data->texinfo.dire_tex[i])
			ft_printf(2, "Debug Texture : %s : %s\n", direction_names[i],
				data->texinfo.dire_tex[i]);
	}
	i = -1;
	while (++i < 2)
	{
		ft_printf(2, "Debug Color: %s : %d,%d,%d\n", colors_name[i],
			data->texinfo.fc_tex[i][0], data->texinfo.fc_tex[i][1],
			data->texinfo.fc_tex[i][2]);
	}
	ft_printf(2, "\nDebug map width : %d\n", data->map.map_width);
	ft_printf(2, "Debug map height : %d\n", data->map.map_height);
	i = -1;
	while (data->map.map[++i])
		printf("Debug map [%3d] : %s\n", i, data->map.map[i]);
}
