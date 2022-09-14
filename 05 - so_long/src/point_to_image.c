/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:17:00 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:15 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*point_to_player_image(t_data *data)
{
	if (data->player.direction == 'u')
		return (data->img_anim->p_u);
	else if (data->player.direction == 'd')
		return (data->img_anim->p_d);
	else if (data->player.direction == 'r')
		return (data->img_anim->p_r);
	else if (data->player.direction == 'l')
		return (data->img_anim->p_l);
	else
		return (NULL);
}

void	*point_to_image(unsigned int row, unsigned int col, t_data *data)
{
	if (data->map[row][col] == '1')
		return (data->img_st.wall);
	else if (data->map[row][col] == '0')
		return (data->img_st.floor);
	else if (data->map[row][col] == 'E')
		return (data->img_st.exit);
	else if (data->map[row][col] == 'C')
		return (data->img_anim->col);
	else if (data->map[row][col] == 'H')
		return (data->img_anim->e_r);
	else if (data->map[row][col] == 'h')
		return (data->img_anim->e_l);
	else if (data->map[row][col] == 'V')
		return (data->img_anim->e_u);
	else if (data->map[row][col] == 'v')
		return (data->img_anim->e_d);
	else if (data->map[row][col] == 'P')
		return (point_to_player_image(data));
	else
		return (NULL);
}

void	*point_to_number_image(int n, t_data *data)
{
	if (n == 0)
		return (data->img_st.n0);
	else if (n == 1)
		return (data->img_st.n1);
	else if (n == 2)
		return (data->img_st.n2);
	else if (n == 3)
		return (data->img_st.n3);
	else if (n == 4)
		return (data->img_st.n4);
	else if (n == 5)
		return (data->img_st.n5);
	else if (n == 6)
		return (data->img_st.n6);
	else if (n == 7)
		return (data->img_st.n7);
	else if (n == 8)
		return (data->img_st.n8);
	else if (n == 9)
		return (data->img_st.n9);
	else
		return (NULL);
}
