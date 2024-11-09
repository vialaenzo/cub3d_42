/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:14:32 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:14:33 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extensions(char *str, char *ext)
{
	char *(err) = NULL;
	if (ft_strncmp(ext, MAP_EXTENSION, ft_strlen(MAP_EXTENSION) + 1) == 0)
		err = ERR_ARG_EXTENSION;
	else if (ft_strncmp(ext, TEXTURE_EXTENSION, ft_strlen(TEXTURE_EXTENSION)
			+ 1) == 0)
		err = ERR_TEX_EXTENSION;
	char *(last_part) = ft_strrchr(str, '/');
	if (ft_strncmp(ft_strrchr(str, '.'), ext, ft_strlen(ext) + 1) != 0)
		return (ft_error(NULL, err, FAILURE));
	if (last_part && ft_strlen(++last_part) < MAP_FILENAME_MIN)
		return (ft_error(str, ERR_CHECK_FILENAME, FAILURE));
	return (SUCCESS);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

void	skip_whitespace(char **line)
{
	while (is_whitespace(**line))
		(*line)++;
}
