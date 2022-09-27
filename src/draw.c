/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/27 14:42:40 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*px;
	
	if (x < 0 || x >= WIN_RESX ||
		y < 0 || y >= WIN_RESY)
		return ;
	px = img->addr + (y * img->width + x * (img->bppx / __CHAR_BIT__));
	*(unsigned int *)(px) = color;
}

/* Draw a colored line specified by ln using the DDA
 * (Digital Differential Analyzer) algorithm:
 * determine the number of steps as the larger of delta x and delta y
 *
 * dx / steps and dy / steps will be their respective increment values
 * each step, increment them and round to int to find the current pixel
*/
void	draw_line(t_img *img, t_line ln)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	int		steps;
	
	dx = (double)(ln.x1 - ln.x0);
	dy = (double)(ln.y1 - ln.y0);
	steps = fmax(fabs(dx), fabs(dy));
	dx /= steps;
	dy /= steps;
	x = (double)(ln.x0);
	y = (double)(ln.y0);
	while (steps--)
	{
		set_pixel (img, (int)(x), (int)(y), ln.color);
		x += dx;
		y += dy;
	}
}

# define UNIT_TESTS 1
# if UNIT_TESTS == 1
void	draw_umbrella(t_img *img, int x, int y, int radius)
{
	const float		d2r = M_PI / 180;
	const float		astep = 2.5f * d2r;
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
