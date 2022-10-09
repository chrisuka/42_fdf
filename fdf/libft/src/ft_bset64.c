/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bset64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:14:20 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 21:21:43 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bset64(void *b, uint64_t quad, size_t len)
{
	uint64_t		*quadp;
	unsigned char	uchr;

	uchr = (unsigned char)(quad);
	while (len % sizeof(quad) != 0)
	{
		((unsigned char *)(b))[len] = uchr;
		len --;
	}
	quadp = (uint64_t *)(b + len - sizeof(quadp));
	while (len >= sizeof(quad))
	{
		len -= sizeof(quad);
		*(--quadp) = quad;
	}
	return (b);
}
