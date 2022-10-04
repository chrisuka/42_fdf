/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/04 18:47:31 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	initialize_fdf_data(void)
{
	t_fdf	fdf;

	fdf.map = NULL; // REMEMBER ME....
	fdf.w = 0;
	fdf.h = 0;
	fdf.xpos = 0;
	fdf.ypos = 0;
	//fdf.amplitude = 0.25f;
	fdf.amplitude = 0.15f;
	fdf.scale = 25;
	fdf.projection = 1;
	return (fdf);
}

#if 0

static int	read_height(char *fname, int *lines)
{
	int		fd;
	char	buf[BUFF_SIZE];
	ssize_t	bs;

	fd = open (fname, O_RDONLY);
	bs = 1;
	while (bs)
	{
		bs = read (fd, buf, BUFF_SIZE);
		if (bs < 0)
			return (-1);
		*lines += (ft_memchr(buf, '\n', bs) != NULL);
	}
	close (fd);
	fd = open (fname, O_RDONLY);
	return (fd);
}

static int	parse_line(char *line, int y)
{
	t_list	*wl;
	t_list	*node;
	int		x;

	wl = ft_wordlist (line, " ", get_lrinfo().len);
	x = 0;
	node = wl;
	while (node != NULL)
	{
		// first, scan for illegal characters, return error (OPTIONAL)
		map[x][y] = ft_atoi(node->content);
		++ x;
		node = node->next;
		free (wl);
		wl = node;
	}
	return (x);
}

t_fdf	parse_map_file(char *fname)
{
	t_fdf	fdf;
	int		y;
	
	fdf = initialize_fdf_data();
	fd = read_height (fname, &fdf.h);
	if (fd < 0)
		return (-1); // return type is FDF so tick a SIG_ERROR flag instead!
	fdf.map = (int **)malloc(sizeof(int *) * fdf.h);
	y = 0;
	while (get_next_line(fd, &line) != RET_EOF)
	{
		fdf.map[y] = (int *)malloc(sizeof(int) * fdf.w);
		if (parse_line (line, y++) != fdf.w)
			return (-1);
	}
	return (fdf);
}

#else
t_fdf	parse_map_file(char *fname)
{
	const int	w = 10;
	const int	h = 7;
	const int	map[h][w] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 {0,10, 0,10, 0, 0,10,10,10, 0},
							 {0,10, 0,10, 0, 0, 0, 0,10, 0},
							 {0,10,10,10, 0, 0,10,10,10, 0},
							 {0, 0, 0,10, 0, 0,10, 0, 0, 0},
							 {0, 0, 0,10, 0, 0,10,10,10, 0},
							 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	t_fdf		fdf;

	fname = NULL;
	fdf = initialize_fdf_data();
	fdf.w = w;
	fdf.h = h;
	fdf.map = (int **)malloc(sizeof(int *) * w);
	for (int x = 0; x < w; x++)
	{
		fdf.map[x] = (int *)malloc(sizeof(int) * h);
		for (int y = 0; y < h; y++)
			fdf.map[x][y] = map[y][x];
	}
	return (fdf);
}

#endif
