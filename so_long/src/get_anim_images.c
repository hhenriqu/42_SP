/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_anim_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:18:24 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:26 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img_anim	*create_img_node0(t_data *data)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(data->mlx, "./sprites/p_u0.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(data->mlx, "./sprites/p_d0.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(data->mlx, "./sprites/p_l0.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(data->mlx, "./sprites/p_r0.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(data->mlx, "./sprites/e_u0.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(data->mlx, "./sprites/e_d0.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(data->mlx, "./sprites/e_l0.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(data->mlx, "./sprites/e_r0.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(data->mlx, "./sprites/col0.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node1(t_data *data)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(data->mlx, "./sprites/p_u1.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(data->mlx, "./sprites/p_d1.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(data->mlx, "./sprites/p_l1.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(data->mlx, "./sprites/p_r1.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(data->mlx, "./sprites/e_u1.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(data->mlx, "./sprites/e_d1.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(data->mlx, "./sprites/e_l1.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(data->mlx, "./sprites/e_r1.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(data->mlx, "./sprites/col1.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node2(t_data *data)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(data->mlx, "./sprites/p_u2.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(data->mlx, "./sprites/p_d2.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(data->mlx, "./sprites/p_l2.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(data->mlx, "./sprites/p_r2.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(data->mlx, "./sprites/e_u2.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(data->mlx, "./sprites/e_d2.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(data->mlx, "./sprites/e_l2.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(data->mlx, "./sprites/e_r2.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(data->mlx, "./sprites/col2.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

static t_img_anim	*create_img_node3(t_data *data)
{
	t_img_anim	*node;
	int			w;
	int			h;

	node = malloc(sizeof(t_img_anim));
	if (!node)
		return (NULL);
	node->p_u = mlx_xpm_file_to_image(data->mlx, "./sprites/p_u1.xpm", &w, &h);
	node->p_d = mlx_xpm_file_to_image(data->mlx, "./sprites/p_d1.xpm", &w, &h);
	node->p_l = mlx_xpm_file_to_image(data->mlx, "./sprites/p_l1.xpm", &w, &h);
	node->p_r = mlx_xpm_file_to_image(data->mlx, "./sprites/p_r1.xpm", &w, &h);
	node->e_u = mlx_xpm_file_to_image(data->mlx, "./sprites/e_u1.xpm", &w, &h);
	node->e_d = mlx_xpm_file_to_image(data->mlx, "./sprites/e_d1.xpm", &w, &h);
	node->e_l = mlx_xpm_file_to_image(data->mlx, "./sprites/e_l1.xpm", &w, &h);
	node->e_r = mlx_xpm_file_to_image(data->mlx, "./sprites/e_r1.xpm", &w, &h);
	node->col = mlx_xpm_file_to_image(data->mlx, "./sprites/col3.xpm", &w, &h);
	node->next = NULL;
	return (node);
}

void	get_animated_nodes(t_data *data)
{
	data->img_head = create_img_node0(data);
	data->img_head->next = create_img_node1(data);
	data->img_anim = data->img_head->next;
	data->img_anim->next = create_img_node2(data);
	data->img_anim = data->img_anim->next;
	data->img_anim->next = create_img_node3(data);
}
