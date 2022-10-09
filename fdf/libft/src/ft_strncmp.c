/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:19:08 by ikarjala          #+#    #+#             */
/*   Updated: 2021/11/13 18:59:45 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)(s1 - 1);
	p2 = (char *)(s2 - 1);
	while (n-- > 0 && *++p1 == *++p2 && *p1 != '\0')
		continue ;
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
