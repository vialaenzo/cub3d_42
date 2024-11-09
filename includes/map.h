/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:55:58 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 11:55:59 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_EXTENSION ".cub"
# define MAP_FILENAME_MIN 5
# define TEXTURE_EXTENSION ".xpm"

# define MAP_FLOOR '0'
# define MAP_WALL  '1'
# define MAP_VOID  '\x20'
# define MAP_SPACE 'V'

# define MAP_DOOR_CLOSED 'D'
# define MAP_DOOR_OPEN   'd'

# define MAP_PLAYER_CHARS "NSEW"
# define MAP_PLAYER_NORTH 'N'
# define MAP_PLAYER_SOUTH 'S'
# define MAP_PLAYER_RIGHT 'E'
# define MAP_PLAYER_LEFT  'W'

# define VALID_CHARACTERS "01NSWE "
# define VALID_CHARACTERS_BONUS "01NSWEdD "

# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040
# define MMAP_DEBUG_MSG 0

#endif
