/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:57:52 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 11:59:14 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tab_to_color(char t, char r, char g, char b)
{
	return (*(int *)(char []){b, g, r, t});
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	int (i) = img->bpp - 8;
	char *(pixel) = img->addr + (y * img->len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	which_face(t_data *data, t_raycast *raycast)
{
	(void)data;
	if (!raycast->side && data->player.pos_x < raycast->map_x)
		return (WEST);
	if (!raycast->side && data->player.pos_x > raycast->map_x)
		return (EAST);
	if (raycast->side && data->player.pos_y < raycast->map_y)
		return (NORTH);
	if (raycast->side && data->player.pos_y > raycast->map_y)
		return (SOUTH);
	return (0);
}
