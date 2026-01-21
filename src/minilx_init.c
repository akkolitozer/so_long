/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:21 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/20 18:57:00 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(void *minilx, void *minilx_win)
{
	mlx_destroy_window(minilx, minilx_win);
	return (0);
}

void minilx_init(void)
{
	void	*minilx;
	void	*minilx_win;
	minilx = mlx_init();
	minilx_win = mlx_new_window(minilx, 1000, 1000, "so_long");\
	mlx_hook(minilx_win, 17, 0, close_win, minilx);
	mlx_loop(minilx);
}