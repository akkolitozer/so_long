/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:34:53 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/02 16:42:37 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ber_file(char *path)
{
	int	len;

	len = 0;
	while (path[len])
		len++;
	if (len < 4 || path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
		return (0);
	return (1);
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
	return (var[2]);
}

int	rep_path(char *u, char *d, char *l, char *r)
{
	int	change;

	change = 0;
	if (*u == '0' || *u == 'C')
	{
		*u = 'P';
		change = 1;
	}
	if (*d == '0' || *d == 'C')
	{
		*d = 'P';
		change = 1;
	}
	if (*l == '0' || *l == 'C')
	{
		*l = 'P';
		change = 1;
	}
	if (*r == '0' || *r == 'C')
	{
		*r = 'P';
		change = 1;
	}
	return (change);
}
