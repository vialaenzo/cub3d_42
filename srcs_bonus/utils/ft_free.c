/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:56:35 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:10:37 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_everything(t_data *data)
{
	int (x) = -1;
	while (++x < NB_TEX)
	{
		if (data->texinfo.dire_tex[x])
			free(data->texinfo.dire_tex[x]);
		if (data->mlx && data->texinfo.wall_tex[x].mlx_img)
			mlx_destroy_image(data->mlx, data->texinfo.wall_tex[x].mlx_img);
	}
	if (data->file)
		ft_free_tab(data->file);
	if (data->map.map)
		ft_free_tab(data->map.map);
	if (data->file_str)
		free(data->file_str);
	if (data->mlx)
	{
		if (data->img.mlx_img)
			mlx_destroy_image(data->mlx, data->img.mlx_img);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (SUCCESS);
}
