/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:01:44 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/07 20:13:29 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(void *img, t_map *map)
{
	if (map && img != NULL)
		mlx_destroy_image(map->mlx, img);
}

void	memset_decor_sprites(t_map *map)
{
	map->img_ground = 0;
	map->img_wall = 0;
	map->img_wall_left = 0;
	map->img_wall_right = 0;
	map->img_grey = 0;
	map->img_wall_bas = 0;
	map->img_wall_mid = 0;
	map->img_collectible = 0;
	map->img_exit[0] = 0;
	map->img_exit[1] = 0;
	map->img_explosion[0] = 0;
	map->img_explosion[1] = 0;
	map->img_explosion[2] = 0;
	map->img_explosion[3] = 0;
	map->img_explosion[4] = 0;
	map->img_explosion[5] = 0;
	map->img_explosion[6] = 0;
	map->img_blood = 0;
}

void	memset_player_sprites(t_map *map)
{
	map->img_player_static_back[0] = 0;
	map->img_player_static_front[0] = 0;
	map->img_player_static_back[1] = 0;
	map->img_player_static_front[1] = 0;
	map->img_player_move_front[0] = 0;
	map->img_player_move_front[1] = 0;
	map->img_player_static_left[0] = 0;
	map->img_player_static_left[1] = 0;
	map->img_player_move_left[0] = 0;
	map->img_player_move_left[1] = 0;
	map->img_player_static_right[0] = 0;
	map->img_player_static_right[1] = 0;
	map->img_player_move_right[0] = 0;
	map->img_player_move_right[1] = 0;
	map->img_player_move_back[0] = 0;
	map->img_player_move_back[1] = 0;
	map->img_mechant = 0;
	memset_decor_sprites(map);
	init_sprites_decors(map);
	init_sprites_players(map);
}

void	init_sprites_decors(t_map *map)
{
	map->img_ground = ft_files_image(map, map->img_ground, GROUNDPATH);
	map->img_wall = ft_files_image(map, map->img_wall, WALL1PATH);
	map->img_wall_left = ft_files_image(map, map->img_wall_left, WALLLEFTPATH);
	map->img_wall_right = ft_files_image(map, map->img_wall_right,
			WALLRIGHTPATH);
	map->img_grey = ft_files_image(map, map->img_grey, GREY);
	map->img_wall_bas = ft_files_image(map, map->img_wall_bas, WALLBASPATH);
	map->img_wall_mid = ft_files_image(map, map->img_wall_mid, WALLMIDPATH);
	map->img_collectible = ft_files_image(map, map->img_collectible,
			COLLECTPATH);
	map->img_exit[0] = ft_files_image(map, map->img_exit[0], EXIT1PATH);
	map->img_exit[1] = ft_files_image(map, map->img_exit[1], EXIT2PATH);
	map->img_mechant = ft_files_image(map, map->img_mechant, MECHANTPATH);
	map->img_explosion[0] = ft_files_image(map, map->img_explosion[0], EX1);
	map->img_explosion[1] = ft_files_image(map, map->img_explosion[1], EX2);
	map->img_explosion[2] = ft_files_image(map, map->img_explosion[2], EX3);
	map->img_explosion[3] = ft_files_image(map, map->img_explosion[3], EX4);
	map->img_explosion[4] = ft_files_image(map, map->img_explosion[4], EX5);
	map->img_explosion[5] = ft_files_image(map, map->img_explosion[5], EX6);
	map->img_explosion[6] = ft_files_image(map, map->img_explosion[6], EX7);
	map->img_blood = ft_files_image(map, map->img_blood, BLOODPATH);
}

void	init_sprites_players(t_map *map)
{
	map->img_player_static_back[0] = ft_files_image(map,
			map->img_player_static_back[0], PSTAB1);
	map->img_player_static_front[0] = ft_files_image(map,
			map->img_player_static_front[0], PSTAF1);
	map->img_player_move_front[0] = ft_files_image(map,
			map->img_player_move_front[0], PWALKF1);
	map->img_player_move_front[1] = ft_files_image(map,
			map->img_player_move_front[1], PWALKF2);
	map->img_player_static_left[0] = ft_files_image(map,
			map->img_player_static_left[0], PSTAL1);
	map->img_player_move_left[0] = ft_files_image(map,
			map->img_player_move_left[0], PWALKL1);
	map->img_player_move_left[1] = ft_files_image(map,
			map->img_player_move_left[1], PWALKL2);
	map->img_player_static_right[0] = ft_files_image(map,
			map->img_player_static_right[0], PSTAR1);
	map->img_player_move_right[0] = ft_files_image(map,
			map->img_player_move_right[0], PWALKR1);
	map->img_player_move_right[1] = ft_files_image(map,
			map->img_player_move_right[1], PWALKR2);
	map->img_player_move_back[0] = ft_files_image(map,
			map->img_player_move_back[0], PWALKB1);
	map->img_player_move_back[1] = ft_files_image(map,
			map->img_player_move_back[1], PWALKB2);
}
