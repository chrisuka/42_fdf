/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/27 16:32:52 by ikarjala         ###   ########.fr       */
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

	db_draw_unitcircle (&v->img, WIN_RESX / 2, WIN_RESY / 2, WIN_RESY / 2 - 10);
	//draw_line (&v->img, ln);
	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	timestr = ft_itoa(v->uptime);
	mlx_string_put (v->mlxo, v->mlx_win, 10, 10, 0x00FFFFFF, timestr);
	ft_strdel(&timestr);
	
	v->uptime++;
	return (0);
}
