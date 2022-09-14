/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:15:17 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:11 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_struct(t_data *data)
{
	data->img_anim = NULL;
	data->img_head = NULL;
	data->comment = 0;
	data->rows = 0;
	data->cols = 0;
	data->starts = 0;
	data->collectibles = 0;
	data->exits = 0;
	data->map = NULL;
	data->player.direction = 'r';
	data->enemies = NULL;
	data->moves = 0;
	data->anim_tick = 1;
	data->enem_tick = 1;
}

int	so_long(t_data *data)
{
	int	window_width;

	window_width = data->cols * SPRITE_SIZE;
	if (window_width < BANNER_HEIGHT * 10)
		window_width = BANNER_HEIGHT * 10;
	data->mlx = mlx_init();
	if (data->mlx)
	{
		data->win = mlx_new_window(data->mlx, window_width,
				data->rows * SPRITE_SIZE + BANNER_HEIGHT, "so_long");
		if (data->win)
		{
			get_images(data);
			mlx_loop_hook(data->mlx, &screen_update, data);
			mlx_hook(data->win, 2, (1L << 0), &keypress_handler, data);
			mlx_hook(data->win, 17, 0, &closed_by_user, data);
			mlx_loop(data->mlx);
		}		
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_putendl("Error!\nInvalid arguments!");
	else
	{
		set_struct(&data);
		if (file_check(&data, argv[1]) == 0)
			so_long(&data);
	}
	return (0);
}
