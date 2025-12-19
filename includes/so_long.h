/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:17:32 by hulescur          #+#    #+#             */
/*   Updated: 2025/12/17 16:59:40 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

int		map_h(char **map);
int		map_w(char **map);
char	**map_open(char *map_path);
int		same_len(char **map);
int		closed_map(char **map);
int		pec01(char **map);
int		map_valid(char **map);

#endif