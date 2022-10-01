/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:21:15 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 18:22:21 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* top-down */
static t_vec2i	project_parallel(int x, int y, t_fdf fdf)
{
	const int	ox = WIN_RESX / 2 - ((10 * 50) / 2);
	const int	oy = WIN_RESY / 2 - ((7  * 50) / 2);

	return ((t_vec2i){
			ox + x * fdf.scale + (fdf.xpos),
			oy + y * fdf.scale + (fdf.ypos)
			});
}

static t_vec2i	project_isometric(int x, int y, t_fdf fdf)
{
	const int	ox = WIN_RESX / 2;
	const int	oy = WIN_RESY / 2 - ((7 * 50) / 2);

	fdf.scale >>= 1;
	return ((t_vec2i){
			ox + (x - y) * 2 * fdf.scale + (fdf.xpos),
			oy + (y + x) * fdf.scale + (fdf.ypos)
			- fdf.amplitude * fdf.map[x][y]
			});
}

t_vec2i	project_point(int x, int y, t_fdf fdf)
{
	if (fdf.projection == 1)
		return (project_isometric(x, y, fdf));
	return (project_parallel(x, y, fdf));
}

