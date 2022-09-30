/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:21:15 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/30 22:31:11 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if 0
/* top-down */
static t_vec2i	project_parallel(int x, int y, t_fdf fdf)
{
	const int	ox = WIN_RESX / 2 - ((10 * 50) / 2);
	const int	oy = WIN_RESY / 2 - ((7  * 50) / 2);

	return ((t_vec2i){
			ox + x * fdf.scale,
			oy + y * fdf.scale
			});
}

#else
//static t_vec2i	project_isometric(int x, int y, t_fdf fdf)
static t_vec2i	project_parallel(int x, int y, t_fdf fdf)
{
	const int	ox = WIN_RESX / 2;
	const int	oy = WIN_RESY / 2 - ((7 * 50) / 2);

	fdf.scale >>= 1;
	return ((t_vec2i){
			ox + (x - y) * 2 * fdf.scale,
			oy + (y + x) * fdf.scale
			- fdf.amplitude * fdf.map[x][y]
			});
}

#endif

t_vec2i	project_point(int x, int y, t_fdf fdf)
{
	return (project_parallel(x, y, fdf));
}

