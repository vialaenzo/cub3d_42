/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:47 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:17:22 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_mouse_press(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == MOUSE_LEFT)
		data->mouse = true;
	if (button == MOUSE_RIGHT)
	{
		data->mouse = false;
		mlx_mouse_show(data->mlx, data->win);
	}
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	(void)data;
	(void)y;
	if (!data->mouse)
		return (0);
	if (x < WIN_WIDTH / 2 - 1)
		rotate(&data->player, ROTSPEED / 10);
	if (x > WIN_WIDTH / 2 + 1)
		rotate(&data->player, -ROTSPEED / 10);
	return (0);
}
