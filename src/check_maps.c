/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:42:01 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:33:54 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmaps_is_close(t_map *map)
{
	map->y = 0;
	if (is_line_items(map->all_map[map->y], WALL) == 1
		|| is_line_items(map->all_map[map->lenght_right], WALL))
		return (EXIT_FAILURE);
	while (map->all_map[map->y])
	{
		if (check_item(map->all_map[map->y][0], WALL) == 1
			|| check_item(map->all_map[map->y][map->lenght_up], WALL) == 1)
			return (EXIT_FAILURE);
		++map->y;
	}
	return (EXIT_SUCCESS);
}

int	checkmaps_is_rec(t_map *map)
{
	map->y = 0;
	map->lenght_up = ft_strlen(map->all_map[0]) - 1;
	map->lenght_right = ft_strlen_tab(map->all_map) - 1;
	while (map->all_map[map->y])
	{
		if (map->lenght_up != ft_strlen(map->all_map[map->y]) - 1)
			return (EXIT_FAILURE);
		++map->y;
	}
	return (EXIT_SUCCESS);
}

int	init_maps(t_map *map)
{
	map->stock_data = ft_strdup("");
	if (!map->stock_data)
		free_and_exit(MALLOC_FAIL, EXIT_FAILURE, map, true);
	while (1)
	{
		map->temp_stock = get_next_line(map->fd);
		if (map->temp_stock == NULL)
			break ;
		map->stock_data = ft_re_strjoin(map->stock_data, map->temp_stock);
		if (!map->stock_data)
			free_and_exit(MALLOC_FAIL, EXIT_FAILURE, map, true);
		ft_free((void **)&map->temp_stock);
	}
	if (*map->stock_data == '\0')
		return (EXIT_FAILURE);
	map->all_map = ft_split(map->stock_data, '\n');
	map->track_tab = ft_split(map->stock_data, '\n');
	map->track_tab2 = ft_split(map->stock_data, '\n');
	if (!map->all_map || !map->track_tab || !map->track_tab2)
		free_and_exit(MALLOC_FAIL, EXIT_FAILURE, map, true);
	return (EXIT_SUCCESS);
}

int	least_items(t_map *map)
{
	map->players_numbers = there_is_item(map->all_map, PLAYER);
	if (map->players_numbers != 1)
		return (EXIT_FAILURE);
	map->collects_numbers = there_is_item(map->all_map, 'C');
	if (map->collects_numbers < 1)
		return (EXIT_FAILURE);
	map->exit_numbers = there_is_item(map->all_map, 'E');
	if (map->exit_numbers != 1)
		return (EXIT_FAILURE);
	if (there_is_item(map->all_map, MECHANT) > 0)
		map->bonus = 1;
	else
		map->bonus = 0;
	return (EXIT_SUCCESS);
}

int	check_weird_items(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != WALL && map[j][i] != GROUND
				&& map[j][i] != PLAYER && map[j][i] != EXIT
				&& map[j][i] != COLECT && map[j][i] != MECHANT)
			{
				return (EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
	return (0);
}
