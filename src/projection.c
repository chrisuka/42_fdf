/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:21:15 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/03 19:49:00 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vec2i	project_parallel(int x, int y, t_fdf fdf)
{
	int	ox = WIN_RESX / 2 - (fdf.w / 2 * fdf.scale);
	int	oy = WIN_RESY / 2 - (fdf.h / 2 * fdf.scale);

	return ((t_vec2i){
		ox + x * fdf.scale * 2 + (fdf.xpos),
		oy + y * fdf.scale * 2 + (fdf.ypos)
	});
}

static t_vec2i	project_isometric(int x, int y, t_fdf fdf)
{
	int	ox = WIN_RESX / 2 - (fdf.w / 2) * fdf.scale;
	int	oy = WIN_RESY / 2 - (fdf.h / 2) * fdf.scale;

	return ((t_vec2i){
		ox + (x - y) * fdf.scale * 2 + (fdf.xpos),
		oy + (y + x) * fdf.scale + (fdf.ypos)
		- (int)(fdf.amplitude * fdf.map[x][y] * fdf.scale)
	});
}

t_vec2i	project_point(int x, int y, t_fdf fdf)
{
	if (fdf.projection == 1)
		return (project_isometric(x, y, fdf));
	return (project_parallel(x, y, fdf));
}
