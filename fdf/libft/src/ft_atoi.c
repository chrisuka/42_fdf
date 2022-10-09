/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:59:37 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 22:10:21 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		nb;
	char	sign;
	char	*cp;
	char	*beg;

	cp = (char *)(str);
	while (ft_isspace(*cp))
		cp++;
	if (!(*cp == '-' || ft_isdigit(*cp) || *cp == '+'))
		return (0);
	sign = *cp;
	cp += !ft_isdigit(*cp);
	nb = 0;
	while (*cp == '0')
		cp++;
	beg = cp;
	while (ft_isdigit(*cp))
		nb = nb * 10 + (*cp++ - '0');
	if (cp - beg >= 19)
		return (-(sign != '-'));
	return (nb * ft_bool2sign (sign != '-'));
}
