/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:26:41 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 13:54:11 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**map_copy;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (ac == 2)
	{
		game->map = map_open(av[1]);
		map_copy = map_open(av[1]);
		if (!game->map)
		{
			ft_putstr("Error\nCould not open map file.\n");
			return (1);
		}
		if (!map_not_valid(map_copy))
			minilx_init(game);
	}
	return (0);
}
