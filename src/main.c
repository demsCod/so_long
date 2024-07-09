/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:14:26 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:41 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_game(t_map *map)
{
	if (init_maps(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
	if (checkmaps_is_rec(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
	if (checkmaps_is_close(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
	if (least_items(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
	if (map_playable(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
	if (check_exit_good(map) == 1)
		free_and_exit(MAP_KO, EXIT_FAILURE, map, false);
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	if (ac == 2)
	{
		if (ft_str_len(av[1], 0) < 5)
			return (ft_putstr_fd("Error\nextension not valid\n", 2), 1);
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) == 0)
		{
			map = malloc(sizeof(t_map));
			if (!map)
				exit(EXIT_FAILURE);
			ft_memset(map, sizeof(t_map), 0);
			free((map->all_map = NULL, map->track_tab = NULL,
					map->track_tab2 = NULL));
			map->mlx = 0;
			map->fd = open(av[1], O_RDONLY);
			if (map->fd < 0)
				return (ft_putstr_fd("Eror\nMap not valid\n", 2), free(map), 1);
			check_game(map);
			init_windows(map);
		}
		else
			return (ft_putstr_fd("Error\nextension not valid\n", 2), 1);
	}
}
