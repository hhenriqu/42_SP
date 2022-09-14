/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:24:34 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:48 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_char	*new_enemy_node(char dir, unsigned int row, unsigned int col)
{
	t_char	*new;

	new = malloc(sizeof(t_char));
	if (!new)
		return (NULL);
	new->direction = dir;
	new->row = row;
	new->col = col;
	new->next = NULL;
	return (new);
}

void	create_enemy(t_data *data, unsigned int row, unsigned int col)
{
	t_char	*new;
	t_char	*tmp;
	char	c;

	c = data->map[row][col];
	if (c == 'V')
		new = new_enemy_node('u', row, col);
	else if (c == 'v')
		new = new_enemy_node('d', row, col);
	else if (c == 'H')
		new = new_enemy_node ('r', row, col);
	else
		new = new_enemy_node ('l', row, col);
	if (!data->enemies)
		data->enemies = new;
	else
	{
		tmp = data->enemies;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_enemies_list(t_data *data)
{
	t_char	*tmp;

	if (data->enemies)
	{
		while (data->enemies)
		{
			tmp = data->enemies->next;
			free(data->enemies);
			data->enemies = tmp;
		}
	}
}
