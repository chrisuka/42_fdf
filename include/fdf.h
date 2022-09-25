/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:56:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/25 13:39:52 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define BIN_NAME	"fdf"
# define WIN_TITLE	"FdF"
# define WIN_RESX	1080
# define WIN_RESY	740

# define XC_EXIT	0
# define XC_ERROR	1

# define SIG_CONT	0
# define SIG_EXIT	1

typedef struct	s_fdf_data {
	int	map;
}	t_fdf;

typedef struct	s_img_data {
	void	*o;
	char	*addr;
	int		bppx;
	int		width;
	int		endian;
}	t_img;

typedef struct	s_fdf_data_container {
	size_t	uptime;
	int		sig;
	void	*mlxo;
	void	*mlx_win;

	t_fdf	fdf;
	t_img	img;
}	t_vars;

typedef union	u_argb {
	int	hex : 32;
	struct s_palette {
		int	b : 8;
		int	g : 8;
		int	r : 8;
		int	a : 8;
	}	col;
}	t_argb;

typedef struct	s_line {
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	unsigned int	color;
}	t_line;

/*/ Parser /////////////*/

int	parse_map_file(char *fname);

/*/ App Control ////////*/

int	app_update (void *vars);
int	handle_keyhook (int keycode, void *vars);

/*/ Draw  //////////////*/

void	set_pixel(t_img *img, int x, int y, unsigned int color);
void	draw_line(t_img *img, t_line ln);
void	draw_square(t_img *img, int x, int y, int size, unsigned int color);
void	draw_umbrella(t_img *img, int x, int y, int radius);

static inline int	argb2hex (int a, int r, int g, int b)
{
	return (a << (__CHAR_BIT__ * 3) |
			r << (__CHAR_BIT__ * 2) |
			g << (__CHAR_BIT__ * 1) |
			b);
}

#endif
