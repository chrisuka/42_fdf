/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:14:17 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/05 23:08:40 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	line_init(t_vec2i p0, t_vec2i p1)
{
	t_line	ln;
	
	ln.x0 = p0.x;
	ln.y0 = p0.y;
	ln.x1 = p1.x;
	ln.y1 = p1.y;
	return (ln);
}

static inline void	draw_horizontal(t_img *img, int x, int y, t_fdf fdf)
{
	draw_line(img, line_init(
		project_point (x + 0, y, fdf),
		project_point (x + 1, y, fdf)));
}

static inline void	draw_vertical(t_img *img, int x, int y, t_fdf fdf)
{
	draw_line(img, line_init(
		project_point (x, y + 0, fdf),
		project_point (x, y + 1, fdf)));
}

void	draw_map(t_img *img, t_fdf fdf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < fdf.w - 1)
	{
		y = -1;
		while (++y < fdf.h - 1)
		{
			draw_horizontal (img, x, y, fdf);
			draw_vertical (img, x, y, fdf);
		}
	}
	x = fdf.w - 1;
	y = -1;
	while (++y < fdf.h - 1)
		draw_vertical (img, x, y, fdf);
	y = fdf.h - 1;
	x = -1;
	while (++x < fdf.w - 1)
		draw_horizontal (img, x, y, fdf);
}
