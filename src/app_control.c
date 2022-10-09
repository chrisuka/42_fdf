/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:16:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 18:14:27 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keysym_macos.h"

void	app_close(t_vars *v, int code)
{
	if (v->fdf.map)
		ft_freearray((void **)&v->fdf.map, v->fdf.h);
	if (v->mlxo)
		mlx_destroy_window(v->mlxo, v->mlx_win);
	v->mlxo = NULL;
	v->mlx_win = NULL;
	exit(code);
}

int	on_keydown(int key, void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	v->fdf.xpos -= ((key == ARROW_RIGHT) - (key == ARROW_LEFT)) * MOVE_STEP;
	v->fdf.ypos += ((key == ARROW_UP) - (key == ARROW_DOWN)) * MOVE_STEP;
	v->fdf.scale += ((key == KB_I) - (key == KB_O)) * SIZE_STEP;
	v->fdf.amplitude += ((key == KB_U) - (key == KB_D)) * AMP_STEP;
	v->fdf.scale = ft_max(v->fdf.scale, 1);
	return (0);
}

int	on_keyup(int key, void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	if (key == KB_ESC)
		app_close (v, XC_EXIT);
	if (key == KB_SPC)
		v->fdf.projection = !v->fdf.projection;
	return (0);
}

int	on_render(void *vars)
{
	t_vars	*v;

	v = (t_vars *)(vars);
	ft_bzero (v->img.addr, (WIN_RESX * WIN_RESY) * (v->img.bpp / 8));
	draw_map(&v->img, v->fdf);
	draw_gui (&v->img);
	mlx_put_image_to_window (v->mlxo, v->mlx_win, v->img.o, 0, 0);
	gui_put_text (v);
	v->uptime++;
	return (0);
}
