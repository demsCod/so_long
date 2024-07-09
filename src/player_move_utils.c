/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:07:00 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/02 17:06:27 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map *map, void *image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, image, x * PIXELSIZE, y
		* PIXELSIZE);
}

void	move_back(t_map *map)
{
	if (map->pos_back == 0)
	{
		put_image(map, map->img_player_move_back[0], map->p_x, map->p_y - 1);
		++map->pos_back;
	}
	else if (map->pos_back == 1)
	{
		put_image(map, map->img_player_static_back[0], map->p_x, map->p_y - 1);
		++map->pos_back;
	}
	else if (map->pos_back == 2)
	{
		put_image(map, map->img_player_move_back[1], map->p_x, map->p_y - 1);
		++map->pos_back;
	}
	else if (map->pos_back == 3)
	{
		put_image(map, map->img_player_move_back[0], map->p_x, map->p_y - 1);
		map->pos_back = 0;
	}
}

void	move_front(t_map *map)
{
	if (map->pos_front == 0)
	{
		put_image(map, map->img_player_move_front[0], map->p_x, map->p_y + 1);
		++map->pos_front;
	}
	else if (map->pos_front == 1)
	{
		put_image(map, map->img_player_static_front[0], map->p_x, map->p_y + 1);
		++map->pos_front;
	}
	else if (map->pos_front == 2)
	{
		put_image(map, map->img_player_move_front[1], map->p_x, map->p_y + 1);
		++map->pos_front;
	}
	else if (map->pos_front == 3)
	{
		put_image(map, map->img_player_move_front[0], map->p_x, map->p_y + 1);
		map->pos_front = 0;
	}
}

void	move_right(t_map *map)
{
	if (map->pos_right == 0)
	{
		put_image(map, map->img_player_move_right[0], map->p_x + 1, map->p_y);
		++map->pos_right;
	}
	else if (map->pos_right == 1)
	{
		put_image(map, map->img_player_static_right[0], map->p_x + 1, map->p_y);
		++map->pos_right;
	}
	else if (map->pos_right == 2)
	{
		put_image(map, map->img_player_move_right[1], map->p_x + 1, map->p_y);
		++map->pos_right;
	}
	else if (map->pos_right == 3)
	{
		put_image(map, map->img_player_move_right[0], map->p_x + 1, map->p_y);
		map->pos_right = 0;
	}
}

void	move_left(t_map *map)
{
	if (map->pos_left == 0)
	{
		put_image(map, map->img_player_move_left[0], map->p_x - 1, map->p_y);
		++map->pos_left;
	}
	else if (map->pos_left == 1)
	{
		put_image(map, map->img_player_static_left[0], map->p_x - 1, map->p_y);
		++map->pos_left;
	}
	else if (map->pos_left == 2)
	{
		put_image(map, map->img_player_move_left[1], map->p_x - 1, map->p_y);
		++map->pos_left;
	}
	else if (map->pos_left == 3)
	{
		put_image(map, map->img_player_move_left[0], map->p_x - 1, map->p_y);
		map->pos_left = 0;
	}
}
