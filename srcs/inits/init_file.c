/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:28 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:29 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*init_file_extra(char *file_ac, char *line, char *temp)
{
	if (!file_ac)
		file_ac = ft_strdup(line);
	else
	{
		temp = ft_strjoin(file_ac, line);
		free(file_ac);
		file_ac = temp;
	}
	free(line);
	return (file_ac);
}

size_t	ft_len_split(char **split)
{
	if (!split || !split[0])
		return (FAILURE);
	int (i) = 0;
	while (split[i])
		i++;
	return (i);
}

int	init_file(t_data *data)
{
	char *(file_ac) = NULL;
	char *(temp) = NULL;
	int (fd) = open(data->path_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(data->path_file, ERR_OPEN_FILE, FAILURE));
	char *(line) = get_next_line(fd);
	while (line != NULL)
	{
		file_ac = init_file_extra(file_ac, line, temp);
		if (file_ac == NULL)
			return (ft_error(data->path_file, ERR_MALLOC, FAILURE));
		line = get_next_line(fd);
	}
	data->file_str = file_ac;
	data->file = ft_split(file_ac, '\n');
	data->count_line = ft_len_split(data->file);
	close(fd);
	if (ft_len_split(data->file) < 9)
	{
		free(data->file_str);
		ft_free_tab(data->file);
		return (ft_error(data->path_file, ERR_FILE_TOO_SHORT, FAILURE));
	}
	return (SUCCESS);
}
