/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:54 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 19:58:05 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define GUI_MARGIN	10

#define GUI_ANCHOR_CENTER	0
#define GUI_ANCHOR_TOP_L	1
#define GUI_ANCHOR_TOP_R	2
#define GUI_ANCHOR_BOT_R	3
#define GUI_ANCHOR_BOT_L	4

#define TEXT_ROWOFF			15
#define TEXT_COLOR			0x00FFFFFF

static inline t_rect2d	box_identity(void)
{
	t_rect2d	r;
	
	r.x0 = GUI_MARGIN;
	r.y0 = GUI_MARGIN;
	r.x1 = 300;
	r.y1 = 200;
	r.color = 0x00202020;
	return (r);
}

void	gui_put_text(t_vars *v)
{
	//const char	tip_h[] = "Press [h] to show info";
	const char	*texts[] = {"Press [h] to hide info",
			"Frame: "};
	char		*dystr1;
	char		*dystr2;
	int	y;

	y = GUI_MARGIN + 10;
	mlx_string_put (v->mlxo, v->mlx_win, GUI_MARGIN + 10, y, TEXT_COLOR, (char *)texts[0]);
	y += TEXT_ROWOFF;
	dystr1 = ft_itoa (v->uptime);
	dystr2 = ft_strjoin (texts[1], dystr1);
	mlx_string_put (v->mlxo, v->mlx_win, GUI_MARGIN + 10, y, TEXT_COLOR, dystr2);
	ft_strdel (&dystr1);
	ft_strdel (&dystr2);
}

void	draw_gui(t_img *img)
{
	t_rect2d	r;

	r = box_identity();
	draw_rect (img, r, GUI_ANCHOR_TOP_L);
}
