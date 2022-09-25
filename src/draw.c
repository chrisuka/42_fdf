/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/25 14:25:57 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*px;
	
	px = img->addr + (y * img->width + x * (img->bppx / __CHAR_BIT__));
	*(unsigned int *)(px) = color;
}

/* Bresenham's line algorithm
 * use ratio of y delta / x delta as the y increment as we iterate x0 -> x1
 * fraction = (y1 - y0) / (x1 - x0)
 * if fraction is over 0.5, y + 1
 * this can be simplified: (y1 - y0) / (x1 - x0) * 2 * (x1 - x0)
 * => 2 * (y1 - y0)
*/
void	draw_line(t_img *img, t_line ln)
{
	int	dx;
	int	dy;
	int	dv;

	dx = (ln.x1 - ln.x0);
	dy = (ln.y1 - ln.y0) * 2;
	if (dx > dy)
	{
		dx ^= dy;
		dy ^= dx;
		dx ^= dy;
	}
	dv = dx - dy;
	while (ln.x0 < ln.x1)
	{
		dv -= dy;
		if (dv < 0)
		{
			ln.y0 ++;
			dv += 2 * dx;
		}
		set_pixel (img, ln.x0, ln.y0, ln.color);
		ln.x0 ++;
	}
}

# define UNIT_TESTS 1
# if UNIT_TESTS == 1
void	draw_umbrella(t_img *img, int x, int y, int radius)
{
	const float		d2r = M_PI / 180;
	const float		astep = 5.0f * d2r;
	float			angle;
	int				steps;
	t_line			ln;
	unsigned int	color;
	
	angle = 0.0f;
	steps = (int)round((2 * M_PI) / astep);
	ln = (t_line){x, y, 0, 0, 0};
	draw_square (img, x, y, 5, 0x00FFFFFF);
	while (steps--)
	{
		color = argb2hex(0, rand() % 255, rand() % 255, rand() % 255);
		ln.color = color;
		ln.x1 = (int)round(x + sin(angle) * radius);
		ln.y1 = (int)round(y + cos(angle) * radius);
		draw_square (img, ln.x1, ln.y1, 5, color);
		draw_line (img, ln);
		angle += astep;
	}
}

void	draw_square(t_img *img, int x, int y, int size, unsigned int color)
{
	int	offx;
	int	offy;

	x -= (size >> 1) + 1;
	y -= (size >> 1) + 1;
	offx = x + size;
	offy = y + size;
	while (++x < offx)
	{
		y = offy - size;
		while (++y < offy)
		{
			if (x >= 0 && x < offx &&
				y >= 0 && y < offy)
				set_pixel (img, x, y, color);
		}
	}
}
# endif
