/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:55:54 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:18:02 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_output
{
	FAILURE = 0,
	SUCCESS = 1,
};

# define ERR_ARG_COUNT "Invalid number of argument."
# define ERR_ARG_EXTENSION "Invalid map extension"
# define ERR_CHECK_FILENAME "Invalid File Name"
# define ERR_CHECK_MAP "Invalid Map"
# define ERR_FILE_TOO_SHORT "File too short"
# define ERR_FLOODFILL "Map not close"
# define ERR_FLOODFILL_BORDER "Border invalid"
# define ERR_INVALID_CHAR "Invalid Character in Map"
# define ERR_INVALID_COLORS "Invalid Values Colors (F|C)"
# define ERR_JUMP_MAP "Jump in Map"
# define ERR_MALLOC "Memory allocation failed."
# define ERR_MIS_TEX_COLOR "Missing Textures or Colors"
# define ERR_OPEN_FILE "Failed Open File"
# define ERR_PARSING_FILE "Invalid Nb Colors | Textures Map"
# define ERR_PLAYER_DIRECTION "Unable to set player orientation"
# define ERR_PLAYER_LOCATION "Unable to set player location"
# define ERR_PLAYER_MULT "More than 1 player"
# define ERR_PLAYER_NF "Player not found"
# define ERR_TEX "Invalid texture"
# define ERR_TEX_ALREADY_SET "Texture already set"
# define ERR_TEX_EXTENSION "Invalid texture extension"
# define ERR_TEX_NF "Texture not found"
# define ERR_MLX_IMG "Failed to create mlx image"
# define ERR_RENDER "Failed to render minimap"
#endif
