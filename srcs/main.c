/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:20:46 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 14:37:55 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	ft_choose(char *av, t_win *win)
{
	if (!ft_strcmp(av, "mandelbrot"))
		win->fracnum = 0;
	else if (!ft_strcmp(av, "julia"))
		win->fracnum = 1;
	else if (!ft_strcmp(av, "leaf"))
		win->fracnum = 2;
	else if (!ft_strcmp(av, "bonus_1"))
		win->fracnum = 3;
	else if (!ft_strcmp(av, "bonus_2"))
		win->fracnum = 4;
	else if (!ft_strcmp(av, "bonus_3"))
		win->fracnum = 5;
	else if (!ft_strcmp(av, "bonus_4"))
		win->fracnum = 6;
	else if (!ft_strcmp(av, "bonus_5"))
		win->fracnum = 7;
	else
	{
		ft_putendl("Usage: ./fractol [mandelbrot || julia || leaf || bonus_X]");
		exit(0);
	}
}

void	ft_fract(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->i_p);
	win->i_p = mlx_new_image(win->mlx_ptr, win->var.ix, win->var.iy);
	win->img_str = mlx_get_data_addr(win->i_p, &win->b, &win->s_l, &win->end);
	if (win->fracnum == 0)
		mandelbrot(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 1)
		julia(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 2)
		leaf(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 3)
		feigen(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 4)
		dentitre(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 5)
		douady(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 6)
		goute(*win, win->var, win->var.c, win->var.z);
	else if (win->fracnum == 7)
		last(*win, win->var, win->var.c, win->var.z);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->i_p, 0, 0);
}

int		funct(int x, int y, t_win *win)
{
	if (win->fracnum == 1 && win->var.lock == 0)
		win->var.c = x / 200.0 - 2.5 + ((y / 200.0 - 2.5) * I);
	ft_fract(win);
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;

	if (ac != 2)
	{
		ft_putendl("Usage: ./fractol [mandelbrot || julia || leaf || bonus]");
		exit(0);
	}
	ft_choose(av[1], &win);
	ft_init(&win, av[1]);
	ft_fract(&win);
	mlx_key_hook(win.win_ptr, deal_key, &win);
	mlx_mouse_hook(win.win_ptr, deal_mouse, &win);
	mlx_hook(win.win_ptr, 6, 0, funct, &win.var);
	mlx_loop(win.mlx_ptr);
	return (0);
}
