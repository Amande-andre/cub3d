/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:54:45 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 12:33:01 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define Y_LEN		1200
# define X_LEN		(Y_LEN)
# define PRESS_ARROW_UP 65362
# define PRESS_ARROW_DOWN 65364
# define PRESS_ARROW_LEFT 65361
# define PRESS_ARROW_RIGHT 65363
# define BUFFER_SIZE 1

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx_int.h"

// typedef struct s_win
// {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }				t_win;

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// }				t_mlx;
typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		fd;
	char	**map;
	int		map_x;
	int		map_y;
}	t_win;

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		set_window(t_win *win);
int		ft_close_win(int key, t_win *win);
int		create_map_2D(t_win *win, char *av);
void	draw_map(t_win *win, int fd);
void	draw_squar(t_win *win, int color);

#endif