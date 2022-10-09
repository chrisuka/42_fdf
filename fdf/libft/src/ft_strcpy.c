/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:44:18 by ikarjala          #+#    #+#             */
/*   Updated: 2022/03/18 03:06:24 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*p_dst;

	if (!dst && !src)
		return (NULL);
	p_dst = dst;
	while (*src != '\0')
		*p_dst++ = *src++;
	*p_dst = '\0';
	return (dst);
}
