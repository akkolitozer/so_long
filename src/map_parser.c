/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:34:53 by hulescur          #+#    #+#             */
/*   Updated: 2025/12/17 17:59:01 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*init_vars(int *vars)
{
	int	i;

	i = 0;
	while (vars[i])
		vars[i++] = 0;
	return (vars);
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
	int	vars[5];
	
	vars[0] = 0;
	vars[1] = 0;
	vars[2] = 0;
	vars[3] = -1;
	while (map[++vars[3]])
	{
		vars[4] = -1;
		while (map[vars[3]][++vars[4]])
		{
			if (map[vars[3]][vars[4]] == 'P')
				vars[0]++;
			else if (map[vars[3]][vars[4]] == 'E')
				vars[1]++;
			else if (map[vars[3]][vars[4]] == 'C')
				vars[2]++;
			else if (map[vars[3]][vars[4]] != '1' && map[vars[3]][vars[4]] != '0')
				return (0);
		}
	}
	if (vars[0] != 1 || vars[1] != 1 || vars[2] < 1)
		return (0);
	return (1);
}

int	map_valid(char **map)
{
	int i;
	int same = same_len(map);
	int closed = closed_map(map);
	int pec = pec01(map);
	
	i = 0;
	if (!same_len(map) || !closed_map(map) || !pec01(map))
	{
		ft_putstr("Map is not valid");
		return (0);
	}
	ft_putstr("Map is valid");
	return (1);
}

int	main(void)
{
	char **map;
	map = map_open("map.txt");
	map_valid(map);
}