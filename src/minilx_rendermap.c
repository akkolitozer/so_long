/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_rendermap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:49:55 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/25 19:41:08 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_walls(t_game *game, char **map)
{
	int	i;
	int	j;
	int	tile_size;
	void	*wall_img;

	tile_size = 48;
	wall_img = mlx_xpm_file_to_image(game->minilx, "./textures/wall.xpm", 
		&tile_size, &tile_size);
	if (!wall_img)
	{
		ft_putstr("Error loading wall texture\n");
		return ;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->minilx, game->minilx_win, 
					wall_img, j * tile_size, i * tile_size);
		}
	}
}

void	render_ground(t_game *game, char **map)
{
	int	i;
	int	j;
	int	tile_size;
	void	*ground_img;
	
	tile_size = 48;
	ground_img = mlx_xpm_file_to_image(game->minilx, "./textures/ground.xpm", 
		&tile_size, &tile_size);
	if (!ground_img)
	{
		ft_putstr("Error loading ground texture\n");
		return ;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->minilx, game->minilx_win, 
					ground_img, j * tile_size, i * tile_size);
		}
	}
}
void	render_player(t_game *game, char **map)
{
	int	i;
	int	j;
	int	tile_size;
	void	*player_img;

	tile_size = 48;
	player_img = mlx_xpm_file_to_image(game->minilx, "./textures/playerRight.xpm", 
		&tile_size, &tile_size);
	if (!player_img)
	{
		ft_putstr("Error loading player texture\n");
		return ;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->minilx, game->minilx_win, 
					player_img, j * tile_size, i * tile_size);
		}
	}
}

void	render_collectibles(t_game *game, char **map)
{
	int	i;
	int	j;
	int	tile_size;
	void	*collectible_img;

	tile_size = 48;
	collectible_img = mlx_xpm_file_to_image(game->minilx, 
		"./textures/collectible.xpm", &tile_size, &tile_size);
	if (!collectible_img)
	{
		ft_putstr("Error loading collectible texture\n");
		return ;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(game->minilx, game->minilx_win, 
					collectible_img, j * tile_size, i * tile_size);
		}
	}
}
void	render_exit(t_game *game, char **map)
{
	int	i;
	int	j;
	int	tile_size;
	void	*exit_img;

	tile_size = 48;
	exit_img = mlx_xpm_file_to_image(game->minilx, "./textures/exit.xpm", 
		&tile_size, &tile_size);
	if (!exit_img)
	{
		ft_putstr("Error loading exit texture\n");
		return ;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->minilx, game->minilx_win, 
					exit_img, j * tile_size, i * tile_size);
		}
	}
}
