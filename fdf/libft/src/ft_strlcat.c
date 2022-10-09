/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:42:44 by ikarjala          #+#    #+#             */
/*   Updated: 2022/03/24 16:35:11 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	result;
	char	*ps;

	if (!dst && !src)
		return (0);
	len = 0;
	while (*dst++ != '\0')
		len++;
	if (len >= dstsize)
		result = ft_strlen((char *)src) + dstsize;
	else
		result = len + ft_strlen((char *)src);
	dst--;
	ps = (char *)src;
	while (*ps != '\0' && len + 1 < dstsize)
	{
		*dst++ = *ps;
		len++;
		ps++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (result);
}
