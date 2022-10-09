/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:56:31 by ikarjala          #+#    #+#             */
/*   Updated: 2022/03/24 16:35:28 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*sweep;
	size_t	probe;

	if (!haystack && !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	sweep = (char *)haystack;
	while (*sweep != '\0')
	{
		probe = 0;
		while (needle[probe] == sweep[probe])
		{
			if ((size_t)(&sweep[probe] - haystack) >= len)
				return (NULL);
			if (needle[probe + 1] == '\0')
				return (sweep);
			probe++;
		}
		sweep++;
	}
	return (NULL);
}
