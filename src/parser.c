/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:41:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/23 16:12:56 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline int	parse_index(char *s)
{
	int	val;

	val = 0;
	s = NULL;
	/*
	while (ft_isdigit(*s))
		val = val * 10 + (*s - '0');
		*/
	return (val);
}

int	parse_map_file(char *fname)
{
	//const size_t	buff_size = 128;
	//char	buf[buff_size];
	//ssize_t	rb;
	int		fd;
	
	//fd = open(fname, RD_RDONLY);
	fd = parse_index(fname);
	fname = NULL;
	return (0);
	/*
	while (rb = read(fd, buf, buff_size))
	{
		
	}
	*/
}
