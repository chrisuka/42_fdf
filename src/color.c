/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:58:53 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 17:35:25 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Combine Red, Green, Blue and Alpha channels into 1 integer (4 * 8 bits)
 * Note that the order is actually ARGB because it makes more sense for math
 * All channels are taken as 32-bit integers and not casted so be careful.
*/
unsigned int	rgba_hex(int r, int g, int b, int a)
{
	return (a << (__CHAR_BIT__ * 3)
		| r << (__CHAR_BIT__ * 2)
		| g << (__CHAR_BIT__ * 1)
		| b);
}
