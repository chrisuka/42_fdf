/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:54 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/08 18:19:13 by ikarjala         ###   ########.fr       */
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
	r.y1 = TEXT_ROWOFF * 16;
	return (r);
}

static inline int	gui_off(int row)
{
	const int	o = GUI_MARGIN + 10;

	return (o + row * TEXT_ROWOFF);
}

static void	put_dynamic_text(t_vars *v, const char *s1, char **s2, int x, int y)
{
	const int	ox = GUI_MARGIN + 10;
	const char	empty[] = "";
	char		*dystr;

	if (!*s2)
		*s2 = ft_strdup(empty);
	dystr = ft_strjoin(s1, *s2);
	mlx_string_put (v->mlxo, v->mlx_win, ox + x, gui_off(y), TEXT_COLOR, dystr);
	ft_strdel(&dystr);
	ft_strdel(s2);
}

void	gui_put_text(t_vars *v)
{
	const int	ox = GUI_MARGIN + 10;
	const char	*texts[] = {
			"Controls",
			"--------",
			"esc: quit",
			"arrows: move camera",
			"i/o: zoom in/out",
			"u/d: amplitude up/down",
			"space: toggle projection"};
	const char	*mode_txt[] = {"[] Parallel", "<> Isometric"};
	char		*dystr;
	int	n;

	n = -1;
	while (++n < (int)(sizeof(texts) / sizeof(char *)))
		mlx_string_put (v->mlxo, v->mlx_win, ox,
			ox+ n * TEXT_ROWOFF, TEXT_COLOR, (char *)(texts[n]));
	dystr = ft_itoa (v->uptime);
	put_dynamic_text(v, "Frame: ", &dystr, 0, 10);
	put_dynamic_text(v, mode_txt[v->fdf.projection], &dystr, 0, 11);
	dystr = ft_itoa (v->fdf.w);
	put_dynamic_text(v, "w: ", &dystr, 160, 10);
	dystr = ft_itoa (v->fdf.h);
	put_dynamic_text(v, "h: ", &dystr, 160, 11);
	dystr = ft_itoa ((int)round(v->fdf.amplitude * 100.0f));
	put_dynamic_text(v, "amplitude: ", &dystr, 0, 13);
}

void	draw_gui(t_img *img)
{
	t_rect	r;

	r = gui_tooltip_box();
	draw_rect (img, r, GUI_ANCHOR_TOP_L, 0x00101010);
}
