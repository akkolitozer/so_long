/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:06:33 by hulescur          #+#    #+#             */
/*   Updated: 2026/01/26 19:37:12 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../includes/get_next_line.h"

int		ft_putstr(char *str);
char	*ft_strtrim(char *str, char c);
void	ft_putnbr(int n);
int		ft_putchar(char c);
void	*ft_calloc(size_t count, size_t size);

#endif 