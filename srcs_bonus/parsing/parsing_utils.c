/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:00:57 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:00:58 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_char(char *str, char old_char, char new_char)
{
	size_t (len) = strlen(str);
	if (len > 0 && str[len - 1] == old_char)
		str[len - 1] = new_char;
}

int	find_tex(char *line)
{
	if (ft_strchr_char(line, "NO ") || ft_strchr_char(line, "SO ")
		|| ft_strchr_char(line, "EA ") || ft_strchr_char(line, "WE "))
		return (SUCCESS);
	if (ft_strchr_char(line, "F ") || ft_strchr_char(line, "C "))
		return (SUCCESS + 1);
	return (FAILURE);
}
