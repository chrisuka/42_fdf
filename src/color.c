/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:58:53 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/01 22:07:45 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Combine Red, Green, Blue and Alpha channels into 1 integer (4 * 8 bits)
 * Note that the order is actually ARGB because it makes more sense for math
 * All channels are taken as 32-bit integers and not casted so be careful.
*/
unsigned int	rgba_hex(int r, int g, int b, int a)
{
	return (a << (__CHAR_BIT__ * 3) |
			r << (__CHAR_BIT__ * 2) |
			g << (__CHAR_BIT__ * 1) |
			b);
}

/* Create an ARGB integer from Hue, Saturation and Value
 * using color space conversion
*/
unsigned int	hsv_hex(float h, float s, float v)
{
	h = 0;
	s = 0;
	v = 0;
	return (rgba_hex(
			255,
			255,
			255,
			0));


	/*	Whatever this means..
	C = V × S
	X = C × (1 - | (H / 60°) mod 2 - 1|)
	m = V - C
	(R, G, B) = ((R'+ m) ×255, (G'+ m) ×255, (B'+ m) ×255)
	*/
}
