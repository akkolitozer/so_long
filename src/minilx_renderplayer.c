/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_renderplayer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:49:20 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/27 15:59:17 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	defineplayerupimg(t_game *game)
{
	int	tile_size;

	tile_size = 48;
	game->p_up_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/playerUp.xpm", &tile_size, &tile_size);
	if (!game->p_up_img)
	{
		ft_putstr("Error loading player up texture\n");
		exit_success(game);
		return ;
	}
}

void	defineplayerdownimg(t_game *game)
{
	int	tile_size;

	tile_size = 48;
	game->p_down_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/playerDown.xpm", &tile_size, &tile_size);
	if (!game->p_down_img)
	{
		ft_putstr("Error loading player down texture\n");
		exit_success(game);
		return ;
	}
}

void	defineplayerleftimg(t_game *game)
{
	int	tile_size;

	tile_size = 48;
	game->p_left_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/playerLeft.xpm", &tile_size, &tile_size);
	if (!game->p_left_img)
	{
		ft_putstr("Error loading player left texture\n");
		exit_success(game);
		return ;
	}
}

void	defineplayerrightimg(t_game *game)
{
	int	tile_size;

	tile_size = 48;
	game->p_right_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/playerRight.xpm", &tile_size, &tile_size);
	if (!game->p_right_img)
	{
		ft_putstr("Error loading player right texture\n");
		exit_success(game);
		return ;
	}
}

void	defineplayerimg(t_game *game)
{
	defineplayerdownimg(game);
	defineplayerupimg(game);
	defineplayerleftimg(game);
	defineplayerrightimg(game);
	game->p_img = game->p_down_img;
	if (game->p_dir == UP)
		game->p_img = game->p_up_img;
	else if (game->p_dir == DOWN)
		game->p_img = game->p_down_img;
	else if (game->p_dir == LEFT)
		game->p_img = game->p_left_img;
	else if (game->p_dir == RIGHT)
		game->p_img = game->p_right_img;
}
