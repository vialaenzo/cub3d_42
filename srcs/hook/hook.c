/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:32 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:59 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_quit(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (1);
}

int	handle_loop(t_data *data)
{
	render(data);
	return (0);
}

void	hook_init(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win, 9, 1L << 21, &handle_focus_in, data);
	mlx_hook(data->win, 10, 1L << 21, &handle_focus_out, data);
	mlx_hook(data->win, 17, 0l, &handle_quit, data);
}
