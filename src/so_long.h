/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:30:05 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <errno.h>
# include <stdbool.h>

# define KEYPRESS 2
# define KEYRELEASE 3

# define GROUNDPATH "solongpath/decor/decor_ground.xpm"
# define WALL1PATH "solongpath/decor/wall_1.xpm"
# define WALLLEFTPATH "solongpath/decor/wallleft.xpm"
# define WALLRIGHTPATH "solongpath/decor/wallright.xpm"
# define WALLBASPATH "solongpath/decor/wallbas.xpm"
# define WALLMIDPATH "solongpath/decor/wallmid2.xpm"
# define EXIT1PATH "solongpath/decor/exit1.xpm"
# define EXIT2PATH "solongpath/decor/exit2.xpm"
# define COLLECTPATH "solongpath/decor/collectible.xpm"
# define GREY "solongpath/decor/grey.xpm"

# define MECHANTPATH "solongpath/decor/mechants.xpm"
# define EX1 "solongpath/explosion/explo1.xpm"
# define EX2 "solongpath/explosion/explo2.xpm"
# define EX3 "solongpath/explosion/explo3.xpm"
# define EX4 "solongpath/explosion/explo4.xpm"
# define EX5 "solongpath/explosion/explo5.xpm"
# define EX6 "solongpath/explosion/explo6.xpm"
# define EX7 "solongpath/explosion/explo7.xpm"
# define BLOODPATH "solongpath/explosion/blood.xpm"

# define PSTAF1 "solongpath/static_animation/animfront/aafront-1.xpm"
# define PSTAF2 "solongpath/static_animation/animfront/aafront-2.xpm"

# define PSTAB1 "solongpath/static_animation/animback/aaback-1.xpm"
# define PSTAB2 "solongpath/static_animation/animback/aback-2.xpm"

# define PSTAL1 "solongpath/static_animation/animside_left/aaleft-1.xpm"
# define PSTAL2 "solongpath/static_animation/animside_left/aaleft-2.xpm"

# define PSTAR1 "solongpath/static_animation/animside_right/aaright-1.xpm"
# define PSTAR2 "solongpath/static_animation/animside_right/aaright-2.xpm"

# define PWALKB1 "solongpath/move/walkback/mmvb1.xpm"
# define PWALKB2 "solongpath/move/walkback/mmvb2.xpm"

# define PWALKF1 "solongpath/move/walkfront/wf1.xpm"
# define PWALKF2 "solongpath/move/walkfront/wf2.xpm"

# define PWALKR1 "solongpath/move/walkright/wr1.xpm"
# define PWALKR2 "solongpath/move/walkright/wr2.xpm"

# define PWALKL1 "solongpath/move/walkleft/wl1.xpm"
# define PWALKL2 "solongpath/move/walkleft/wl2.xpm"

# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'
# define COLECT 'C'
# define EXIT 'E'
# define MECHANT 'M'

# define MALLOC_FAIL "Error\nMalloc failed"
# define OPEN_FAIL "Error\nOpen failed"
# define MAP_KO "Error\nThe map is not correct"
# define WINDOWSFAIL "Error\nWindows initiation failed"

# define PIXELSIZE 124

typedef struct s_map
{
	int		fd;
	char	*stock_data;
	char	*temp_stock;
	char	**track_tab;
	char	**track_tab2;
	char	**all_map;
	int		x;
	int		y;
	int		choicemove;
	bool	can_move;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		pos_back;
	int		pos_front;
	int		pos_right;
	int		pos_left;
	int		collects_numbers;
	int		players_numbers;
	int		exit_numbers;
	bool	beforewindows;
	size_t	lenght_up;
	size_t	lenght_right;
	void	*img_player_static_front[2];
	void	*img_player_static_back[2];
	void	*img_player_static_left[2];
	void	*img_player_static_right[2];
	void	*img_player_move_front[2];
	void	*img_player_move_back[2];
	void	*img_player_move_left[2];
	void	*img_player_move_right[2];
	void	*img_wall;
	void	*img_wall_left;
	void	*img_wall_right;
	void	*img_grey;
	void	*img_collectible;
	void	*img_mechant;
	void	*img_wall_bas;
	void	*img_wall_mid;
	void	*img_ground;
	void	*img_exit[2];
	void	*img_explosion[7];
	void	*img_blood;
	int		numbers_pas;
	int		bonus;
	void	*mlx;
	void	*mlx_win;
}			t_map;

void		put_image(t_map *map, void *image, int x, int y);
void		find_player(t_map *map);
int			extend_player(char **map, int x, int y);
int			map_playable(t_map *map);
void		free_and_exit(const char *err, int code, t_map *map, bool status);
int			least_items(t_map *map);
int			there_is_item(char **map, char item);
int			check_item(char pos, char item);
void		ft_destroy_image(void *img, t_map *map);
int			is_line_items(char *str, char item);
int			checkmaps_is_close(t_map *map);
int			checkmaps_is_rec(t_map *map);
int			init_maps(t_map *map);
void		init_windows(t_map *map);
void		p_move_back(t_map *map);
void		p_move_front(t_map *map);
void		p_move_left(t_map *map);
void		p_move_right(t_map *map);
void		move_back(t_map *map);
int			check_weird_items(char **map);
void		move_front(t_map *map);
void		move_left(t_map *map);
void		move_right(t_map *map);
int			checkmaps_is_close(t_map *map);
int			checkmaps_is_rec(t_map *map);
int			least_items(t_map *map);
void		init_sprites_decors(t_map *map);
void		find_exit(t_map *map);
void		init_sprites_players(t_map *map);
void		init_sprites_decors(t_map *map);
void		memset_player_sprites(t_map *map);
void		memset_decor_sprites(t_map *map);
void		drawindos(t_map *map, size_t x, size_t y);
int			check_exit_good(t_map *map);
void		draw_enemies(t_map *map);
void		*ft_files_image(t_map *map, void *img, char *path);
void		boom(int x, int y, t_map *map);
#endif
