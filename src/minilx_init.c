/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:21 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/25 19:39:02 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_win(void *minilx, void *minilx_win)
{
	mlx_destroy_window(minilx, minilx_win);
}

int	key_handler(int keycode, void *param)
{
	return (0);
}

void	render_map(struct window *win, char **map)
{
	render_walls(win, map);
	render_ground(win, map);
	render_player(win, map);
	render_collectibles(win, map);
	render_exit(win, map);
}

int	minilx_init(char **map)
{
	t_game	game;

	game.win_width = map_w(map) * 48;
	game.win_height = map_h(map) * 48;
	game.minilx = mlx_init();
	game.minilx_win = mlx_new_window(game.minilx, game.win_width, 
		game.win_height, "so_long");
	render_map(&game, map);
	mlx_key_hook(game.minilx_win, key_handler, &game);
	mlx_hook(game.minilx_win, 17, 0, close_win, &game);
	mlx_loop(game.minilx);
	return (0);
}
