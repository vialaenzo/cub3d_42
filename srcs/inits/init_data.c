/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:27 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:13:20 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_tex(t_data *data)
{
	data->texinfo.dire_tex[NORTH] = NULL;
	data->texinfo.dire_tex[SOUTH] = NULL;
	data->texinfo.dire_tex[EAST] = NULL;
	data->texinfo.dire_tex[WEST] = NULL;
	data->texinfo.wall_tex[NORTH].mlx_img = NULL;
	data->texinfo.wall_tex[SOUTH].mlx_img = NULL;
	data->texinfo.wall_tex[EAST].mlx_img = NULL;
	data->texinfo.wall_tex[WEST].mlx_img = NULL;
	return (SUCCESS);
}

static int	init_player(t_data *data)
{
	data->player.dir = MAP_VOID;
	return (SUCCESS);
}

static int	init_mlx(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img.mlx_img = NULL;
	return (SUCCESS);
}

static int	init_data(t_data *data, char **argv)
{
	data->texinfo.nb_tex = 0;
	data->texinfo.nb_colors = 0;
	data->count_line = 0;
	data->path_file = argv[1];
	data->map.map = NULL;
	int (i) = -1;
	while (++i < (2 * RGB_VALUES))
		data->texinfo.fc_tex[i / RGB_VALUES][i % RGB_VALUES] = -1;
	return (SUCCESS);
}

int	init_all(t_data *data, char **argv)
{
	if (!init_data(data, argv))
		return (ft_error("DATA", ERR_MALLOC, FAILURE));
	if (!init_file(data))
		exit(1);
	if (!init_tex(data))
		return (ft_error("TEXTURES", ERR_MALLOC, FAILURE));
	if (!init_mlx(data))
		return (ft_error("MLX", ERR_MALLOC, FAILURE));
	if (!init_player(data))
		return (ft_error("PLAYER", ERR_MALLOC, FAILURE));
	return (SUCCESS);
}
