/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:04:07 by ikarjala          #+#    #+#             */
/*   Updated: 2022/08/25 15:45:54 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline const char	*get_delim(void)
{
	return (" \n\t");
}

char	*ft_strtrim(const char *s)
{
	size_t	len;
	t_uint	index;
	t_uint	start;
	t_uint	end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && ft_strchr(get_delim(), s[start]))
		start++;
	end = start;
	index = start;
	while (s[index] != '\0')
	{
		if (!ft_strchr(get_delim(), s[index]))
			end = index;
		index++;
	}
	len = (size_t)(end - start + (start != end));
	return (ft_strsub(s, start, len));
}
