/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmande <anmande@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:23:09 by anmande           #+#    #+#             */
/*   Updated: 2023/10/04 12:54:01 by anmande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_len + x * (win->bpp / 8));
	(void)color;
	(void)dst;
}

void	draw_squar(t_win *win, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			my_mlx_pixel_put(win, i, j, color);
			j++;
		}
		i++;
	}
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
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		j = 0;
		while (j < 10)
		{
			if (line[j] == '1')
				draw_squar(win, 0x00FF0000);
			else if (line[j] == '0')
				draw_squar(win, 0x00000000);
			else if (line[j] == '2')
				draw_squar(win, 0x0000FF00);
			j++;
		}
		i++;
	}

}
