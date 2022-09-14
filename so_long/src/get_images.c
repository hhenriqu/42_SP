/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:17:57 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/13 04:44:13 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_static_images(t_data *data)
{
	t_img_st	*img;
	int			w;
	int			h;

	img = &data->img_st;
	img->floor = mlx_xpm_file_to_image(data->mlx, "./sprites/sqm.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(data->mlx, "./sprites/wall.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(data->mlx, "./sprites/exit.xpm", &w, &h);
	img->moves = mlx_xpm_file_to_image(data->mlx, "./sprites/mov.xpm", &w, &h);
	img->n0 = mlx_xpm_file_to_image(data->mlx, "./sprites/n0.xpm", &w, &h);
	img->n1 = mlx_xpm_file_to_image(data->mlx, "./sprites/n1.xpm", &w, &h);
	img->n2 = mlx_xpm_file_to_image(data->mlx, "./sprites/n2.xpm", &w, &h);
	img->n3 = mlx_xpm_file_to_image(data->mlx, "./sprites/n3.xpm", &w, &h);
	img->n4 = mlx_xpm_file_to_image(data->mlx, "./sprites/n4.xpm", &w, &h);
	img->n5 = mlx_xpm_file_to_image(data->mlx, "./sprites/n5.xpm", &w, &h);
	img->n6 = mlx_xpm_file_to_image(data->mlx, "./sprites/n6.xpm", &w, &h);
	img->n7 = mlx_xpm_file_to_image(data->mlx, "./sprites/n7.xpm", &w, &h);
	img->n8 = mlx_xpm_file_to_image(data->mlx, "./sprites/n8.xpm", &w, &h);
	img->n9 = mlx_xpm_file_to_image(data->mlx, "./sprites/n9.xpm", &w, &h);
}

void	get_images(t_data *data)
{
	get_static_images(data);
	get_animated_nodes(data);
}
