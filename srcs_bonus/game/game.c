/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:04:18 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:04:19 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAILURE);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (data->win == NULL)
		return (FAILURE);
	data->mouse = false;
	data->img.mlx_img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.mlx_img)
		return (FAILURE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.len, &data->img.endian);
	if (!data->img.addr)
		return (FAILURE);
	return (SUCCESS);
}
