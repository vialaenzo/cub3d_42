/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:31 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:47 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_focus_in(t_data *data)
{
	(void)data;
	return (0);
}

int	handle_focus_out(t_data *data)
{
	data->mouse = false;
	mlx_mouse_show(data->mlx, data->win);
	return (0);
}
