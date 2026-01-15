/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:36:42 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/15 18:37:16 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int check_exit(char **map)
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

int	check_path(char **map)
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
	int count_c;
	
	count_c = 0;
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
				change += rep_path(&map[i - 1][j], &map[i + 1][j], &map[i][j - 1], &map[i][j + 1]);
		}
	}
	return (check_path(map) && check_exit(map));
}

int	map_not_valid(char **map)
{
	int	i;

	i = 0;
	if (!same_len(map))
		i += ft_putstr("Map is not rectangular\n");
	if (!closed_map(map))
		i += ft_putstr("Map is not surrounded by walls\n");
	if (!pec01(map))
		i += ft_putstr("Map does not contain the correct number of elements\n");
	if (!ce_reachable(map))
		i += ft_putstr("Map does not contain valid elements\n");
	if (i == 0)
		ft_putstr("Map is VALID\n");
	return (i);
}

int	main(void)
{
	int i = 0;
	char **map;
	map = map_open("map.txt");
	// while (map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	map_not_valid(map);
}