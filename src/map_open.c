/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:21:56 by hulescur          #+#    #+#             */
/*   Updated: 2025/12/17 17:24:42 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_h(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

int	map_w(char **map)
{
	int	w;

	w = 0;
	while (map[0][w] && map[0][w] != '\n')
		w++;
	return (w);
}

int	count_lines(char *map_path)
{
	int		fd;
	int		count;
	char	*line;
	
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**map_open(char *map_path)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;
	char	*line;

	i = 0;
	lines = count_lines(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = ft_strtrim(line, '\n');
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
