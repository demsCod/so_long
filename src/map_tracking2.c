/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tracking2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:16:58 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:49:25 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extend_player2(char **map, int x, int y)
{
	int	count;

	count = 0;
	if (map[y + 1][x] != WALL && map[y + 1][x] != PLAYER && map[y
		+ 1][x] != MECHANT)
	{
		free((map[y + 1][x] = PLAYER, count++, NULL));
	}
	if (map[y - 1][x] != WALL && map[y - 1][x] != PLAYER && map[y
		- 1][x] != MECHANT)
	{
		free((map[y - 1][x] = PLAYER, count++, NULL));
	}
	if (map[y][x + 1] != WALL && map[y][x + 1] != PLAYER && map[y][x
		+ 1] != MECHANT)
	{
		free((map[y][x + 1] = PLAYER, count++, NULL));
	}
	if (map[y][x - 1] != WALL && map[y][x - 1] != PLAYER && map[y][x
		- 1] != MECHANT)
	{
		free((map[y][x - 1] = PLAYER, count++, NULL));
	}
	return (count);
}

int	check_exit_good(t_map *map)
{
	int	count;
	int	y;
	int	x;

	while (1)
	{
		count = 0;
		y = -1;
		while (map->track_tab2[++y] != NULL)
		{
			x = -1;
			while (map->track_tab2[y][++x] != '\0')
			{
				if (map->track_tab2[y][x] == PLAYER)
					count += extend_player2(map->track_tab2, x, y);
			}
		}
		if (count == 0)
			break ;
	}
	if (there_is_item(map->track_tab2, EXIT) != 0)
		return (EXIT_FAILURE);
	return (0);
}
