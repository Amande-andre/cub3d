/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:40:17 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 12:43:04 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	set_data(t_win *win)
{
	win->fd = 0;
	win->map_x = 0;
	win->map_y = 0;
	if (set_window(win) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_win	win;

	if (ac != 2)
		return (0);
	if (set_data(&win) == 1)
		return (1);
	create_map_2D(&win, av[1]);
	//draw_squar(&win, 0xFF0000);
	mlx_hook(win.win, 17, 0, ft_close_win, &win);
	mlx_hook(win.win, 2, 1L << 0, ft_close_win, &win);
	mlx_loop(win.mlx);
	(void)av;
	return (0);
}
