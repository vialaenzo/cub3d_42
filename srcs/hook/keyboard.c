/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:34 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:13:05 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_data *data)
{
	t_player *(p) = &data->player;
	if (keycode == KEYCODE_ECHAP)
		handle_quit(data);
	else if (keycode == KEYCODE_W)
		move(data, p->dir_x * MOVESPEED, p->dir_y * MOVESPEED);
	else if (keycode == KEYCODE_A)
		move(data, p->dir_y * MOVESPEED, p->dir_x * -MOVESPEED);
	else if (keycode == KEYCODE_S)
		move(data, p->dir_x * -MOVESPEED, p->dir_y * -MOVESPEED);
	else if (keycode == KEYCODE_D)
		move(data, p->dir_y * -MOVESPEED, p->dir_x * MOVESPEED);
	else if (keycode == KEYCODE_RIGHT)
		rotate(&data->player, -ROTSPEED);
	else if (keycode == KEYCODE_LEFT)
		rotate(&data->player, ROTSPEED);
	return (0);
}
