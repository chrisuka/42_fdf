/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:21:15 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 17:31:20 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_v2d	project_parallel(int x, int y, t_fdf fdf)
{
	int	ox;
	int	oy;

	ox = WIN_RESX / 2 - fdf.w * fdf.scale / 2;
	oy = WIN_RESY / 2 - fdf.h * fdf.scale / 2;
	return ((t_v2d){
		ox + x * fdf.scale * 2 + (fdf.xpos),
		oy + y * fdf.scale * 2 + (fdf.ypos)
	});
}

static t_v2d	project_isometric(int x, int y, t_fdf fdf)
{
	int	ox;
	int	oy;

	ox = WIN_RESX / 2 - fdf.w * fdf.scale / 2;
	oy = WIN_RESY / 2 - fdf.h * fdf.scale / 2;
	return ((t_v2d){
		ox + (x - y) * fdf.scale * 2 + (fdf.xpos),
		oy + (y + x) * fdf.scale + (fdf.ypos)
		- (int)(fdf.amplitude * fdf.map[y][x] * fdf.scale)
	});
}

t_v2d	project_point(int x, int y, t_fdf fdf)
{
	if (fdf.projection == 1)
		return (project_isometric(x, y, fdf));
	return (project_parallel(x, y, fdf));
}
