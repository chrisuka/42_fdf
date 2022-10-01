/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 20:11:42 by ikarjala         ###   ########.fr       */
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
	if (keycode == KB_ESC)
		app_close (v);
	v->fdf.xpos += ((keycode == ARROW_RIGHT) - (keycode == ARROW_LEFT)) * MOVE_STEP;
	v->fdf.ypos -= ((keycode == ARROW_UP) - (keycode == ARROW_DOWN)) * MOVE_STEP;
	v->fdf.scale += ((keycode == KB_ASCII_I) - (keycode == KB_ASCII_O)) * SIZE_STEP;
	/*
	ft_putnbr(keycode);
	ft_putendl("");
	*/
	if (keycode == KB_SPC)
		v->fdf.projection = !v->fdf.projection;
	return (0);
}

int	app_update (void *vars)
{
	const int	update = 1;
	static int	drew_once = 0;
	t_vars	*v;

	if (drew_once)
		return (0);
	drew_once |= !update;
	v = (t_vars *)(vars);

	// CLEAR STENCIL
	ft_bzero (v->img.addr, (WIN_RESX * WIN_RESY - 1) * sizeof(int));

	/*
	for (int x = 0; x < WIN_RESX; x++)
		for (int y = 0; y < WIN_RESY; y++)
			set_pixel (&v->img, x, y, 0x0000FF00);
			*/

	//db_draw_unitcircle (&v->img, WIN_RESX / 2, WIN_RESY / 2, WIN_RESY / 2 - 10);

	draw_map(&v->img, v->fdf);

	// GUI
	draw_gui (&v->img);

	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);

	gui_put_text (v);

	v->uptime++;
	return (0);
}
