/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:06:00 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 17:14:36 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_p_pos(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->px = j;
				game->py = i;
				return ;
			}
		}
	}
}

void	get_e_pos(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H')
			{
				game->ex = j;
				game->ey = i;
				return ;
			}
		}
	}
}

int	enemy_detect_player(t_game *game)
{
	get_p_pos(game);
	get_e_pos(game);
	if (abs(game->px - game->ex) > abs(game->py - game->ey))
		return (1);
	return (0);
}

void	enemy_move(t_game *game)
{
		
}

void	enemy(t_game *game)
{
	
}