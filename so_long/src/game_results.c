/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_results.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:21:21 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 21:26:32 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_game(t_data *data)
{
	destroy_window(data);
	free_static_images(data);
	free_animated_images(data);
	free_map(data);
	free_enemies_list(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	closed_by_user(t_data *data)
{
	ft_putendl("Game closed by user!");
	close_game(data);
	return (0);
}

void	win_game(t_data *data)
{
	ft_putchar('\n');
	ft_putstr(WIN_COLOR);
	ft_putendl("██╗   ██╗   ██████╗   ██╗   ██╗\
          ██╗    ██╗  ██╗  ███╗   ██╗  ██╗");
	ft_putendl("╚██╗ ██╔╝  ██╔═══██╗  ██║   ██║\
          ██║    ██║  ██║  ████╗  ██║  ██║");
	ft_putendl(" ╚████╔╝   ██║   ██║  ██║   ██║\
          ██║ █╗ ██║  ██║  ██╔██╗ ██║  ██║");
	ft_putendl("  ╚██╔╝    ██║   ██║  ██║   ██║\
          ██║███╗██║  ██║  ██║╚██╗██║  ╚═╝");
	ft_putendl("   ██║     ╚██████╔╝  ╚██████╔╝\
          ╚███╔███╔╝  ██║  ██║ ╚████║  ██╗");
	ft_putstr("   ╚═╝      ╚═════╝    ╚═════╝\
            ╚══╝╚══╝   ╚═╝  ╚═╝  ╚═══╝  ╚═╝");
	ft_putendl(DEF_COLOR);
	ft_putchar('\n');
	close_game(data);
}

void	lose_game(t_data *data)
{
	ft_putchar('\n');
	ft_putstr(LOSE_COLOR);
	ft_putendl("██╗   ██╗   ██████╗   ██╗   ██╗\
          ██╗        ██████╗   ███████╗  ███████╗  ██╗");
	ft_putendl("╚██╗ ██╔╝  ██╔═══██╗  ██║   ██║\
          ██║       ██╔═══██╗  ██╔════╝  ██╔════╝  ██║");
	ft_putendl(" ╚████╔╝   ██║   ██║  ██║   ██║\
          ██║       ██║   ██║  ███████╗  █████╗    ██║");
	ft_putendl("  ╚██╔╝    ██║   ██║  ██║   ██║\
          ██║       ██║   ██║  ╚════██║  ██╔══╝    ╚═╝");
	ft_putendl("   ██║     ╚██████╔╝  ╚██████╔╝\
          ███████╗  ╚██████╔╝  ███████║  ███████╗  ██╗");
	ft_putstr("   ╚═╝      ╚═════╝    ╚═════╝\
           ╚══════╝   ╚═════╝   ╚══════╝  ╚══════╝  ╚═╝");
	ft_putendl(DEF_COLOR);
	ft_putchar('\n');
	close_game(data);
}
