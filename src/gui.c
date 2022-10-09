/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:54 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 21:52:44 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline t_rect	gui_tooltip_box(void)
{
	t_rect	r;

	r.x0 = GUI_MARGIN;
	r.y0 = GUI_MARGIN;
	r.x1 = 300;
	r.y1 = TEXT_ROWOFF * 16;
	return (r);
}

static inline t_v2d	gui_off(int x, int y)
{
	const int	o = GUI_MARGIN + 10;
	t_v2d		p;

	p.x = o + x;
	p.y = o + y * TEXT_ROWOFF;
	return (p);
}

static void	put_dynamic_text(t_vars *v, const char *s1, char **s2, t_v2d p)
{
	const int	ox = GUI_MARGIN + 10;
	const char	empty[] = "";
	char		*dystr;

	if (!*s2)
		*s2 = ft_strdup(empty);
	dystr = ft_strjoin(s1, *s2);
	mlx_string_put (v->mlxo, v->mlx_win, ox + p.x, p.y, TEXT_COLOR, dystr);
	ft_strdel(&dystr);
	ft_strdel(s2);
}

void	gui_put_text(t_vars *v)
{
	const int	ox = GUI_MARGIN + 10;
	const char	*texts[] = {"Controls",
		"--------",
		"esc: quit",
		"arrows: move camera",
		"i/o: zoom in/out",
		"u/d: amplitude up/down",
		"space: toggle projection"};
	const char	*mode_txt[] = {"[] Parallel", "<> Isometric"};
	char		*dystr;
	int			n;

	n = -1;
	while (++n < (int)(sizeof(texts) / sizeof(char *)))
		mlx_string_put (v->mlxo, v->mlx_win, ox,
			ox + n * TEXT_ROWOFF, TEXT_COLOR, (char *)(texts[n]));
	dystr = ft_itoa (v->frame);
	put_dynamic_text(v, "Frame: ", &dystr, gui_off(0, 10));
	put_dynamic_text(v, mode_txt[v->fdf.projection], &dystr, gui_off(0, 11));
	dystr = ft_itoa (v->fdf.w);
	put_dynamic_text(v, "w: ", &dystr, gui_off(160, 10));
	dystr = ft_itoa (v->fdf.h);
	put_dynamic_text(v, "h: ", &dystr, gui_off(160, 11));
	dystr = ft_itoa ((int)round(v->fdf.amplitude * 100.0f));
	put_dynamic_text(v, "amplitude: ", &dystr, gui_off(0, 13));
}

void	draw_gui(t_img *img)
{
	t_rect	r;

	r = gui_tooltip_box();
	draw_rect (img, r, GUI_ANCHOR_TOP_L, GUI_BG_COLOR);
}
