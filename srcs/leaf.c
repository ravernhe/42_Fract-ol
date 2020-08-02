/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:42:18 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:16:26 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	leaf(t_win win, t_frac var, t_complex c, t_complex z)
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
				z = ccos(z / c);
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
