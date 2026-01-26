/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:21 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 18:12:23 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_error(t_game *game, char *msg)
{
	ft_putstr("Error\n");
	ft_putstr(msg);
	full_cleanup(game);
	exit(1);
	return (1);
}

int	exit_success(t_game *game)
{
	full_cleanup(game);
	exit(0);
	return (0);
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		player_movement(game, keycode);
		render_map(game);
	}
	else if (keycode == 65307)
		exit_success(game);
	return (0);
}

void	render_map(t_game *game)
{
	render_walls(game);
	render_ground(game);
	render_player(game);
	render_collectibles(game);
	render_exit(game);
}

int	minilx_init(t_game *game)
{
	game->win_width = map_w(game->map) * 48;
	game->win_height = map_h(game->map) * 48;
	game->minilx = mlx_init();
	game->minilx_win = mlx_new_window(game->minilx, game->win_width,
			game->win_height, "so_long");
	render_map(game);
	mlx_key_hook(game->minilx_win, key_handler, game);
	mlx_hook(game->minilx_win, 17, 0, exit_success, game);
	mlx_loop(game->minilx);
	return (0);
}
