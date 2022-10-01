/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:54 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 16:17:17 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define GUI_EDGE_OFFSET		10

#define GUI_ANCHOR_CENTER	0
#define GUI_ANCHOR_TOP_L	1
#define GUI_ANCHOR_TOP_R	2
#define GUI_ANCHOR_BOT_R	3
#define GUI_ANCHOR_BOT_L	4

static inline t_rect2d	box_identity(void)
{
	t_rect2d	r;
	
	r.x0 = GUI_EDGE_OFFSET;
	r.y0 = GUI_EDGE_OFFSET;
	r.x1 = 100;
	r.y1 = WIN_RESY - GUI_EDGE_OFFSET;
	r.color = 0x00202020;
	return (r);
}

void	draw_tooltip(t_img *img, int full)
{
	//const char	tip_h[] = "Press [h] to toggle info";
	t_rect2d	r;

	full = 1;//DEBUG
	r = box_identity();
	draw_rect (img, r, GUI_ANCHOR_TOP_L);
	//mlx_string_put (v->mlxo, v->mlx_win, 10, 10, 0x00FFFFFF, timestr);
}
