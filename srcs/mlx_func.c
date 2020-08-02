/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:09:00 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:32:32 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	put_pixel_img(int x, int y, char *str, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				len;

	len = 850;
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	str[(x * 4) + (len * 4 * y)] = b;
	str[(x * 4) + (len * 4 * y) + 1] = g;
	str[(x * 4) + (len * 4 * y) + 2] = r;
	str[(x * 4) + (len * 4 * y) + 3] = 0;
}

int		deal_key(int key, t_win *win)
{
	if (key == 49)
		win->var.lock = (win->var.lock == 0) ? 1 : 0;
	else if (key == 126 && win->var.iteration < 200)
		win->var.iteration += 1;
	else if (key == 125 && win->var.iteration > 1)
		win->var.iteration -= 1;
	else if (key == 53)
	{
		mlx_destroy_image(win->mlx_ptr, win->i_p);
		exit(0);
	}
	else if (key == 15)
	{
		if (win->fracnum == 0)
			ft_init_mand(&win->var);
		if (win->fracnum == 1 || win->fracnum == 3 || win->fracnum == 4 \
			|| win->fracnum == 5 || win->fracnum == 6 || win->fracnum == 7)
			ft_init_julia(&win->var);
		if (win->fracnum == 2)
			ft_init_leaf(&win->var);
	}
	ft_fract(win);
	return (0);
}

int		deal_mouse(int button, int x, int y, t_win *win)
{
	float	x3;
	float	y3;
	double	tmp[4];

	if (button == 1 || button == 4)
	{
		tmp[0] = win->var.x1;
		tmp[1] = win->var.x2;
		tmp[2] = win->var.y1;
		win->var.zoom_x *= 2;
		win->var.zoom_y *= 2;
		x3 = win->var.x2 + x * (win->var.x1 - win->var.x2) / win->var.ix;
		y3 = win->var.y2 + y * (win->var.y1 - win->var.y2) / win->var.iy;
		win->var.x1 = x3 + (tmp[0] - tmp[1]) / 4;
		win->var.x2 = x3 - (tmp[0] - tmp[1]) / 4;
		win->var.y1 = y3 + (tmp[2] - win->var.y2) / 4;
		win->var.y2 = y3 - (tmp[2] - win->var.y2) / 4;
	}
	else if (button == 2 || button == 5)
	{
		win->var.zoom_x *= 0.5;
		win->var.zoom_y *= 0.5;
	}
	ft_fract(win);
	return (0);
}
