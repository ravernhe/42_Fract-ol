/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:30:40 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:33:01 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	ft_init_julia(t_frac *var)
{
	var->iteration = 30;
	var->x1 = 1;
	var->x2 = -1;
	var->y1 = 1.2;
	var->y2 = -1.2;
	var->c = 0.1485 + (0.01 * I);
	var->zoom_x = var->ix / (var->x1 - var->x2);
	var->zoom_y = var->iy / (var->y1 - var->y2);
}

void	ft_init_leaf(t_frac *var)
{
	var->iteration = 5;
	var->x1 = 1;
	var->x2 = -1;
	var->y1 = 1.2;
	var->y2 = -1.2;
	var->c = 0.5 + (0.11 * I);
	var->zoom_x = var->ix / (var->x1 - var->x2);
	var->zoom_y = var->iy / (var->y1 - var->y2);
}

void	ft_init_mand(t_frac *var)
{
	var->iteration = 30;
	var->x1 = 0.6;
	var->x2 = -2.1;
	var->y1 = 1.2;
	var->y2 = -1.2;
	var->zoom_x = var->ix / (var->x1 - var->x2);
	var->zoom_y = var->iy / (var->y1 - var->y2);
}

void	ft_init(t_win *win, char *av)
{
	win->var.iteration = 30;
	win->var.ix = 850;
	win->var.iy = 850;
	win->var.lock = 1;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->var.ix, win->var.iy, av);
	win->i_p = mlx_new_image(win->mlx_ptr, win->var.ix, win->var.iy);
	win->img_str = mlx_get_data_addr(win->i_p, &win->b, &win->s_l, &win->end);
	if (win->fracnum == 0)
		ft_init_mand(&win->var);
	if (win->fracnum == 1 || win->fracnum == 3 || win->fracnum == 4 \
		|| win->fracnum == 5 || win->fracnum == 6 || win->fracnum == 7)
		ft_init_julia(&win->var);
	if (win->fracnum == 2)
		ft_init_leaf(&win->var);
}
