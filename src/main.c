/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:26:41 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 18:14:30 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**map_copy;
	t_game	*game;

	if (ac != 2)
		return (1);
	game = calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	game->map = map_open(av[1]);
	map_copy = map_open(av[1]);
	if (!game->map || !map_copy)
	{
		free_map(game->map);
		free_map(map_copy);
		free(game);
		return (exit_error(game, "Error\nCould not open map file\n"));
	}
	if (!map_not_valid(map_copy))
		minilx_init(game);
	free_map(map_copy);
	free_map(game->map);
	full_cleanup(game);
	return (0);
}
