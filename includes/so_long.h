/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:17:32 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/25 19:49:07 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilx/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_dir;

typedef struct s_game
{
	void	*minilx;
	void	*minilx_win;
	int 	win_width;;
	int		win_height;
	char	**map;
	int		px;
	int		py;
	int		moves;
	
	t_dir	p_dir;
	void	*wall_img;
	void	*ground_img;
	void	*p_up_img;
	void	*p_down_img;
	void	*p_left_img;
	void	*p_right_img;
	void	*collectible_img;
	void	*exit_img;
}	t_game;

char	**map_open(char *map_path);
int		map_h(char **map);
int		map_w(char **map);
int		count_lines(char *map_path);
int		same_len(char **map);
int		closed_map(char **map);
int		pec01(char **map);
int		rep_path(char *u, char *d, char *l, char *r);
int		check_exit(char **map);
int		check_path(char **map);
int		ce_reachable(char **map);
int		map_not_valid(char **map);
int		minilx_init(char **map);
int		close_win(void *minilx, void *minilx_win);
void	render_map(t_game *game, char **map);
void	render_walls(t_game *game, char **map);
void	render_ground(t_game *game, char **map);
void	render_player(t_game *game, char **map);
void	render_collectibles(t_game *game, char **map);
void	render_exit(t_game *game, char **map);

#endif