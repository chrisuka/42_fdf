/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/23 19:57:07 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keysym_macos.h"

static int	app_close (t_vars *v)
{
	mlx_destroy_window(v->mlxo, v->mlx_win);
	exit(XC_EXIT);
	return (XC_EXIT);
}

int	handle_keyhook (int keycode, void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	if (keycode != KB_ESC)
		return (0);
	v->sig = SIG_EXIT;
	app_close (v);
	return (0);
}

int	app_update (void *vars)
{
	static int	blegh = 0;
	t_vars	*v;
	char	*timestr;

	if (!blegh)
		blegh = 1;
	else return (0);
	v = (t_vars *)(vars);
	/*
	for (int x = 0; x < WIN_RESX; x++)
		for (int y = 0; y < WIN_RESY; y++)
			set_pixel (&v->img, x, y, argb2hex(0, x, y, 0) );
			*/
	t_line	ln = (t_line){10, 50, WIN_RESX - 10, WIN_RESY - 10, 0x00FF0000};
	//set_pixel (&v->img, ln.x0, ln.y0, 0x00FFFFFF);
	draw_square (&v->img, ln.x0, ln.y0, 5, 0x00FFFFFF);
	draw_square (&v->img, ln.x1, ln.y1, 5, 0x00FFFFFF);
	draw_line (&v->img, ln);
	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	timestr = ft_itoa(v->uptime);
	mlx_string_put (v->mlxo, v->mlx_win, 0, 0, 0x00FFFFFF, timestr);
	ft_strdel(&timestr);
	
	v->uptime++;
	return (0);
}
