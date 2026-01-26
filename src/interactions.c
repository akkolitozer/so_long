/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:46:10 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 13:58:36 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_collectible(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	is_invalid_exit(char **map, int i, int j)
{
	if (map[i][j] == 'E' && !check_all_c(map))
		return (1);
	return (0);
}

int is_valid_exit(char **map, int i, int j)
{
	if (map[i][j] == 'E' && check_all_c(map))
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	cant_move_to(char **map, int i, int j)
{
	if (is_wall(map[i][j]) || is_invalid_exit(map, i, j))
		return (1);
	return (0);
}