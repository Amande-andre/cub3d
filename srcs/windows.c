/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:24:57 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 16:38:14 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	set_window(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, X_LEN, Y_LEN, "Cub3D");
	win->img = mlx_new_image(win->mlx, X_LEN, Y_LEN);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_len, &win->endian);
	return (0);
}

int	create_map_2D(t_win *win, char *av)
{
	win->fd = open(av, O_RDONLY);
	if (win->fd == -1)
		return (0);
	draw_map(win, win->fd);
	//draw_squar(win, 0x0000FF);
	return (0);
}
int	ft_close_win(int key, t_win *win)
{
	if (key == XK_Escape || key == 17)
	{
		mlx_loop_end(win->mlx);
		if (win->img)//mettre les variables a Null
			mlx_destroy_image(win->mlx, win->img);
		mlx_destroy_window(win->mlx, win->win);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		exit (0);
	}
	return (0);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *) dst = color;
// }

// int	wint_close_win(int key, t_data *win)
// {
// 	iwin (key == XK_Escape || key == 17)
// 	{
// 		mlx_loop_end(win->mlx);
// 		iwin (win->img)
// 			mlx_destroy_image(win->mlx, win->img);
// 		mlx_destroy_window(win->mlx, win->win);
// 		mlx_destroy_display(win->mlx);
// 		winree(win->mlx);
// 		exit (0);
// 	}
// 	return (0);
// }

// int	wint_close_win2(t_data *win)
// {
// 	mlx_loop_end(win->mlx);
// 	iwin (win->img)
// 		mlx_destroy_image(win->mlx, win->img);
// 	mlx_destroy_window(win->mlx, win->win);
// 	mlx_destroy_display(win->mlx);
// 	winree(win->mlx);
// 	exit (0);
// }
