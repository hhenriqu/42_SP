/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:28:51 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/14 00:28:53 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}