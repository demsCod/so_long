/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:42:14 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 18:41:47 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_item(char pos, char item)
{
	if (pos == item)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	is_line_items(char *str, char item)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_item(str[i], item) == 1)
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	there_is_item(char **map, char item)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_item(map[y][x], item) != 1)
				++i;
			++x;
		}
		++y;
	}
	return (i);
}
