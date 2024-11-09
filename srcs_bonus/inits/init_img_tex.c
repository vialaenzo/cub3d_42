/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:12 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:10:45 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_imgs(t_data *data)
{
	int (x) = -1;
	int (v) = 0;
	t_img(tex);
	while (++x < NB_TEX)
	{
		tex.mlx_img = mlx_xpm_file_to_image(data->mlx,
				data->texinfo.dire_tex[x], &v, &v);
		if (!tex.mlx_img)
			return (0);
		tex.addr = mlx_get_data_addr(tex.mlx_img, &tex.bpp, &tex.len,
				&tex.endian);
		data->texinfo.wall_tex[x] = tex;
	}
	return (1);
}

int	init_img_clean(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->len = 0;
	img->endian = 0;
	return (SUCCESS);
}
