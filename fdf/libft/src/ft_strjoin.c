/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:26:17 by ikarjala          #+#    #+#             */
/*   Updated: 2021/11/24 15:57:16 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cat;
	char	*p1;
	char	*p2;

	if (!s1 || !s2)
		return (NULL);
	cat = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!cat)
		return (NULL);
	p1 = (char *)s1;
	p2 = (char *)cat;
	while (*p1 != 0)
		*p2++ = *p1++;
	p1 = (char *)s2;
	while (*p1 != 0)
		*p2++ = *p1++;
	*p2 = 0;
	return (cat);
}
