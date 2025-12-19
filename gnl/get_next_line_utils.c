/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:42 by hulescur          #+#    #+#             */
/*   Updated: 2025/12/17 16:49:04 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sc;
	size_t	i;
	size_t	j;
	size_t	totalen;

	if (!s1 && !s2)
		return (NULL);
	totalen = ft_strlen(s1) + ft_strlen(s2);
	sc = malloc((totalen + 1) * sizeof(char));
	if (!sc)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		sc[i++] = s2[j++];
	sc[i] = 0;
	free(s1);
	return (sc);
}