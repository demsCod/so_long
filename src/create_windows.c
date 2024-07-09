/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:13:23 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 23:25:47 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_exit(t_map *map)
{
	find_exit(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_exit[1], map->e_x
		* PIXELSIZE, map->e_y * PIXELSIZE);
}

int	keyfonction(int keycode, t_map *map)
{
	if (keycode == XK_Escape)
	{
		free_and_exit("You didn't finish the game !\n", EXIT_SUCCESS, map,
			false);
	}
	if (keycode == XK_w || keycode == XK_Up)
		p_move_back(map);
	if (keycode == XK_s || keycode == XK_Down)
		p_move_front(map);
	if (keycode == XK_a || keycode == XK_Left)
		p_move_left(map);
	if (keycode == XK_d || keycode == XK_Right)
		p_move_right(map);
	if (map->collects_numbers == 0)
		change_exit(map);
	return (0);
}

int	quit(t_map *map)
{
	free_and_exit("You didn't finish the game !\n", EXIT_SUCCESS, map, false);
	return (0);
}

void	init_windows(t_map *map)
{
	size_t	x;
	size_t	y;

	free((y = 0, x = 0, map->numbers_pas = 0, map->pos_left = 0, NULL));
	free((map->pos_back = 0, map->pos_front = 0, map->pos_right = 0, NULL));
	free((map->x = 0, NULL));
	map->mlx = mlx_init(map->mlx_win);
	if (map->mlx == NULL)
		(free_and_exit(WINDOWSFAIL, EXIT_FAILURE, map, false));
	map->beforewindows = true;
	map->mlx_win = mlx_new_window(map->mlx, (map->lenght_up + 1) * PIXELSIZE,
			(map->lenght_right + 1) * PIXELSIZE, "so_long");
	if (map->mlx_win == NULL)
		free_and_exit(MALLOC_FAIL, EXIT_FAILURE, map, true);
	memset_player_sprites(map);
	draw_enemies(map);
	drawindos(map, x, y);
	mlx_hook(map->mlx_win, 17, (0L), *quit, map);
	find_player(map);
	mlx_hook(map->mlx_win, 02, (1L << 0), *keyfonction, map);
	mlx_loop(map->mlx);
}
