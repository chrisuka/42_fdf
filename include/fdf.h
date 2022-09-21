/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:56:52 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/21 17:21:13 by ikarjala         ###   ########.fr       */
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
# include "keysym_macos.h"

# define BIN_NAME	"fdf"
# define WIN_TITLE	"FdF"
# define WIN_RESX	1080
# define WIN_RESY	740

# define XC_EXIT	0
# define XC_ERROR	1

# define SIG_CONT	0
# define SIG_EXIT	1

typedef struct	s_fdf_data {
	int		sig;
	int		map;
	void	*mlxo;
	void	*mlx_win;
}	t_fdf;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bppx;
	int		line_length;
	int		endian;
}	t_img;

typedef union	u_argb {
	int	hex : 32;
	struct s_palette {
		int	b : 8;
		int	g : 8;
		int	r : 8;
		int	a : 8;
	}	col;
}	t_argb;

int	parse_map_file(char *fname);

static inline int	argb2hex (int a, int r, int g, int b)
{
	return (b |
			g << (__CHAR_BIT__ * 1) |
			r << (__CHAR_BIT__ * 2) |
			a << (__CHAR_BIT__ * 3));
}


#endif
