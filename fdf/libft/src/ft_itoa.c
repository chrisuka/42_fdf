/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:16:51 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 22:12:16 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return malloced string representing int n
 * first, get the least significant digit of n with modulo (%)
 * then divide it by 10 or -10 to avoid integer overflow while
 * forcing it into a + sign, this will make it easier to get the other digits
 * Set the first char to '-', if n is positive
 * we will overwrite it with a digit later
*/
char	*ft_itoa(int n)
{
	char	*str;
	char	last;
	int		len;
	int		ltz;

	ltz = (n < 0);
	last = (n % 10) * ft_bool2sign(!ltz) + '0';
	n /= ft_bool2sign(!ltz) * 10;
	len = ft_log10((unsigned long long)(n)) + 1 + (n != 0) + ltz;
	str = (char *)malloc(sizeof(char) * (size_t)(len + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[len] = 0;
	str[--len] = last;
	while (--len >= ltz)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* log10(n) + 1 gives us the amount of digits in the integer
 * we increase the length by ltz to account for the minus character
 * we also need to account for the last digit which we cut earlier
 * finally, we need to allocate len + 1 to account for the null terminator
*/
