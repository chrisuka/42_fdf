/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:55:03 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/21 17:57:34 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	print_usage(void)
{
	const char	msg[] = "usage:  " BIN_NAME " <map_file.fdf>\n";

	write (2, msg, sizeof(msg) - 1);
	return (XC_ERROR);
}

static void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*px;
	
	px = img->addr + (y * img->line_length + x * (img->bppx / __CHAR_BIT__));
	*(unsigned int *)(px) = color;
}

static int	app_close(int keycode, void *vars)
{
	t_fdf	*fdf;

	if (keycode != KB_ESC)
		return (0);
	fdf = (t_fdf *)(vars);
	fdf->sig = SIG_EXIT;
	mlx_destroy_window(fdf->mlxo, fdf->mlx_win);
	return (XC_EXIT);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_img	img;

	if (argc != 2)
		return (print_usage());
	fdf.map = parse_map_file(argv[1]);

	fdf.mlxo = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlxo, WIN_RESX, WIN_RESY, WIN_TITLE);
	img.img = mlx_new_image(fdf.mlxo, WIN_RESX, WIN_RESY);
	img.addr = mlx_get_data_addr(img.img, &img.bppx,
			&img.line_length, &img.endian);

	fdf.sig = SIG_CONT;
	for (int x = 0; x < WIN_RESX; x++)
		for (int y = 0; y < WIN_RESY; y++)
			set_pixel(&img, x, y, argb2hex(0, x, y, 0) );
	
	mlx_put_image_to_window(fdf.mlxo, fdf.mlx_win, img.img, 0, 0);

	mlx_key_hook(fdf.mlx_win, &app_close, &fdf);
	//mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
	mlx_loop(fdf.mlxo);

	return (0);
}
