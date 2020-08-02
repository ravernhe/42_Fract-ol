/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:22:27 by ravernhe          #+#    #+#             */
/*   Updated: 2019/07/06 15:36:22 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <complex.h>

typedef _Complex double	t_complex;

typedef struct	s_frac
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	int			ix;
	int			iy;
	int			iteration;
	int			lock;
	t_complex	c;
	t_complex	z;
}				t_frac;

typedef struct	s_win
{
	t_frac	var;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*i_p;
	char	*img_str;
	int		b;
	int		s_l;
	int		end;
	int		fracnum;
}				t_win;

int				mandelbrot(t_win win, t_frac var, t_complex c, t_complex z);
int				julia(t_win win, t_frac var, t_complex c, t_complex z);
int				leaf(t_win win, t_frac var, t_complex c, t_complex z);
int				feigen(t_win win, t_frac var, t_complex c, t_complex z);
int				dentitre(t_win win, t_frac var, t_complex c, t_complex z);
int				douady(t_win win, t_frac var, t_complex c, t_complex z);
int				goute(t_win win, t_frac var, t_complex c, t_complex z);
int				last(t_win win, t_frac var, t_complex c, t_complex z);
void			put_pixel_img(int x, int y, char *str, int color);
void			ft_fract(t_win *win);
void			ft_init(t_win *win, char *av);
int				deal_key(int key, t_win *win);
int				deal_mouse(int button, int x, int y, t_win *win);
void			ft_init_mand(t_frac *var);
void			ft_init_julia(t_frac *var);
void			ft_init_leaf(t_frac *var);

#endif
