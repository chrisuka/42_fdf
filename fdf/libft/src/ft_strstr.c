/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:32:42 by ikarjala          #+#    #+#             */
/*   Updated: 2022/03/18 03:01:06 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
			if (needle[probe + 1] == '\0')
				return (sweep);
			probe++;
		}
		sweep++;
	}
	return (NULL);
}
