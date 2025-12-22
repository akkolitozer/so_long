/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:34:53 by hulescur          #+#    #+#             */
/*   Updated: 2025/12/22 16:06:14 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*init_vars(int *var)
{
	int	i;

	i = 0;
	while (var[i])
		var[i++] = 0;
	return (var);
}

int	same_len(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i++]) != map_w(map))
			return (0);
	}
	return (1);
}

int	closed_map(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || j == 0 || i == (map_h(map) - 1) 
				|| j == (map_w(map) - 1)) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	pec01(char **map)
{
	int	var[5];
	
	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	var[3] = -1;
	while (map[++var[3]])
	{
		var[4] = -1;
		while (map[var[3]][++var[4]])
		{
			if (map[var[3]][var[4]] == 'P')
				var[0]++;
			else if (map[var[3]][var[4]] == 'E')
				var[1]++;
			else if (map[var[3]][var[4]] == 'C')
				var[2]++;
			else if (map[var[3]][var[4]] != '1' && map[var[3]][var[4]] != '0')
				return (0);
		}
	}
	if (var[0] != 1 || var[1] != 1 || var[2] < 1)
		return (0);
	return (1);
}

int	rep_path(char *u, char *d, char *l, char *r)
{
	int change;
	
	change = 0;
	if (*u == '0' || *u == 'C' || *u == 'E')
	{
		*u = 'P';
		change = 1;
	}
	if (*d == '0' || *d == 'C' || *d == 'E')
	{
		*d = 'P';
		change = 1;
	}
	if (*l == '0' || *l == 'C' || *l == 'E')
	{
		*l = 'P';
		change = 1;
	}
	if (*r == '0' || *r == 'C' || *r == 'E')
	{
		*r = 'P';
		change = 1;
	}
	return (change);
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
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
		}
	}
	return (1);
}

int	c_reachable(char **map)
{
	int l = 0;
	int	loop;
	int	change;
	int	i;
	int	j;
	
	loop = (map_h(map) - 2) * 2;
	if (map_w(map) > map_h(map))
	loop = (map_w(map) - 2) * 2;
	while (loop)
	{
		change = 0;
		printf("\nLoops left : %d\n", loop--);	
		i = 0;
		while (map[++i + 1])
		{
			j = 0;
			while (map[i][++j + 1])
			if (map[i][j] == 'P')
				change += rep_path(&map[i - 1][j], &map[i + 1][j], &map[i][j - 1], &map[i][j + 1]);
		}
		while (map[l])
			printf("%s\n", map[l++]);
		l = 0;
		printf("Change : %d\n\n", change);
		if (!change)
		break;
	}
	return (check_path(map));
}

int	map_valid(char **map)
{
	if (!same_len(map))
	{
		ft_putstr("Map is not rectangular");
		return (0);
	}
	if (!closed_map(map))
	{
		ft_putstr("Map is not surrounded by walls");
		return (0);
	}
	if (!pec01(map))
	{
		ft_putstr("Map does not contain the correct number of elements");
		return (0);
	}
	if (!c_reachable(map))
	{
		ft_putstr("Map does not contain valid elements");
		return (0);
	}
	ft_putstr("Map is VALID");
	return (1);
}

int	main(void)
{
	char **map;
	map = map_open("map.txt");
	map_valid(map);
}