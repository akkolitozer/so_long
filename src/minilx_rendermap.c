/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_rendermap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:49:55 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/27 16:07:35 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_walls(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = 48;
	if (game->wall_img)
		free(game->wall_img);
	game->wall_img = mlx_xpm_file_to_image(game->minilx, "./textures/wall.xpm",
			&tile_size, &tile_size);
	if (!game->wall_img)
	{
		ft_putstr("Error loading wall texture\n");
		exit_success(game);
		return ;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->wall_img, j * tile_size, i * tile_size);
	}
}

void	render_ground(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = 48;
	game->ground_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/ground.xpm", &tile_size, &tile_size);
	if (!game->ground_img)
	{
		ft_putstr("Error loading ground texture\n");
		exit_success(game);
		return ;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->ground_img, j * tile_size, i * tile_size);
		}
	}
}

void	render_player(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	defineplayerimg(game);
	tile_size = 48;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->p_img, j * tile_size, i * tile_size);
	}
}

void	render_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = 48;
	game->collectible_img = mlx_xpm_file_to_image(game->minilx,
			"./textures/collectible.xpm", &tile_size, &tile_size);
	if (!game->collectible_img)
	{
		ft_putstr("Error loading collectible texture\n");
		exit_success(game);
		return ;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->collectible_img, j * tile_size, i * tile_size);
		}
	}
}

void	render_exit(t_game *game)
{
	int	i;
	int	j;
	int	tile_size;

	tile_size = 48;
	game->exit_img = mlx_xpm_file_to_image(game->minilx, "./textures/exit.xpm",
			&tile_size, &tile_size);
	if (!game->exit_img)
	{
		ft_putstr("Error loading exit texture\n");
		exit_success(game);
		return ;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->minilx, game->minilx_win,
					game->exit_img, j * tile_size, i * tile_size);
		}
	}
}
