/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:17:35 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:19 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(int row_dst, int col_dst, t_data *data)
{
	data->map[row_dst][col_dst] = 'P';
	data->map[data->player.row][data->player.col] = '0';
	data->player.row = row_dst;
	data->player.col = col_dst;
	data->moves++;
}

static void	check_player_movement(int row_dst, int col_dst, t_data *data)
{
	char	c;

	c = data->map[row_dst][col_dst];
	if (c == '0')
		move_player(row_dst, col_dst, data);
	else if (c == 'C')
	{
		move_player(row_dst, col_dst, data);
		data->collectibles--;
	}
	else if (c == 'E')
	{
		if (data->collectibles == 0)
			win_game(data);
	}
	else if (c == 'h' || c == 'H' || c == 'v' || c == 'V')
		lose_game(data);
}

int	keypress_handler(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		data->player.direction = 'u';
		check_player_movement(data->player.row - 1, data->player.col, data);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		data->player.direction = 'd';
		check_player_movement(data->player.row + 1, data->player.col, data);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		data->player.direction = 'l';
		check_player_movement(data->player.row, data->player.col - 1, data);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->player.direction = 'r';
		check_player_movement(data->player.row, data->player.col + 1, data);
	}
	else if (keycode == KEY_ESC)
		closed_by_user(data);
	return (0);
}
