/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:05:20 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 21:39:12 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[11];
	char	last;
	int		len;
	int		ltz;
	int		i;

	ltz = (n < 0);
	last = (n % 10) * ft_bool2sign(!ltz) + '0';
	n /= ft_bool2sign(!ltz) * 10;
	len = ft_log10((unsigned long long)(n)) + 1 + (n != 0) + ltz;
	i = len - 1;
	buf[0] = '-';
	buf[i] = last;
	while (--i >= ltz)
	{
		buf[i] = (n % 10) + '0';
		n /= 10;
	}
	write (fd, buf, len);
}

/* this logic is virtually identical to ft_itoa, only with a stack array
 * containing the longest possible string to output with this data type
 * we first write to the fixed buffer, then write it out to fd
 * using the pre-calculated length
*/
