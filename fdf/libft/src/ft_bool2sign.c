/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool2sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:42:03 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/26 17:53:06 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Remaps boolean value b into a sign of 1 or -1
 * 0 becomes -1 and any non-zero value becomes 1
*/
int	ft_bool2sign(int b)
{
	return (1 | -!b);
}
