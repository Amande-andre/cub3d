/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:23:09 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 17:26:31 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_squar(t_win *win, int color, int x_map, int y_map)
{
	int	i;
	int	j;

	i = x_map * 10;
	while (i < (x_map + 1) * 10)
	{
		j = y_map * 10;
		while (j < (y_map + 1) * 10)
		{
			my_mlx_pixel_put(win, i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}


char *get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(100000);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}

void	draw_map(t_win *win, int fd)
{
	int 	i;
	int 	j;
	char	*line;

	j = 0;
	while (j < 6)
	{
		i = 0;
		line = get_next_line(fd);
		printf("%s\n", line);
		while (line[i])
		{
			if (line[i] == '1')
				draw_squar(win, 0xFF0000, i, j);
			else if (line[i] == '0')
				draw_squar(win, 0x00FF00, i, j);
			i++;
		}
		j++;
	}
	//draw_squar(win, 0x0000FF);
	(void)fd;
}
