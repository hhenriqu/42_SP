/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:24:49 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:43 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_enemy(unsigned int row_dst, unsigned int col_dst,
	t_data *data, t_char *enemy)
{
	char	c;

	if (enemy->direction == 'u')
		c = 'V';
	else if (enemy->direction == 'd')
		c = 'v';
	else if (enemy->direction == 'r')
		c = 'H';
	else
		c = 'h';
	data->map[row_dst][col_dst] = c;
	data->map[enemy->row][enemy->col] = '0';
	enemy->row = row_dst;
	enemy->col = col_dst;
}

static void	change_direction(t_data *data, t_char *enemy)
{
	if (enemy->direction == 'u')
	{
		enemy->direction = 'd';
		data->map[enemy->row][enemy->col] = 'v';
	}
	else if (enemy->direction == 'd')
	{
		enemy->direction = 'u';
		data->map[enemy->row][enemy->col] = 'V';
	}
	else if (enemy->direction == 'r')
	{
		enemy->direction = 'l';
		data->map[enemy->row][enemy->col] = 'h';
	}
	else if (enemy->direction == 'l')
	{
		enemy->direction = 'r';
		data->map[enemy->row][enemy->col] = 'H';
	}
}

static int	check_enemy_move(unsigned int row_dst, unsigned int col_dst,
	t_data *data, t_char *enemy)
{
	if (data->map[row_dst][col_dst] == '0')
		move_enemy(row_dst, col_dst, data, enemy);
	else if (data->map[row_dst][col_dst] == 'P')
	{
		lose_game(data);
		return (1);
	}
	else
		change_direction(data, enemy);
	return (0);
}

void	enemies_movement(t_data *data)
{
	t_char	*tmp;
	int		end_game;

	if (data->enemies)
	{
		end_game = 0;
		tmp = data->enemies;
		while (tmp && !end_game)
		{
			if (tmp->direction == 'u')
				end_game = check_enemy_move(tmp->row - 1, tmp->col, data, tmp);
			else if (tmp->direction == 'd')
				end_game = check_enemy_move(tmp->row + 1, tmp->col, data, tmp);
			else if (tmp->direction == 'r')
				end_game = check_enemy_move(tmp->row, tmp->col + 1, data, tmp);
			else
				end_game = check_enemy_move(tmp->row, tmp->col - 1, data, tmp);
			if (!end_game)
				tmp = tmp->next;
		}
	}
}
