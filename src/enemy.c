/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:06:00 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/27 17:37:02 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_enemy(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = 48;
	game->p_enemy_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/hostile.xpm", &tile_size, &tile_size);
	if (!game->p_enemy_img)
	{
		ft_putstr("Error loading enemy texture\n");
		exit_success(game);
		return ;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'H')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->p_enemy_img, j * tile_size, i * tile_size);
		}
	}
}

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
			}
			else if (game->map[i][j] == 'H')
			{
				game->ex = j;
				game->ey = i;
			}
		}
	}
}

void	enemy_way_to_player(t_game *game)
{
	get_p_pos(game);
	if (abs(game->px - game->ex) > abs(game->py - game->ey))
	{
		if (game->px < game->ex)
			game->e_dir = LEFT;
		else
			game->e_dir = RIGHT;
	}
	else
	{
		if (game->py < game->ey)
			game->e_dir = UP;
		else
			game->e_dir = DOWN;
	}
}

void	enemy(t_game *game)
{
	enemy_way_to_player(game);
	enemy_move_handler(game);
}