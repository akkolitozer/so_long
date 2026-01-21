/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:26:41 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/21 15:34:08 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac == 2)
	{
		map = map_open(av[1]);
		if (!map)
		{
			ft_putstr("Error\nCould not open map file.\n");
			return (1);
		}
		if (!map_not_valid(map))
			minilx_init();
	}
	return (0);
}
