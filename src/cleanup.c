/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:38:09 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 18:08:47 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	cleanup(t_game *game)
{
	if (game->wall_img)
	{
		mlx_destroy_image(game->minilx, game->wall_img);
		game->wall_img = NULL;
	}
	if (game->ground_img)
	{
		mlx_destroy_image(game->minilx, game->ground_img);
		game->ground_img = NULL;
	}
	if (game->p_img)
	{
		mlx_destroy_image(game->minilx, game->p_img);
		game->p_img = NULL;
	}
	if (game->p_up_img)
	{
		mlx_destroy_image(game->minilx, game->p_up_img);
		game->p_up_img = NULL;
	}
	if (game->p_down_img)
	{
		mlx_destroy_image(game->minilx, game->p_down_img);
		game->p_down_img = NULL;
	}
}

void	cleanup2(t_game *game)
{
	if (game->p_left_img)
	{
		mlx_destroy_image(game->minilx, game->p_left_img);
		game->p_left_img = NULL;
	}
	if (game->p_right_img)
	{
		mlx_destroy_image(game->minilx, game->p_right_img);
		game->p_right_img = NULL;
	}
	if (game->collectible_img)
	{
		mlx_destroy_image(game->minilx, game->collectible_img);
		game->collectible_img = NULL;
	}
	if (game->exit_img)
	{
		mlx_destroy_image(game->minilx, game->exit_img);
		game->exit_img = NULL;
	}
	if (game->minilx_win)
	{
		mlx_destroy_window(game->minilx, game->minilx_win);
		game->minilx_win = NULL;
	}
}

void	cleanup3(t_game *game)
{
	int	i;

	i = 0;
	
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->minilx)
	{
		mlx_destroy_display(game->minilx);
		free(game->minilx);
		game->minilx = NULL;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

void	full_cleanup(t_game *game)
{
	cleanup(game);
	cleanup2(game);
	cleanup3(game);
	free(game);
}