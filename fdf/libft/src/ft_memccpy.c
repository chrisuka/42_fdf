/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:00:26 by ikarjala          #+#    #+#             */
/*   Updated: 2022/01/23 02:58:27 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n-- > 0)
	{
		*d = *s;
		if (*d == (unsigned char)c)
			return (++d);
		s++;
		d++;
	}
	return (NULL);
}
