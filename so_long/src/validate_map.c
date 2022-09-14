/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:15:41 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/13 04:43:21 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_data *data)
{
	size_t	i;

	i = -1;
	while (++i < data->cols)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			return (1);
	}
	i = -1;
	while (++i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->cols - 1] != '1')
			return (1);
	}
	return (0);
}

static void	set_player_pos(t_data *data, unsigned int row, unsigned int col)
{
	data->player.row = row;
	data->player.col = col;
}

static int	check_invalid(t_data *data)
{
	unsigned int	row;
	unsigned int	col;

	row = -1;
	while (++row < data->rows)
	{
		col = -1;
		while (++col < data->cols)
		{
			if (data->map[row][col] == 'P')
				set_player_pos(data, row, col);
			else if (data->map[row][col] == 'H' || data->map[row][col] == 'h'
				|| data->map[row][col] == 'V' || data->map[row][col] == 'v')
				create_enemy(data, row, col);
			else if (data->map[row][col] != 'C' && data->map[row][col] != 'E'
				&& data->map[row][col] != '1' && data->map[row][col] != '0')
				return (1);
		}
	}
	return (0);
}

static int	free_map_error(t_data *data, char *message)
{
	free_map(data);
	free_enemies_list(data);
	ft_putendl(message);
	return (1);
}

int	validate_map(t_data *data)
{
	data->cols = ft_strlen(data->map[0]);
	while (data->map[++data->rows])
	{
		if (ft_strlen(data->map[data->rows]) != data->cols)
			return (free_map_error(data, "Error!\nMap is not rectangular!"));
	}
	if (check_walls(data) == 1)
		return (free_map_error(data, "Error!\nMap is not surrounded by walls!"));
	if (check_invalid(data) == 1)
		return (free_map_error(data, "Error!\nMap invalid characters!"));
	return (0);
}
