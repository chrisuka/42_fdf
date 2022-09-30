/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/30 22:32:45 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	inside_frame(int x, int y)
{
	return (x >= 0 && x < WIN_RESX &&
			y >= 0 && y < WIN_RESY);
}

void	set_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*px;
	
	px = img->addr + (y * img->width + x * (img->bppx / __CHAR_BIT__));
	*(unsigned int *)(px) = color;
}

void	draw_map(t_img *img, t_fdf fdf)
{
	t_vec2i	ps[2];
	t_vec2i	zero;
	t_line	ln;
	int	x;
	int	y;

	x = 0;
	while (++x < fdf.w)
	{
		y = 0;
		while (++y < fdf.h)
		{
			zero = project_point (x - 1, y - 1, fdf);
			ps[0] = zero;
			ps[1] = project_point (x, y - 1, fdf);
			ln = (t_line){ps[0].x, ps[0].y, ps[1].x, ps[1].y, 0x00FF00FF};
			draw_line(img, ln);
			// R D
			ps[0] = ps[1];
			ps[1] = project_point (x, y, fdf);
			ln = (t_line){ps[0].x, ps[0].y, ps[1].x, ps[1].y, 0x00FF00FF};
			draw_line(img, ln);
			// D L
			ps[0] = ps[1];
			ps[1] = project_point (x - 1, y, fdf);
			ln = (t_line){ps[0].x, ps[0].y, ps[1].x, ps[1].y, 0x00FF00FF};
			draw_line(img, ln);
			// L U
			ps[0] = zero;
			ln = (t_line){ps[0].x, ps[0].y, ps[1].x, ps[1].y, 0x00FF00FF};
			draw_line(img, ln);
		}
	}

}

/* Draw a colored line specified by ln using the DDA
 * (Digital Differential Analyzer) algorithm:
 * determine the number of steps as the larger of delta x and delta y
 *
 * dx / steps and dy / steps will be their respective increment values
 * each step, increment xy and round to int to find the next pixel
*/
void	draw_line(t_img *img, t_line ln)
{
	double	x;
	double	y;
	double	dx;
	double	dy;
	int		steps;
	
	if (!inside_frame(ln.x0, ln.y0) || !inside_frame(ln.x1, ln.y1))
		return ;
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

# if 0 // SAVE THIS !!!!
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
	draw_rect (img, r, 0);
	while (steps--)
	{
		color = argb2hex(0, rand() % 255, rand() % 255, rand() % 255);
		ln.color = color;
		ln.x1 = (int)round(x + sin(angle) * radius);
		ln.y1 = (int)round(y + cos(angle) * radius);
		r = (t_rect2d){ln.x1, ln.y1, 8, 8, color};
		draw_rect (img, r, 0);
		draw_line (img, ln);
		angle += astep;
	}
}
# endif

/* Draw a colored rect from origin x0,y0 with size x1,y1
 * offset by the direction specified by the anchor index:
 * 0:center, 1:topleft, 2:topright, 3:bottomright, 4:bottomleft
*/
void	draw_rect(t_img *img, t_rect2d r, int anchor)
{
	const int	offsets[][2] = {{-1,-1}, {0,0}, {-2,0}, {-2,-2}, {0,-2}};
	int	xn;
	int	yn;

	r.x0 += offsets[anchor][0] * (r.x1 / 2);
	r.y0 += offsets[anchor][1] * (r.y1 / 2);
	if (!inside_frame(r.x0, r.y0) && !inside_frame(r.x1, r.y1))
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
