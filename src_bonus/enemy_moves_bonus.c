/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:49:57 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/28 15:16:36 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_move_right(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H' &&
					!enemy_cant_move_to(game->map, i, j + 1))
			{
				if (game->map[i][j + 1] == 'P')
					dead_handler(game);
				game->map[i][j] = '0';
				game->map[i][j + 1] = 'H';
				return ;
			}
		}
	}
}

void	enemy_move_left(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H' &&
					!enemy_cant_move_to(game->map, i, j - 1))
			{
				if (game->map[i][j - 1] == 'P')
					dead_handler(game);
				game->map[i][j] = '0';
				game->map[i][j - 1] = 'H';
				return ;
			}
		}
	}
}

void	enemy_move_up(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H' &&
					!enemy_cant_move_to(game->map, i - 1, j))
			{
				if (game->map[i - 1][j] == 'P')
					dead_handler(game);
				game->map[i][j] = '0';
				game->map[i - 1][j] = 'H';
				return ;
			}
		}
	}
}

void	enemy_move_down(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H' &&
					!enemy_cant_move_to(game->map, i + 1, j))
			{
				if (game->map[i + 1][j] == 'P')
					dead_handler(game);
				game->map[i][j] = '0';
				game->map[i + 1][j] = 'H';
				return ;
			}
		}
	}
}

void	enemy_move_handler(t_game *game)
{
	if (game->e_dir == UP)
		enemy_move_up(game);
	else if (game->e_dir == DOWN)
		enemy_move_down(game);
	else if (game->e_dir == LEFT)
		enemy_move_left(game);
	else if (game->e_dir == RIGHT)
		enemy_move_right(game);
}
