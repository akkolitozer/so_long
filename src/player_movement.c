/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:31:18 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/25 19:01:03 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move_up(struct window *win, char **map, int *m)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && can_move_to(map, i - 1, j))
			{
				(*m)++;
				map[i][j] = '0';
				map[i - 1][j] = 'P';
			}
		}
	}
}

void	player_move_down(struct window *win, char **map, int *m)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && can_move_to(map, i + 1, j))
			{
				(*m)++;
				map[i][j] = '0';
				map[i + 1][j] = 'P';
			}
		}
	}
}

void	player_move_left(struct window *win, char **map, int *m)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && can_move_to(map, i, j - 1))
			{
				(*m)++;
				map[i][j] = '0';
				map[i][j - 1] = 'P';
			}
		}
	}
}

void	player_move_right(struct window *win, char **map, int *m)
{
	int	i;
	int	j;
	
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && can_move_to(map, i, j + 1))
			{
				(*m)++;
				map[i][j] = '0';
				map[i][j + 1] = 'P';
			}
		}
	}
}

void	player_movement(struct window *win, char **map, int keycode, int *m)
{
	if (keycode == 119)
		player_move_up(win, map, &m);
	else if (keycode == 97)
		player_move_down(win, map, &m);
	else if (keycode == 115)
		player_move_left(win, map, &m);
	else if (keycode == 100)
		player_move_right(win, map, &m);
}