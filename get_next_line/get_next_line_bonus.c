/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:48 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/07/11 17:04:49 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_getline(char *str)
{
	char	*newline;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	newline = ft_calloc(i + 2);
	if (str[i] == '\n')
		newline[i] = '\n';
	while (i--)
		newline[i] = str[i];
	return (newline);
}

char	*ft_getrest(char *str)
{
	int		i;
	char	*rest;

	if (!str)
		return (NULL);
	if (!ft_newline(str))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	rest = ft_strjoin("", str + i);
	free(str);
	return (rest);
}

char	*ft_read(int fd, char *str, char *aux, char *buf)
{
	int	read_size;

	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buf);
			return (NULL);
		}
		if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		aux = str;
		if (aux == NULL)
			aux = ft_calloc(1);
		str = ft_strjoin(aux, buf);
		free(aux);
		if (ft_newline(str))
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX + 1];
	char		*aux;
	char		*buf;

	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	aux = NULL;
	buf = ft_calloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str[fd] = ft_read(fd, str[fd], aux, buf);
	if (!str[fd] || !*str[fd])
		return (NULL);
	aux = ft_getline(str[fd]);
	str[fd] = ft_getrest(str[fd]);
	if (!aux)
	{
		free(str[fd]);
		free(aux);
		return (NULL);
	}
	return (aux);
}
