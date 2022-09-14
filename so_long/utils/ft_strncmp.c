/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:28:57 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/14 00:28:58 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1)
	{
		if (s2)
			return (-1);
		return (0);
	}
	if (!s2)
		return (1);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		h_len;
	int		n_len;
	int		i;

	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (n_len > h_len)
		return (NULL);
	i = 0;
	while (i <= h_len - n_len)
	{
		if (ft_strncmp(haystack + i, needle, n_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
