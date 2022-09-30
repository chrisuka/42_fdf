/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/30 21:08:54 by ikarjala         ###   ########.fr       */
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

	//db_draw_unitcircle (&v->img, WIN_RESX / 2, WIN_RESY / 2, WIN_RESY / 2 - 10);

#if 1
	const int	ox = WIN_RESX / 2;
	const int	oy = WIN_RESY / 2;
	t_rect2d r = (t_rect2d){ox, oy, (50 * 10), (50 * 7), 0x00AABBAA};
	draw_rect(&v->img, r, 0);
#endif

	draw_map(&v->img, v->fdf);

	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	timestr = ft_itoa(v->uptime);
	mlx_string_put (v->mlxo, v->mlx_win, 10, 10, 0x00FFFFFF, timestr);
	ft_strdel(&timestr);
	
	v->uptime++;
	return (0);
}
