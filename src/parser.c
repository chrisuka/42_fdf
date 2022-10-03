/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/03 22:03:10 by ikarjala         ###   ########.fr       */
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
	fdf.amplitude = 0.25f;
	fdf.scale = 25;
	fdf.projection = 1;
	return (fdf);
}

#if 0

static int	parse_line(char *line, int y)
{
	t_list	*wordl;
	t_list	*node;
	int		x;

	// first, scan for illegal characters, return error
	
	wordl = ft_memsplit(line, " ", get_lrinfo().len);
	x = 0;
	while (node != NULL)
	{
		map[x][y] = ft_atoi(node->content);
		++ x;
		node = node->next;
		free (wordl);
		worldl = node;
	}
	return (x);
}

t_fdf	parse_map_file(char *fname)
{
	t_fdf	fdf;
	int		y;
	
	fdf = initialize_fdf_data();
	fd = open (fname, O_RDONLY);
	if (fd < 0)
		return (-1);
	y = 0;
	while (get_next_line(fd, &line) != RET_EOF)
	{
		if (parse_line (line, y++) != fdf.w)
			return (-1);
	}
	// MAP NEEDS TO KNOW THE HEIGHT BEFORE MALLOCING, DAMMIT...
	//fdf.map = (int **)malloc(sizeof(int *) * fdf.h);
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
