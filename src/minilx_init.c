/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:01:21 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/22 18:06:43 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(void *minilx, void *minilx_win)
{
	mlx_destroy_window(minilx, minilx_win);
	return (0);
}

int	minilx_init(char **map)
{
	struct window	win;

	win.win_width = map_w(map) * 48;
	win.win_height = map_h(map) * 48;
	win.minilx = mlx_init();
	win.minilx_win = mlx_new_window(win.minilx, win.win_width, win.win_height, "so_long");
	mlx_hook(win.minilx_win, 17, 0, close_win, win.minilx);
	mlx_loop(win.minilx);
	return (0);
}
