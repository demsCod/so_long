/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:43:03 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:53:35 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	boom(int x, int y, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 5)
	{
		j = 0;
		while (j <= 2000)
		{
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->img_explosion[i], x * PIXELSIZE, y * PIXELSIZE);
			j++;
		}
		i++;
	}
	while (j <= 15000)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img_blood, x
			* PIXELSIZE, y * PIXELSIZE);
		j++;
	}
}

void	print_err_and_exit(const char *err, int code, bool status)
{
	if (status == true)
	{
		perror((char *)err);
		exit(code);
	}
	if (err != NULL)
		ft_putendl_fd((char *)err, STDERR_FILENO);
	exit(code);
}

void	destroy_all_image2(t_map *map)
{
	ft_destroy_image(map->img_player_static_left[0], map);
	ft_destroy_image(map->img_player_static_left[1], map);
	ft_destroy_image(map->img_player_static_front[0], map);
	ft_destroy_image(map->img_player_static_front[1], map);
	ft_destroy_image(map->img_player_static_back[0], map);
	ft_destroy_image(map->img_player_static_back[1], map);
	ft_destroy_image(map->img_mechant, map);
	ft_destroy_image(map->img_explosion[0], map);
	ft_destroy_image(map->img_explosion[1], map);
	ft_destroy_image(map->img_explosion[2], map);
	ft_destroy_image(map->img_explosion[3], map);
	ft_destroy_image(map->img_explosion[4], map);
	ft_destroy_image(map->img_explosion[5], map);
	ft_destroy_image(map->img_explosion[6], map);
	ft_destroy_image(map->img_blood, map);
}

void	destroy_all_image(t_map *map)
{
	ft_destroy_image(map->img_collectible, map);
	ft_destroy_image(map->img_exit[0], map);
	ft_destroy_image(map->img_exit[1], map);
	ft_destroy_image(map->img_grey, map);
	ft_destroy_image(map->img_ground, map);
	ft_destroy_image(map->img_wall, map);
	ft_destroy_image(map->img_wall_bas, map);
	ft_destroy_image(map->img_wall_left, map);
	ft_destroy_image(map->img_wall_right, map);
	ft_destroy_image(map->img_wall_mid, map);
	ft_destroy_image(map->img_player_move_back[0], map);
	ft_destroy_image(map->img_player_move_back[1], map);
	ft_destroy_image(map->img_player_move_front[0], map);
	ft_destroy_image(map->img_player_move_front[1], map);
	ft_destroy_image(map->img_player_move_left[0], map);
	ft_destroy_image(map->img_player_move_left[1], map);
	ft_destroy_image(map->img_player_move_right[0], map);
	ft_destroy_image(map->img_player_move_right[1], map);
	ft_destroy_image(map->img_player_static_right[0], map);
	ft_destroy_image(map->img_player_static_right[1], map);
	destroy_all_image2(map);
}

void	free_and_exit(const char *err, int code, t_map *map, bool status)
{
	if (map != NULL && map->mlx != NULL)
	{
		destroy_all_image(map);
		mlx_destroy_window(map->mlx, map->mlx_win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	ft_free((void **)&map->stock_data);
	ft_free((void **)&map->temp_stock);
	ft_free_2d((void ***)&map->track_tab);
	ft_free_2d((void ***)&map->track_tab2);
	ft_free_2d((void ***)&map->all_map);
	ft_close(&map->fd);
	ft_free((void **)&map);
	print_err_and_exit(err, code, status);
}
