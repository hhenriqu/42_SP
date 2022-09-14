/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:23:07 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:37 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_static_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_st.floor);
	mlx_destroy_image(data->mlx, data->img_st.wall);
	mlx_destroy_image(data->mlx, data->img_st.exit);
	mlx_destroy_image(data->mlx, data->img_st.moves);
	mlx_destroy_image(data->mlx, data->img_st.n0);
	mlx_destroy_image(data->mlx, data->img_st.n1);
	mlx_destroy_image(data->mlx, data->img_st.n2);
	mlx_destroy_image(data->mlx, data->img_st.n3);
	mlx_destroy_image(data->mlx, data->img_st.n4);
	mlx_destroy_image(data->mlx, data->img_st.n5);
	mlx_destroy_image(data->mlx, data->img_st.n6);
	mlx_destroy_image(data->mlx, data->img_st.n7);
	mlx_destroy_image(data->mlx, data->img_st.n8);
	mlx_destroy_image(data->mlx, data->img_st.n9);
}

static void	free_animated_node(t_img_anim *node, t_data *data)
{
	mlx_destroy_image(data->mlx, node->p_u);
	mlx_destroy_image(data->mlx, node->p_d);
	mlx_destroy_image(data->mlx, node->p_r);
	mlx_destroy_image(data->mlx, node->p_l);
	mlx_destroy_image(data->mlx, node->e_u);
	mlx_destroy_image(data->mlx, node->e_d);
	mlx_destroy_image(data->mlx, node->e_r);
	mlx_destroy_image(data->mlx, node->e_l);
	mlx_destroy_image(data->mlx, node->col);
}

void	free_animated_images(t_data *data)
{
	t_img_anim	*tmp;

	data->img_anim = NULL;
	while (data->img_head)
	{
		tmp = data->img_head->next;
		free_animated_node(data->img_head, data);
		free(data->img_head);
		data->img_head = tmp;
	}
}
