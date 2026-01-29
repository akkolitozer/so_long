/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:36:42 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 11:32:00 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i + 1])
	{
		j = 0;
		while (map[i][++j + 1])
		{
			if (map[i][j] == 'E')
				if (map[i - 1][j] != 'P' && map[i + 1][j] != 'P'
					&& map[i][j - 1] != 'P' && map[i][j + 1] != 'P')
					return (0);
		}
	}
	return (1);
}

int	check_all_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i + 1])
	{
		j = 0;
		while (map[i][++j + 1])
		{
			if (map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

int	ce_reachable(char **map)
{
	int	change;
	int	i;
	int	j;

	change = 1;
	while (change)
	{
		change = 0;
		i = 0;
		while (map[++i + 1])
		{
			j = 0;
			while (map[i][++j + 1])
				if (map[i][j] == 'P')
					change += rep_path(&map[i - 1][j], &map[i + 1][j],
							&map[i][j - 1], &map[i][j + 1]);
		}
	}
	return (check_all_c(map) && check_exit(map));
}

int	map_not_valid(char **map)
{
	int	i;

	i = 0;
	if (!same_len(map))
		i += ft_putstr("Error\nMap is not rectangular\n");
	if (!closed_map(map))
	{
		if (!i)
			ft_putstr("Error\n");
		i += ft_putstr("Map is not surrounded by walls\n");
	}
	if (!pec01(map))
	{
		if (!i)
			ft_putstr("Error\n");
		i += ft_putstr("Map contains incorrect number of elements\n");
	}
	if (!ce_reachable(map))
	{
		if (!i)
			ft_putstr("Error\n");
		i += ft_putstr("Map contains incorrect elements\n");
	}
	return (i);
}
