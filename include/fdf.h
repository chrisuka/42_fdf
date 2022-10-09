/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:56:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 18:19:41 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

# define BIN_NAME	"fdf"
# define WIN_TITLE	"FdF"
# define WIN_RESX	1080
# define WIN_RESY	740

# ifndef CLI_COLORS
#  define CLI_COLORS
#  define CGREEN	"\033[0;33m"
#  define CYELLOW	"\033[0;32m"
#  define CRED		"\033[0;31m"
#  define CGREENB	"\033[1;33m"
#  define CYELLOWB	"\033[1;32m"
#  define CREDB		"\033[1;31m"
#  define CNIL		"\033[0;0m"
# endif

# define XC_EXIT	0
# define XC_ERROR	1

# define ECONTINUE	0
# define EEXIT		1
# define EPARSE		2
# define EINTERNAL	3

# define MOVE_STEP	30
# define SIZE_STEP	5
# define AMP_STEP	0.25f

typedef struct s_fdf_mapdata {
	char	*fname;
	int		**map;
	int		w;
	int		h;
	int		xpos;
	int		ypos;
	float	amplitude;
	int		scale;
	int		projection;
	int		eparse;
}	t_fdf;

typedef struct s_img_data {
	void	*o;
	char	*addr;
	int		bpp;
	int		width;
	int		endian;
}	t_img;

typedef struct s_vars_data_container {
	size_t	uptime;
	int		sig;
	void	*mlxo;
	void	*mlx_win;

	t_fdf	fdf;
	t_img	img;
}	t_vars;

typedef struct s_vector2int
{
	int	x;
	int	y;
}	t_v2d;

typedef struct s_line {
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}	t_line;
typedef struct s_line	t_rect;

/*/ Parser /////////////*/

t_fdf	parse_map_file(char *fname);

/*/ App Control ////////*/

int		on_keydown(int key, void *vars);
int		on_render(void *vars);
int		on_keyup(int keycode, void *vars);
void	app_close(t_vars *v, int code);

/*/ Draw Manager ///////*/

void	draw_map(t_img *img, t_fdf fdf);

/*/ Draw Utilities /////*/

void	set_pixel(t_img *img, int x, int y, unsigned int color);
void	draw_line(t_img *img, t_line ln);
void	draw_rect(t_img *img, t_rect r, int anchor, unsigned int color);

/*/ Projection /////////*/

t_v2d	project_point(int x, int y, t_fdf fdf);

/*/ GUI ////////////////*/

void	gui_put_text(t_vars *v);
void	draw_gui(t_img *img);

/*/ Error //////////////*/

int		perr_badmap(char *fname);

#endif
