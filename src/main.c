/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:55:03 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/21 21:27:35 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	print_usage(void)
{
	const char	msg[] = "usage:  " BIN_NAME " <map_file.fdf>\n";

	write (2, msg, sizeof(msg) - 1);
	return (XC_ERROR);
}

int	main(int argc, char **argv)
{
	//char	wname_buf[10];
	t_vars	v;

	if (argc != 2)
		return (print_usage());
	v.fdf.map = parse_map_file(argv[1]);
	v.sig = SIG_CONT;

	v.mlxo = mlx_init();
	v.mlx_win = mlx_new_window(v.mlxo, WIN_RESX, WIN_RESY, WIN_TITLE);
	v.img.o = mlx_new_image(v.mlxo, WIN_RESX, WIN_RESY);
	v.img.addr = mlx_get_data_addr(v.img.o, &v.img.bppx,
			&v.img.width, &v.img.endian);

	mlx_key_hook (v.mlx_win, &handle_keyhook, &v);
	mlx_loop_hook (v.mlxo, &app_update, &v);
	mlx_loop (v.mlxo);
	return (XC_EXIT);
}
