/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:58:28 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/28 15:00:26 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dead_handler(t_game *game)
{
	ft_putstr("Enemy caught you! Game Over! : ");
	ft_putnbr(game->m);
	ft_putchar('\n');
	exit_success(game);
}

void	debug_map(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		ft_putstr(game->map[i]);
		ft_putchar('\n');
	}
}

void	move_increase(t_game *game)
{
	game->m++;
	ft_putnbr(game->m);
	ft_putstr("\n");
}