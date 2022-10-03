/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:56:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/03 21:20:34 by ikarjala         ###   ########.fr       */
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

# define MOVE_STEP	30
# define SIZE_STEP	5
# define AMP_STEP	0.25f

typedef struct	s_fdf_data {
	int	**map;
	int	w;
	int	h;
	int	xpos;
	int	ypos;
	float	amplitude;
	int	scale;
	int	projection;
}	t_fdf;

typedef struct	s_img_data {
	void	*o;
	char	*addr;
	int		bpp;
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

typedef struct	s_vector2int
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct	s_line {
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}	t_line;
typedef struct s_line	t_rect;

/*/ Parser /////////////*/

t_fdf	parse_map_file(char *fname);

/*/ App Control ////////*/

int	app_update (void *vars);
int	handle_keyhook (int keycode, void *vars);

/*/ Draw ///////////////*/

void	set_pixel(t_img *img, int x, int y, unsigned int color);
void	draw_line(t_img *img, t_line ln);
void	draw_rect(t_img *img, t_rect r, int anchor, unsigned int color);
void	db_draw_unitcircle(t_img *img, int x, int y, int radius);

void	draw_map(t_img *img, t_fdf fdf);

/*/ Projection /////////*/

t_vec2i	project_point(int x, int y, t_fdf fdf);

/*/ GUI ////////////////*/

/*/ COLOR //////////////*/

unsigned int	rgba_hex(int r, int g, int b, int a);
unsigned int	hsv_hex(float h, float s, float v);

void	gui_put_text(t_vars *v);
void	draw_gui(t_img *img);

#endif
