/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:31:18 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/28 15:03:41 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_up(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->p_dir = UP;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && !cant_move_to(game->map, i - 1, j))
			{
				move_increase(game);
				if (game->map[i - 1][j] == 'H')
					dead_handler(game);
				if (is_valid_exit(game->map, i - 1, j))
					exit_success(game);
				game->map[i][j] = '0';
				game->map[i - 1][j] = 'P';
				if (game->m % 2 == 0)
					enemy(game);
				return ;
			}
		}
	}
}

void	player_move_down(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->p_dir = DOWN;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && !cant_move_to(game->map, i + 1, j))
			{
				move_increase(game);
				if (game->map[i + 1][j] == 'H')
					dead_handler(game);
				if (is_valid_exit(game->map, i + 1, j))
					exit_success(game);
				game->map[i][j] = '0';
				game->map[i + 1][j] = 'P';
				if (game->m % 2 == 0)
					enemy(game);
				return ;
			}
		}
	}
}

void	player_move_left(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->p_dir = LEFT;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && !cant_move_to(game->map, i, j - 1))
			{
				move_increase(game);
				if (game->map[i][j - 1] == 'H')
					dead_handler(game);
				if (is_valid_exit(game->map, i, j - 1))
					exit_success(game);
				game->map[i][j] = '0';
				game->map[i][j - 1] = 'P';
				if (game->m % 2 == 0)
					enemy(game);
				return ;
			}
		}
	}
}

void	player_move_right(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->p_dir = RIGHT;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && !cant_move_to(game->map, i, j + 1))
			{
				move_increase(game);
				if (game->map[i][j + 1] == 'H')
					dead_handler(game);
				if (is_valid_exit(game->map, i, j + 1))
					exit_success(game);
				game->map[i][j] = '0';
				game->map[i][j + 1] = 'P';
				if (game->m % 2 == 0)
					enemy(game);
				return ;
			}
		}
	}
}

void	player_movement(t_game *game, int keycode)
{
	get_p_pos(game);
	if (keycode == 119)
		player_move_up(game);
	else if (keycode == 97)
		player_move_left(game);
	else if (keycode == 115)
		player_move_down(game);
	else if (keycode == 100)
		player_move_right(game);
}
