/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:00:47 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/06/12 18:52:43 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*dest;

	len = ft_strlen(s);
	dest = ft_calloc((len + 1), sizeof(const char));
	if (dest == NULL)
		return (NULL);
	dest = ft_memcpy(dest, s, len);
	return (dest);
}
