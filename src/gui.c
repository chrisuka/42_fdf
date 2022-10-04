/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:54 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/03 22:30:15 by ikarjala         ###   ########.fr       */
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
#define TEXT_COLOR			0x00BB80FF

static inline t_rect	gui_tooltip_box(void)
{
	t_rect	r;
	
	r.x0 = GUI_MARGIN;
	r.y0 = GUI_MARGIN;
	r.x1 = 300;
	r.y1 = TEXT_ROWOFF * 14;
	return (r);
}

void	gui_put_text(t_vars *v)
{
	//const char	tip_h[] = "Press [h] to show info";
	const int	o = GUI_MARGIN + 10;
	const char	*texts[] = {//"Press [h] to hide info",
			"Controls",
			"--------",
			"esc: quit",
			"arrows: move camera",
			"i/o: zoom in/out",
			"u/d: amplitude up/down",
			"space: toggle projection"};
	const char	*mode_txt[] = {"[] Parallel", "<> Isometric"};
	char		*dystr1;
	char		*dystr2;
	int	n;

	n = -1;
	while (++n < (int)(sizeof(texts) / sizeof(char *)))
		mlx_string_put (v->mlxo, v->mlx_win, o,
			o + n * TEXT_ROWOFF, TEXT_COLOR, (char *)(texts[n]));

	dystr1 = ft_itoa (v->uptime);
	dystr2 = ft_strjoin ("Frame: ", dystr1);
	mlx_string_put (v->mlxo, v->mlx_win, o, o + 10 * TEXT_ROWOFF, TEXT_COLOR, dystr2);
	mlx_string_put (v->mlxo, v->mlx_win, o, o + 11 * TEXT_ROWOFF, TEXT_COLOR, (char *)mode_txt[v->fdf.projection]);
	ft_strdel (&dystr1);
	ft_strdel (&dystr2);
}

void	draw_gui(t_img *img)
{
	t_rect	r;

	r = gui_tooltip_box();
	draw_rect (img, r, GUI_ANCHOR_TOP_L, 0x00101010);
}
