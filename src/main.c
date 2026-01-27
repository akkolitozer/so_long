/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:26:41 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/27 16:47:16 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (ac != 2 || !game)
	{
		ft_putstr("Error\nInvalid maps\n");
		free(game);
		return (1);
	}
	if (!load_invalid(game, av[1]))
	{
		game->p_dir = DOWN;
		minilx_init(game);
	}
	else
		free(game);
	return (0);
}
