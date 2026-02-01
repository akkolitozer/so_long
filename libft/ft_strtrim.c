/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:19:51 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/01 15:04:14 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char *str, char c)
{
	char	*sc;
	int		i;
	int		temp;
	int		len;
	int		start;

	i = 0;
	len = 0;
	start = 0;
	while (str[i] && str[i] == c)
		i++;
	temp = i;	
	while (str[i] && str[i++] != c)
		len++;
	sc = malloc(sizeof(char) * (len + 1));
	while (str[temp] && str[temp] != c)
		sc[start++] = str[temp++];
	sc[start] = 0;
	return (sc);
}
