/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/03 22:02:57 by ikarjala         ###   ########.fr       */
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

int	handle_keyhook (int key, void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	if (key == KB_ESC)
		app_close (v);
	v->fdf.xpos -= ((key == ARROW_RIGHT) - (key == ARROW_LEFT)) * MOVE_STEP;
	v->fdf.ypos += ((key == ARROW_UP) - (key == ARROW_DOWN)) * MOVE_STEP;
	v->fdf.scale += ((key == KB_I) - (key == KB_O)) * SIZE_STEP;
	v->fdf.amplitude += ((key == KB_U) - (key == KB_D)) * AMP_STEP;

	v->fdf.scale = ft_max(v->fdf.scale, 0);
#if 0
	ft_putnbr(key);
	ft_putendl("");
#endif
	if (key == KB_SPC)
		v->fdf.projection = !v->fdf.projection;
	return (0);
}

int	app_update (void *vars)
{
	const int	update = 1;
	static int	drew_once = 0;
	t_vars	*v;

	v = (t_vars *)(vars);
	if (drew_once)
		return (0);
	else set_pixel (&v->img, WIN_RESX, WIN_RESY, 0x00FF0000);
	drew_once |= !update;

	// CLEAR STENCIL	(THESE CALCULATIONS ARE PROBABLY WRONG!!)
	ft_bzero (v->img.addr, (WIN_RESX * WIN_RESY) * (v->img.bpp / 8));
	//ft_memset (v->img.addr, 0xFF, v->img.width * WIN_RESY * v->img.bpp);

	//db_draw_unitcircle (&v->img, WIN_RESX / 2, WIN_RESY / 2, WIN_RESY / 2 - 10);

	draw_map(&v->img, v->fdf);

	// GUI
	draw_gui (&v->img);

	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	gui_put_text (v);

	v->uptime++;
	return (0);
}
