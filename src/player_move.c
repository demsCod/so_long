/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:04:25 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/02 23:03:14 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	print_pas(t_map *map)
{
	char	*nb;

	nb = 0;
	nb = ft_itoa(map->numbers_pas);
	ft_putstr_fd("Nombre de pas : ", 1);
	ft_putnbr_fd(map->numbers_pas, 1);
	ft_putchar_fd('\n', 1);
	mlx_string_put(map->mlx, map->mlx_win, 100, 100, 0xFFFFFFFF, nb);
	free(nb);
}

void	p_move_back(t_map *map)
{
	if (map->all_map[map->p_y - 1][map->p_x] == MECHANT)
	{
		put_image(map, map->img_ground, map->p_x, map->p_y);
		boom(map->p_x, map->p_y - 1, map);
		free_and_exit("BOOOOM T'ES MORT", EXIT_SUCCESS, map, false);
	}
	if (map->all_map[map->p_y - 1][map->p_x] != WALL && map->all_map[map->p_y
		- 1][map->p_x] != EXIT)
	{
		if (map->all_map[map->p_y - 1][map->p_x] == COLECT)
			map->collects_numbers--;
		put_image(map, map->img_ground, map->p_x, map->p_y);
		move_back(map);
		map->all_map[map->p_y][map->p_x] = GROUND;
		map->all_map[map->p_y - 1][map->p_x] = PLAYER;
		map->p_y--;
		++map->numbers_pas;
		print_pas(map);
	}
	else if (map->all_map[map->p_y - 1][map->p_x] == EXIT
		&& map->collects_numbers == 0)
	{
		free_and_exit("GG MON PETIT", EXIT_SUCCESS, map, false);
	}
}

void	p_move_front(t_map *map)
{
	if (map->all_map[map->p_y + 1][map->p_x] == MECHANT)
	{
		put_image(map, map->img_ground, map->p_x, map->p_y);
		boom(map->p_x, map->p_y + 1, map);
		free_and_exit("BOOOOM T'ES MORT", EXIT_SUCCESS, map, false);
	}
	if (map->all_map[map->p_y + 1][map->p_x] != WALL && map->all_map[map->p_y
		+ 1][map->p_x] != EXIT)
	{
		if (map->all_map[map->p_y + 1][map->p_x] == COLECT)
			map->collects_numbers--;
		put_image(map, map->img_ground, map->p_x, map->p_y);
		move_front(map);
		map->all_map[map->p_y][map->p_x] = GROUND;
		map->all_map[map->p_y + 1][map->p_x] = PLAYER;
		map->p_y++;
		++map->numbers_pas;
		print_pas(map);
	}
	else if (map->all_map[map->p_y + 1][map->p_x] == EXIT
		&& map->collects_numbers == 0)
	{
		free_and_exit("GG MON PETIT", EXIT_SUCCESS, map, false);
	}
}

void	p_move_left(t_map *map)
{
	if (map->all_map[map->p_y][map->p_x - 1] == MECHANT)
	{
		put_image(map, map->img_ground, map->p_x, map->p_y);
		boom(map->p_x - 1, map->p_y, map);
		free_and_exit("BOOOOM T'ES MORT", EXIT_SUCCESS, map, false);
	}
	if (map->all_map[map->p_y][map->p_x - 1] != WALL
		&& map->all_map[map->p_y][map->p_x - 1] != EXIT)
	{
		if (map->all_map[map->p_y][map->p_x - 1] == COLECT)
			map->collects_numbers--;
		put_image(map, map->img_ground, map->p_x, map->p_y);
		move_left(map);
		map->all_map[map->p_y][map->p_x] = GROUND;
		map->all_map[map->p_y][map->p_x - 1] = PLAYER;
		map->p_x--;
		++map->numbers_pas;
		print_pas(map);
	}
	else if (map->all_map[map->p_y][map->p_x - 1] == EXIT
		&& map->collects_numbers == 0)
	{
		free_and_exit("GG MON PETIT", EXIT_SUCCESS, map, false);
	}
}

void	p_move_right(t_map *map)
{
	if (map->all_map[map->p_y][map->p_x + 1] == MECHANT)
	{
		put_image(map, map->img_ground, map->p_x, map->p_y);
		boom(map->p_x + 1, map->p_y, map);
		free_and_exit("BOOOOM T'ES MORT", EXIT_SUCCESS, map, false);
	}
	if (map->all_map[map->p_y][map->p_x + 1] != WALL
		&& map->all_map[map->p_y][map->p_x + 1] != EXIT)
	{
		if (map->all_map[map->p_y][map->p_x + 1] == COLECT)
			map->collects_numbers--;
		put_image(map, map->img_ground, map->p_x, map->p_y);
		move_right(map);
		map->all_map[map->p_y][map->p_x] = GROUND;
		map->all_map[map->p_y][map->p_x + 1] = PLAYER;
		map->p_x++;
		++map->numbers_pas;
		print_pas(map);
	}
	else if (map->all_map[map->p_y][map->p_x + 1] == EXIT
		&& map->collects_numbers == 0)
	{
		free_and_exit("GG MON PETIT", EXIT_SUCCESS, map, false);
	}
}
