/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 18:05:53 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define BUFF_SIZE	128

t_fdf	initialize_fdf_data(void)
{
	t_fdf	fdf;

	fdf.map = NULL;
	fdf.w = 0;
	fdf.h = 0;
	fdf.xpos = 0;
	fdf.ypos = 0;
	fdf.amplitude = 4;
	fdf.scale = 50;
	fdf.projection = 0;
	return (fdf);
}

#if 0
/* Find out how many rows there are and check
 * that the amount of columns is consistent,
 * then return the fd or -1 in case of error
*/
static inline int	open_validate(char *fname, t_fdf *fdf)
{
	char	buf[BUFF_SIZE];
	ssize_t	rb;
	int		fd;
	char	*cp;
	
	fd = open(fname, RD_RDONLY);
	rb = read(fd, buf, BUFF_SIZE);
	if (rb > 0)
	{
		cp = ft_memchr(buf, '\n', BUFF_SIZE)
		while (cp)
		{
			cp = ft_memchr(cp + 1, '\n', sizeof(buf) - (cp - buf));
			fdf->h += (cp != NULL);
		}
	}
	close (fd);
	fd = open(fname, RD_RDONLY);
	return (fd);
}

t_fdf	parse_map_file(char *fname)
{
	t_fdf	fdf;
	t_list	*wordl;
	int		fd;
	int		x;
	int		y;
	
	fdf = initialize_fdf_data();
	fd = open_validate(fname, &fdf);
	if (fd < 0)
		return (-1);
	fdf.map = (int **)malloc(sizeof(int *) * fdf.h);
	// read until EOF
	// strsplit, count words
	// foreach word, atoi
	y = 0;
	while (y < fdf.h)
	{
		wordl = ft_memsplit(buf, " ", "\n", BUFF_SIZE);
		x = 0;
		while (x < fdf.w)
		{
			fdf.map[x][y] = ft_atoi(wordl->content);
			x ++;
		}
		if (fdf->w != ft_lstlen(wordl));
			// return -1
		ft_lstdel (wordl);
		y ++;
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
