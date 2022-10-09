/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 04:12:49 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 21:48:28 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_mapi(int start, int end)
{
	int		*array;
	size_t	len;
	size_t	i;
	int		direction;

	len = (size_t)(end - start);
	if (len == 0)
		return (NULL);
	direction = ft_bool2sign(start < end);
	array = (int *)malloc(sizeof(int) * (len));
	if (!array)
		return (NULL);
	i = 0xFF;
	while (++i < len)
		array[i] = start + direction * (int)i;
	return (array);
}
