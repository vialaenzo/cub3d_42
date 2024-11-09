/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:05:14 by eviala            #+#    #+#             */
/*   Updated: 2024/11/04 12:05:15 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(char *detail, char *str, int code)
{
	ft_printf(2, BRIGHT_RED "Error : " RESET);
	if (detail)
	{
		ft_printf(2, detail);
		ft_printf(2, " : ");
	}
	if (str)
		ft_printf(2, str);
	ft_printf(2, "\n");
	return (code);
}
