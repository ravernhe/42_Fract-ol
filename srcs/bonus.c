/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:27:35 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:34:54 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	feigen(t_win win, t_frac var, t_complex c, t_complex z)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	while (x < var.ix)
	{
		y = 0;
		while (y < var.iy)
		{
			z = (x / var.zoom_x + var.x2) + ((y / var.zoom_y + var.y2) * I);
			i = 0;
			while (i < var.iteration && cabs(z) <= 2)
			{
				z = z * z + (c * c * c) - 0.401155;
				i++;
			}
			if (i != var.iteration)
				put_pixel_img(x, y, win.img_str, i * 0xFFFFFF / var.iteration);
			y++;
		}
		x++;
	}
	return (0);
}

int	dentitre(t_win win, t_frac var, t_complex c, t_complex z)
{
	int	x;
	int	y;
	int	i;

	c = I;
	x = 0;
	while (x < var.ix)
	{
		y = 0;
		while (y < var.iy)
		{
			z = (x / var.zoom_x + var.x2) + ((y / var.zoom_y + var.y2) * I);
			i = 0;
			while (i < var.iteration && cabs(z) <= 2)
			{
				z = z * z + c;
				i++;
			}
			if (i != var.iteration)
				put_pixel_img(x, y, win.img_str, i * 0xFFFFFF / var.iteration);
			y++;
		}
		x++;
	}
	return (0);
}

int	douady(t_win win, t_frac var, t_complex c, t_complex z)
{
	int	x;
	int	y;
	int	i;

	c = -0.123 + 0.745 * I;
	x = 0;
	while (x < var.ix)
	{
		y = 0;
		while (y < var.iy)
		{
			z = (x / var.zoom_x + var.x2) + ((y / var.zoom_y + var.y2) * I);
			i = 0;
			while (i < var.iteration && cabs(z) <= 2)
			{
				z = z * z + c;
				i++;
			}
			if (i != var.iteration)
				put_pixel_img(x, y, win.img_str, i * 0xFFFFFF / var.iteration);
			y++;
		}
		x++;
	}
	return (0);
}

int	goute(t_win win, t_frac var, t_complex c, t_complex z)
{
	int	x;
	int	y;
	int	i;

	c = I;
	x = 0;
	while (x < var.ix)
	{
		y = 0;
		while (y < var.iy)
		{
			z = (x / var.zoom_x + var.x2) + ((y / var.zoom_y + var.y2) * I);
			i = 0;
			while (i < var.iteration && cabs(z) <= 2)
			{
				z = z * z + c + c;
				i++;
			}
			if (i != var.iteration)
				put_pixel_img(x, y, win.img_str, i * 0xFFFFFF / var.iteration);
			y++;
		}
		x++;
	}
	return (0);
}

int	last(t_win win, t_frac var, t_complex c, t_complex z)
{
	int	x;
	int	y;
	int	i;

	c = -I;
	x = 0;
	while (x < var.ix)
	{
		y = 0;
		while (y < var.iy)
		{
			z = (x / var.zoom_x + var.x2) + ((y / var.zoom_y + var.y2) * I);
			i = 0;
			while (i < var.iteration && cabs(z) <= 2)
			{
				z = z * z + c - 0.4;
				i++;
			}
			if (i != var.iteration)
				put_pixel_img(x, y, win.img_str, i * 0xFFFFFF / var.iteration);
			y++;
		}
		x++;
	}
	return (0);
}
