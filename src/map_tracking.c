/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:42:39 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 18:41:39 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_map *map)
{
	map->p_y = 0;
	while (map->all_map[map->p_y])
	{
		map->p_x = 0;
		while (map->all_map[map->p_y][map->p_x])
		{
			if (check_item(map->all_map[map->p_y][map->p_x],
				'P') == EXIT_SUCCESS)
				return ;
			++map->p_x;
		}
		++map->p_y;
	}
	return ;
}

void	find_exit(t_map *map)
{
	map->e_y = 0;
	while (map->all_map[map->e_y])
	{
		map->e_x = 0;
		while (map->all_map[map->e_y][map->e_x])
		{
			if (check_item(map->all_map[map->e_y][map->e_x],
				EXIT) == EXIT_SUCCESS)
				return ;
			++map->e_x;
		}
		++map->e_y;
	}
	return ;
}

int	extend_player(char **map, int x, int y)
{
	int	count;

	count = 0;
	if (map[y + 1][x] != WALL && map[y + 1][x] != PLAYER && map[y
		+ 1][x] != EXIT && map[y + 1][x] != MECHANT)
	{
		free((map[y + 1][x] = PLAYER, count++, NULL));
	}
	if (map[y - 1][x] != WALL && map[y - 1][x] != PLAYER && map[y
		- 1][x] != EXIT && map[y - 1][x] != MECHANT)
	{
		free((map[y - 1][x] = PLAYER, count++, NULL));
	}
	if (map[y][x + 1] != WALL && map[y][x + 1] != PLAYER && map[y][x
		+ 1] != EXIT && map[y][x + 1] != MECHANT)
	{
		free((map[y][x + 1] = PLAYER, count++, NULL));
	}
	if (map[y][x - 1] != WALL && map[y][x - 1] != PLAYER && map[y][x
		- 1] != EXIT && map[y][x - 1] != MECHANT)
	{
		free((map[y][x - 1] = PLAYER, count++, NULL));
	}
	return (count);
}

int	is_ok(char **map)
{
	if (there_is_item(map, COLECT) != 0)
		return (EXIT_FAILURE);
	if (there_is_item(map, EXIT) != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	map_playable(t_map *map)
{
	int	x;
	int	y;
	int	count;

	if (check_weird_items(map->track_tab) == 1)
		return (EXIT_FAILURE);
	while (1)
	{
		count = 0;
		y = -1;
		while (map->track_tab[++y] != NULL)
		{
			x = -1;
			while (map->track_tab[y][++x] != '\0')
			{
				if (map->track_tab[y][x] == PLAYER)
					count += extend_player(map->track_tab, x, y);
			}
		}
		if (count == 0)
			break ;
	}
	if (is_ok(map->track_tab) == EXIT_FAILURE)
		return (1);
	return (0);
}
