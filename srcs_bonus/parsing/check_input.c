/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:10 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:03:11 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_input(int argc, char **argv)
{
	if (argc != NB_ARGS)
		return (ft_error(NULL, ERR_ARG_COUNT, false));
	if (!check_extensions(argv[1], MAP_EXTENSION))
		return (FAILURE);
	return (true);
}
