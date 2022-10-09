/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:45:04 by ikarjala          #+#    #+#             */
/*   Updated: 2021/11/14 09:56:58 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)((char *)(s1 - 1));
	p2 = (unsigned char *)((char *)(s2 - 1));
	while (n-- > 0 && *++p1 == *++p2)
		continue ;
	return (*p1 - *p2);
}
