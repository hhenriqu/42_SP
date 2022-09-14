/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:15:58 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:02 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_banner(t_data *data)
{
	void	*img_ptr;
	int		moves;
	int		len;
	int		i;	

	moves = data->moves;
	len = ft_nbrlen(moves);
	if (len < 3)
		len = 3;
	if (data->img_st.moves)
		mlx_put_image_to_window(data->mlx, data->win, data->img_st.moves, 0, 0);
	i = 0;
	while (++i <= len)
	{
		img_ptr = NULL;
		if (moves > 0 || i == 1)
			img_ptr = point_to_number_image(moves % 10, data);
		if (img_ptr)
		{
			mlx_put_image_to_window(data->mlx, data->win, img_ptr,
				(BANNER_HEIGHT * 7) + ((len - i) * BANNER_HEIGHT), 0);
			moves /= 10;
		}
	}	
}

static void	tick_counter(t_data *data)
{
	if (data->anim_tick == ANIM_TICKRATE)
	{
		if (!data->img_anim->next)
			data->img_anim = data->img_head;
		else
			data->img_anim = data->img_anim->next;
		data->anim_tick = 1;
	}
	else
		data->anim_tick++;
	if (data->enem_tick == ENEMY_MOVE_TICKRATE)
	{
		enemies_movement(data);
		data->enem_tick = 1;
	}
	else
		data->enem_tick++;
}

int	screen_update(t_data *data)
{
	unsigned int	row;
	unsigned int	col;
	void			*img_ptr;

	tick_counter(data);
	if (data->win)
	{
		print_banner(data);
		row = -1;
		while (++row < data->rows)
		{
			col = -1;
			while (++col < data->cols)
			{
				img_ptr = point_to_image(row, col, data);
				if (img_ptr)
				{
					mlx_put_image_to_window(data->mlx, data->win, img_ptr,
						col * SPRITE_SIZE, row * SPRITE_SIZE + BANNER_HEIGHT);
				}
			}
		}
	}
	return (0);
}
