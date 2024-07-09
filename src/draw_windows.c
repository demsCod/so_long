/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:19:30 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 20:01:57 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_files_image(t_map *map, void *img, char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	img = mlx_xpm_file_to_image(map->mlx, path, &i, &j);
	if (img == NULL)
		free_and_exit(MALLOC_FAIL, EXIT_FAILURE, map, true);
	else if (i != PIXELSIZE || j != PIXELSIZE)
		free_and_exit("Files size is not good !", EXIT_FAILURE, map, false);
	return (img);
}

void	drawall(t_map *map, size_t x, size_t y)
{
	if (y == 0 && x != 0 && x != map->lenght_up)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall, x
			* PIXELSIZE, y * PIXELSIZE);
	}
	else if (y == 0 && x == 0)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_grey, x
			* PIXELSIZE, y * PIXELSIZE);
	}
	else if (y > 0 && x == 0 && y != map->lenght_right)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall_left, x
			* PIXELSIZE, y * PIXELSIZE);
	else if (x == map->lenght_up && y != 0 && y != map->lenght_right)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall_right, x
			* PIXELSIZE, y * PIXELSIZE);
	else if (y == map->lenght_right && x != 0 && x != map->lenght_up)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall_bas, x
			* PIXELSIZE, y * PIXELSIZE);
	else if (x != 0 && x != map->lenght_up && y != 0 && y != map->lenght_right)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_wall_mid, x
			* PIXELSIZE, y * PIXELSIZE);
	else
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_grey, x
			* PIXELSIZE, y * PIXELSIZE);
}

void	drawindos(t_map *map, size_t x, size_t y)
{
	while (map->all_map[y])
	{
		x = 0;
		while (map->all_map[y][x])
		{
			if (map->all_map[y][x] == WALL)
				drawall(map, x, y);
			if (map->all_map[y][x] == COLECT)
				put_image(map, map->img_collectible, x, y);
			if (map->all_map[y][x] == '0')
				put_image(map, map->img_ground, x, y);
			if (map->all_map[y][x] == PLAYER)
				put_image(map, map->img_player_static_front[0], x, y);
			if (map->all_map[y][x] == EXIT)
				put_image(map, map->img_exit[0], x, y);
			if (map->all_map[y][x] == MECHANT)
				put_image(map, map->img_mechant, x, y);
			x++;
		}
		y++;
	}
}

void	draw_enemies(t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map->all_map[y])
	{
		x = 0;
		while (map->all_map[y][x])
		{
			if (map->all_map[y][x] == MECHANT)
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->img_collectible, x * PIXELSIZE, y * PIXELSIZE);
			x++;
		}
		y++;
	}
}
