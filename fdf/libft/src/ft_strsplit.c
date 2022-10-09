/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:30:12 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/02 16:24:23 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**populate(char **array, const char *s,
				const char *del, size_t a_size)
{
	size_t	a_itr;
	size_t	len;

	len = 0;
	a_itr = -1UL;
	while (++a_itr < a_size)
	{
		s = ft_strword(s, del, &len);
		array[a_itr] = (char *)ft_memdup(s, len);
		if (!array[a_itr])
		{
			ft_freearray((void **)&array, a_itr);
			return (NULL);
		}
		s += len;
	}
	return (array);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**array;
	char	del[2];
	size_t	a_wc;

	if (!s)
		return (NULL);
	del[0] = c;
	del[1] = 0;
	a_wc = ft_wordcount(s, del);
	array = (char **)ft_memalloc(sizeof(char *) * (a_wc + 1));
	if (!array)
		return (NULL);
	return (populate(array, s, (const char *)del, a_wc));
}
