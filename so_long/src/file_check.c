/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:23:28 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:45 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_element_counter(char *c, t_data *data)
{
	if (*c == 'C')
		data->collectibles++;
	else if (*c == 'E')
		data->exits++;
	else if (*c == 'P')
	{
		if (data->starts == 0)
			data->starts++;
		else
			*c = '0';
	}
	else if (*c == '#')
		data->comment = 1;
}

static int	read_map(int fd, t_data *data)
{
	char	*map_str;
	char	buffer;

	map_str = NULL;
	while (read(fd, &buffer, 1) > 0)
	{
		if ((data->comment == 0 || buffer == '\n') && buffer != ' ')
		{
			map_element_counter(&buffer, data);
			if (buffer != '#')
				map_str = ft_strappend(map_str, buffer);
		}
		if (data->comment == 1 && buffer == '\n')
			data->comment = 0;
	}
	if (data->starts == 0 || data->collectibles == 0 || data->exits == 0)
	{
		ft_putendl("Error!\nInvalid map. Some elements are missing!");
		free(map_str);
		return (1);
	}
	data->map = ft_split(map_str, '\n');
	free(map_str);
	close (fd);
	return (validate_map(data));
}

int	file_check(t_data *data, char *file)
{
	int		fd;
	char	*path;

	if (ft_strstr(file, ".ber\0") == NULL)
	{
		ft_putendl("Error!\nNot a .ber file!");
		return (1);
	}
	path = ft_strjoin("./maps/", file);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
	{
		ft_putendl("Error!\nCouldn't open this file");
		return (1);
	}
	return (read_map(fd, data));
}
