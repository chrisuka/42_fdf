/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/04 14:35:43 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keysym_macos.h"

static void	app_close (t_vars *v, int code)
{
	// FREE SUM STUFF FIRST
	mlx_destroy_window(v->mlxo, v->mlx_win);
	exit(code);
}

int	handle_keyhook (int key, void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	if (key == KB_ESC)
		app_close (v, XC_EXIT);
	v->fdf.xpos -= ((key == ARROW_RIGHT) - (key == ARROW_LEFT)) * MOVE_STEP;
	v->fdf.ypos += ((key == ARROW_UP) - (key == ARROW_DOWN)) * MOVE_STEP;
	v->fdf.scale += ((key == KB_I) - (key == KB_O)) * SIZE_STEP;
	v->fdf.amplitude += ((key == KB_U) - (key == KB_D)) * AMP_STEP;

	v->fdf.scale = ft_max(v->fdf.scale, 1);
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
	t_vars	*v;

	v = (t_vars *)(vars);

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
