/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:18:51 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/06/12 18:59:38 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ps;
	unsigned char	pc;

	i = 0;
	pc = (unsigned char)c;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (ps[i] == pc)
		{
				ps = &ps[i];
			return ((void *)ps);
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}
