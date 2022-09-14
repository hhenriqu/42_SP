/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:21:41 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:34 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	size_t	i;

	i = -1;
	while (data->map[++i])
	{
		free(data->map[i]);
	}
	free(data->map);
	data->map = NULL;
}

void	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
}
