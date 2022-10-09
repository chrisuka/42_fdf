/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:43:44 by ikarjala          #+#    #+#             */
/*   Updated: 2021/12/17 17:06:11 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	char	*p1;
	char	*p2;

	p1 = (char *)(s1 - 1);
	p2 = (char *)(s2 - 1);
	while (*++p1 == *++p2 && *p1 != '\0')
		continue ;
	return ((unsigned char)*p1 - (unsigned char)*p2);
}
