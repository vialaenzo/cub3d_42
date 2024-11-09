/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:56:19 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 11:56:20 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_input(argc, argv))
		return (FAILURE);
	if (init_all(&data, argv) && parsing(&data) && game_init(&data)
		&& player_init(&data.player, data.map.map) && init_imgs(&data))
	{
		hook_init(&data);
		mlx_loop_hook(data.mlx, &handle_loop, &data);
		mlx_loop(data.mlx);
	}
	return (free_everything(&data), 0);
}
