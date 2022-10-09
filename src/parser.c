/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 17:18:32 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	initialize_fdf_data(void)
{
	t_fdf	fdf;

	fdf.signal = SIG_CONT;
	fdf.map = NULL;
	fdf.w = 0;
	fdf.h = 0;
	fdf.xpos = 0;
	fdf.ypos = 0;
	fdf.amplitude = 0.15f;
	fdf.scale = 25;
	fdf.projection = 1;
	return (fdf);
}

static inline t_fdf	abort_parse(t_fdf *fdf, char *fname)
{
	fdf->signal = SIG_ERROR;
	perr_badmap (fname); // Internal error
	return (*fdf);
}

/* Read through the file once to count the lines and width of the first line
 * then re-open it and return the FD
*/
static inline int	first_pass(char *fname, int *width, int *rows)
{
	int		fd;
	int		wc;
	char	*line;

	line = NULL;
	fd = open (fname, O_RDONLY);
	while (get_next_line(fd, &line) != RET_EOF)
	{
		if (line == NULL)
			return (-1);
		wc = ft_wordcount(line, " ");
		ft_strdel (&line);
		if (wc < 2)
			return (-1);
		if (*width == 0)
			*width = wc;
		++ *rows;
	}
	ft_strdel (&line);
	close (fd);
	fd = open (fname, O_RDONLY);
	return (fd);
}

static int	parse_line(char *line, int y, int **map)
{
	char	**words;
	int		x;

	words = ft_strsplit (line, ' ');
	if (!words)
		return (-1);
	x = 0;
	while (words[x] != NULL)
		++ x;
	map[y] = (int *)ft_memalloc(sizeof(int) * x);
	x = -1;
	if (map[y] != NULL)
	{
		while (words[++x] != NULL)
			map[y][x] = ft_atoi(words[x]);
	}
	ft_freearray ((void **)(&words), x);
	return (x);
}

t_fdf	parse_map_file(char *fname)
{
	t_fdf	fdf;
	char	*line;
	int		fd;
	int		y;

	fdf = initialize_fdf_data();
	fd = first_pass (fname, &fdf.w, &fdf.h);
	if (fd < 0 || fdf.w < 2 || fdf.h < 2)
		return (abort_parse(&fdf, fname));
	fdf.map = (int **)ft_memalloc(sizeof(int *) * fdf.h);
	line = NULL;
	y = 0;
	while (get_next_line(fd, &line) != RET_EOF)
	{
		if (parse_line (line, y++, fdf.map) != fdf.w)
		{
			ft_strdel (&line);
			return (abort_parse(&fdf, fname));
		}
		ft_strdel (&line);
	}
	ft_strdel (&line);
	return (fdf);
}
