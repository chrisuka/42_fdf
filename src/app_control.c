/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/21 22:47:55 by ikarjala         ###   ########.fr       */
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
	t_vars	*v;
	char	*timestr;

	v = (t_vars *)(vars);
	for (int x = 0; x < WIN_RESX; x++)
		for (int y = 0; y < WIN_RESY; y++)
			set_pixel (&v->img, x, y, argb2hex(0, x, y, 0) );
	
	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	timestr = ft_itoa(v->uptime);
	mlx_string_put (v->mlxo, v->mlx_win, 0, 0, 0x00FFFFFF, timestr);
	ft_strdel(&timestr);
	
	v->uptime++;
	return (0);
}
