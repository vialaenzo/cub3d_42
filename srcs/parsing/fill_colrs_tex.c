/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colrs_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:12:24 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:12:25 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	which_tex(char *line, char **after_direct)
{
	if (ft_strchr_char_ref(line, "NO", after_direct))
		return (NORTH);
	if (ft_strchr_char_ref(line, "SO", after_direct))
		return (SOUTH);
	if (ft_strchr_char_ref(line, "EA", after_direct))
		return (EAST);
	if (ft_strchr_char_ref(line, "WE", after_direct))
		return (WEST);
	if (ft_strchr_char_ref(line, "F", after_direct))
		return (FLOOR);
	ft_strchr_char_ref(line, "C", after_direct);
	return (CEILING);
}

int	fill_textures(char *line, t_data *data)
{
	char *(direction_names)[] = {"NORTH", "SOUTH", "EAST", "WEST"};
	char *(after_direct) = NULL;
	int (i) = which_tex(line, &after_direct);
	char **(texture) = ft_split(after_direct, ' ');
	if (!texture)
		return (ft_error("texture", ERR_MALLOC, FAILURE));
	if (ft_len_split(texture) != 1)
		return (ft_error(NULL, ERR_TEX, FAILURE));
	if ((data->texinfo.dire_tex[i] != NULL) || data->texinfo.nb_tex == NB_TEX)
	{
		ft_free_tab(texture);
		return (ft_error(direction_names[i], ERR_TEX_ALREADY_SET, FAILURE));
	}
	data->texinfo.dire_tex[i] = ft_strdup(texture[0]);
	ft_free_tab(texture);
	if (!data->texinfo.dire_tex[i])
		return (ft_error(after_direct, ERR_MALLOC, FAILURE));
	data->texinfo.nb_tex++;
	return (SUCCESS);
}

static int	ft_valid_values(char **split)
{
	int	j;
	int	value;

	int (i) = -1;
	if (!split)
		return (FAILURE);
	while (split[++i] && i < RGB_VALUES)
	{
		j = 0;
		while (split[i][j] && is_whitespace(split[i][j]))
			j++;
		if (!split[i][j])
			return (FAILURE);
		value = ft_atoi(&split[i][j]);
		if (value < 0 || value > 255)
			return (FAILURE);
		while (split[i][j] && ft_isdigit(split[i][j]))
			j++;
		while (split[i][j] && is_whitespace(split[i][j]))
			j++;
		if (split[i][j] != '\0')
			return (FAILURE);
	}
	return (i == RGB_VALUES);
}

int	fill_colors(char *line, t_data *data)
{
	char *(after_direct) = NULL;
	int (i) = which_tex(line, &after_direct);
	if (data->texinfo.fc_tex[i][0] != -1 ||
			data->texinfo.nb_colors == NB_COLORS)
		return (ft_error(NULL, ERR_TEX_ALREADY_SET, FAILURE));
	skip_whitespace(&after_direct);
	if (ft_count_occ(after_direct, ',') != 2)
		return (ft_error(NULL, ERR_INVALID_COLORS, FAILURE));
	char **(split) = ft_split(after_direct, ',');
	if (!split)
		return (ft_error(NULL, ERR_MALLOC, FAILURE));
	if (!ft_valid_values(split))
		return (ft_free_tab(split), ft_error(NULL, ERR_INVALID_COLORS,
				FAILURE));
	int (j) = -1;
	while (split[++j])
	{
		data->texinfo.fc_tex[i][j] = ft_atoi(split[j]);
		free(split[j]);
	}
	free(split);
	data->texinfo.nb_colors++;
	return (SUCCESS);
}

int	fill_tex_colrs(t_data *data)
{
	char *(line) = NULL;
	int (i) = -1;
	while (++i < (NB_COLORS + NB_TEX) && data->file[i])
	{
		line = data->file[i];
		if (find_tex(line) == 1 && data->texinfo.nb_tex < NB_TEX)
		{
			if (!fill_textures(line, data))
				return (FAILURE);
		}
		else if (find_tex(line) == 2 && data->texinfo.nb_colors < NB_COLORS)
		{
			if (!fill_colors(line, data))
				return (FAILURE);
		}
	}
	if (data->texinfo.nb_tex != NB_TEX || data->texinfo.nb_colors != NB_COLORS)
		return (ft_error(NULL, ERR_MIS_TEX_COLOR, FAILURE));
	return (SUCCESS);
}
