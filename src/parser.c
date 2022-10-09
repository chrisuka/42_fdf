/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 20:02:30 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline t_fdf	initialize_mapdata(char *fname)
{
	t_fdf	fdf;

	fdf.fname = fname;
	fdf.map = NULL;
	fdf.w = 0;
	fdf.h = 0;
	fdf.xpos = 0;
	fdf.ypos = 0;
	fdf.amplitude = 0.15f;
	fdf.scale = 25;
	fdf.projection = 1;
	fdf.eparse = ECONTINUE;
	return (fdf);
}

static inline t_fdf	abort_parse(t_fdf *fdf, int code)
{
	fdf->eparse = code;
	perr_badmap (fdf->fname);
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
	int		y;

	line = NULL;
	fd = open (fname, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) != RET_EOF)
	{
		if (line == NULL)
			return (-1);
		wc = ft_wordcount(line, " ");
		ft_strdel (&line);
		if (wc < 2)
			return (-1);
		if (y == 0)
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

	fdf = initialize_mapdata(fname);
	fd = first_pass (fname, &fdf.w, &fdf.h);
	if (fd < 0 || fdf.w < 2 || fdf.h < 2 || fdf.eparse != ECONTINUE)
		return (abort_parse(&fdf, EPARSE));
	fdf.map = (int **)ft_memalloc(sizeof(int *) * fdf.h);
	line = NULL;
	y = 0;
	while (get_next_line(fd, &line) != RET_EOF)
	{
		if (parse_line (line, y++, fdf.map) != fdf.w)
		{
			ft_strdel (&line);
			return (abort_parse(&fdf, EPARSE));
		}
		ft_strdel (&line);
	}
	ft_strdel (&line);
	return (fdf);
}
