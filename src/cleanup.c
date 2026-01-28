/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:13:05 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/28 15:15:48 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	load_invalid(t_game *game, char *path)
{
	char	**map;

	map = map_open(path);
	if (!map)
		return (ft_putstr("Error\nInvalid path\n"));
	if (map_not_valid(map))
	{
		free_tab(map);
		return (ft_putstr("Error\nInvalid maps\n"));
	}
	free_tab(map);
	game->map = map_open(path);
	return (0);
}

void	free_struct(t_game *game)
{
	if (game->minilx)
	{
		mlx_destroy_display(game->minilx);
		free(game->minilx);
	}
	free(game);
}

void	full_cleanup(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->minilx, game->wall_img);
	if (game->ground_img)
		mlx_destroy_image(game->minilx, game->ground_img);
	if (game->p_up_img)
		mlx_destroy_image(game->minilx, game->p_up_img);
	if (game->p_down_img)
		mlx_destroy_image(game->minilx, game->p_down_img);
	if (game->p_left_img)
		mlx_destroy_image(game->minilx, game->p_left_img);
	if (game->p_right_img)
		mlx_destroy_image(game->minilx, game->p_right_img);
	if (game->collectible_img)
		mlx_destroy_image(game->minilx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->minilx, game->exit_img);
	if (game->minilx_win)
		mlx_destroy_window(game->minilx, game->minilx_win);
	if (game->p_enemy_img)
		mlx_destroy_image(game->minilx, game->p_enemy_img);
	free_tab(game->map);
	free_struct(game);
}
