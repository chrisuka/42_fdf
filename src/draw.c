/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/23 19:58:25 by ikarjala         ###   ########.fr       */
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

	dx = ln.x1 - ln.x0;
	dy = 2 * (ln.y1 - ln.y0);
	dv = dy - (dx >> 1);
	while (dx)
	{
		dv -= dy;
		if (dv < 0)
		{
			ln.y0 ++;
			dv += 2 * dx;
		}
		set_pixel (img, ln.x0, ln.y0, ln.color);
		ln.x0 ++;
		dx --;
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
