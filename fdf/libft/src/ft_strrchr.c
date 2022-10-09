/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:59:31 by ikarjala          #+#    #+#             */
/*   Updated: 2021/12/16 20:33:09 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*last;

	ptr = (char *)(s - 1);
	last = NULL;
	while (*++ptr != '\0')
		if (*ptr == c)
			last = ptr;
	if (c == '\0')
		return (ptr);
	if (last == NULL)
		return (NULL);
	return ((char *)last);
}
