/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:17:32 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/22 18:01:40 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilx/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"

typedef struct window
{
	void	*minilx;
	void	*minilx_win;
	int 	win_width;;
	int		win_height;
}	t_window;

char	**map_open(char *map_path);
int		map_h(char **map);
int		map_w(char **map);
int		count_lines(char *map_path);
int		same_len(char **map);
int		closed_map(char **map);
int		pec01(char **map);
int		rep_path(char *u, char *d, char *l, char *r);
int		check_exit(char **map);
int		check_path(char **map);
int		ce_reachable(char **map);
int		map_not_valid(char **map);
int		minilx_init(char **map);


#endif