/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:00:28 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/02 19:25:50 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	uint64_t	*qwordp;
	uint64_t	quad;
	uint8_t		uchr;

	uchr = (unsigned char)(c);
	if (len > sizeof(quad))
	{
		quad = (uint64_t)(uchr);
		quad |= (quad << (__CHAR_BIT__ << 0));
		quad |= (quad << (__CHAR_BIT__ << 1));
		quad |= (quad << (__CHAR_BIT__ << 2));
		qwordp = &b[len];
		while (len >= sizeof(quad))
		{
			len -= sizeof(quad);
			*(--qwordp) = quad;
		}
	}
	while (len-- > 0)
		((unsigned char *)(b))[len] = uchr;
	return (b);
}
