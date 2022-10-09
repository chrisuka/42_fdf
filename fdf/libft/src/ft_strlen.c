/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:12:43 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 00:14:43 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline	uint64_t	catch_bits(uint64_t quad)
{
	const uint64_t	himagic = 0x80808080ULL | (0x80808080ULL << 32);
	const uint64_t	lomagic = 0x01010101ULL | (0x01010101ULL << 32);

	return ((quad - lomagic) & (~quad & himagic));
}

size_t	ft_strlen(const char *s)
{
	uint64_t		*quadp;
	unsigned char	*cp;

	cp = (unsigned char *)(s);
	while (((uint64_t)(cp) & (sizeof(uint64_t) - 1)) != 0)
	{
		if (*cp == '\0')
			return ((size_t)(cp - (unsigned char *)(s)));
		cp++;
	}
	quadp = (uint64_t *)(cp);
	while (catch_bits (*quadp) == 0)
		quadp++;
	cp = (unsigned char *)(quadp);
	while (*cp != '\0')
		cp++;
	return ((size_t)(cp - (unsigned char *)(s)));
}
