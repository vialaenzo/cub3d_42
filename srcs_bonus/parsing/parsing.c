/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:00:54 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:00:55 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_tex(t_data *data)
{
	int (fd) = 0;
	int (i) = -1;
	while (++i < NB_TEX)
	{
		if (!check_extensions(data->texinfo.dire_tex[i], TEXTURE_EXTENSION))
			return (FAILURE);
		fd = open(data->texinfo.dire_tex[i], O_RDONLY);
		if (fd < 0)
			return (ft_error(data->texinfo.dire_tex[i], ERR_TEX_NF, FAILURE));
		close(fd);
	}
	return (SUCCESS);
}

int	parsing(t_data *data)
{
	if (!fill_tex_colrs(data) || !check_tex(data))
		return (FAILURE);
	if (!fill_map(data) || !check_map(data))
		return (FAILURE);
	display_tex(data);
	return (SUCCESS);
}
