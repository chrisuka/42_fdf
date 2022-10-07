/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:55:03 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/07 15:06:26 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keysym_macos.h"

static inline int	print_usage(void)
{
	const char	msg[] = "usage:  " BIN_NAME " <map_file.fdf>\n";

	write (2, msg, sizeof(msg) - 1);
	return (XC_ERROR);
}

#if 0
static void	print_map(int **map, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			ft_putnbr (map[y][x]);
			ft_putchar (' ');
		}
		ft_putchar ('\n');
	}
}
#endif

int	main(int argc, char **argv)
{
	char	*wname;
	t_vars	v;

	if (argc != 2)
		return (print_usage());
	v.uptime = 0;
	v.fdf = parse_map_file(argv[1]);
	if (v.fdf.signal != SIG_CONT)
		app_close (&v, XC_ERROR);
	//else print_map(v.fdf.map, v.fdf.w, v.fdf.h); //DEBUG! GET RID OF THIS!

	v.mlxo = mlx_init();

	wname = ft_strjoin (WIN_TITLE " : ", argv[1]);
	v.mlx_win = mlx_new_window(v.mlxo, WIN_RESX, WIN_RESY, wname);
	ft_strdel (&wname);

	v.img.o = mlx_new_image(v.mlxo, WIN_RESX, WIN_RESY);
	v.img.addr = mlx_get_data_addr(v.img.o, &v.img.bpp,
			&v.img.width, &v.img.endian);

	mlx_hook(v.mlx_win, ON_KEYDOWN, XKMASK_KB, &on_keydown, &v);
	mlx_key_hook (v.mlx_win, &handle_keyhook, &v);
	mlx_loop_hook (v.mlxo, &app_update, &v);
	mlx_loop (v.mlxo);
	return (XC_EXIT);
}
