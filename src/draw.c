/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/27 16:34:16 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*px;
	
	px = img->addr + (y * img->width + x * (img->bppx / __CHAR_BIT__));
	*(unsigned int *)(px) = color;
}

/* Draw a colored line specified by ln using the DDA
 * (Digital Differential Analyzer) algorithm:
 * determine the number of steps as the larger of delta x and delta y
 *
 * dx / steps and dy / steps will be their respective increment values
 * each step, increment xy and round to int to find the next pixel
*/
//typedef void (*draw_line)(t_img *, t_line)
void	draw_line(t_img *img, t_line ln)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		steps;
	
	dx = (double)(ln.x1 - ln.x0);
	dy = (double)(ln.y1 - ln.y0);
	steps = (int)fmax(fabs(dx), fabs(dy));
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
void	db_draw_unitcircle(t_img *img, int x, int y, int radius)
{
	const float		d2r = M_PI / 180;
	const float		astep = 2.5f * d2r;
	float			angle;
	int				steps;
	t_line			ln;
	t_rect2d		r;
	unsigned int	color;
	
	angle = 0.0f;
	steps = (int)round((2 * M_PI) / astep);
	ln = (t_line){x, y, 0, 0, 0};
	r = (t_rect2d){x, y, 5, 5, 0x00FFFFFF};
	//draw_square (img, x, y, 5, 0x00FFFFFF);
	draw_square (img, r, 0);
	while (steps--)
	{
		color = argb2hex(0, rand() % 255, rand() % 255, rand() % 255);
		ln.color = color;
		ln.x1 = (int)round(x + sin(angle) * radius);
		ln.y1 = (int)round(y + cos(angle) * radius);
		r = (t_rect2d){ln.x1, ln.y1, 8, 8, color};
		draw_square (img, r, 0);
		draw_line (img, ln);
		angle += astep;
	}
}

void	draw_square(t_img *img, t_rect2d r, int anchor)
{
	// center, topl, topr, botr, botl
	const int	offsets[][2] = {{-1,-1}, {0,0}, {-2,0}, {-2,-2}, {0,-2}};
	int	xn;
	int	yn;

	r.x0 += offsets[anchor][0] * (r.x1 / 2);
	r.y0 += offsets[anchor][1] * (r.y1 / 2);
	if (r.x0 < 0 || r.x0 + r.x1 >= WIN_RESX ||
		r.y0 < 0 || r.y0 + r.y1 >= WIN_RESY)
		return ;
	xn = 0;
	while (xn <= r.x1)
	{
		yn = 0;
		while (yn <= r.y1)
			set_pixel (img, r.x0 + xn, r.y0 + yn++, r.color);
		xn ++;
	}
}
# endif
