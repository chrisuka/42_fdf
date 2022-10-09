/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:49:36 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 00:22:19 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Let's use special "magic" bitsets,
 * designed to filter 0-bytes in a cluster of bytes;
 * https://graphics.stanford.edu/~seander/bithacks.html#ZeroInWord
 *
 * When we subtract it from the quad (8 chars) the binary addition will cause
 * 1-bits in a byte to get carried towards the 'holes' (0s) which act as
 * indicators that in this specific byte we found something.
 * 
 * quad - 0x01.. outputs high bits set in all bytes where = 0 or > 128 (0x80)
 * quad's complement reverses it's bits, ANDing this with 0x80.. will give
 * us high bits set in bytes where it was not set so the value was < 0x80
 * we use the latter to filter out values over 128 (1 over std ascii max)
 * because we only want the zeroes. We do this by ANDing the subexpressions.
 * If it evaluates to a non-zero value, there is a zero in one of the bytes.
*/
static inline uint64_t	catch_bits(uint64_t quad)
{
	const uint64_t	himagic = 0x80808080ULL | (0x80808080ULL << 32);
	const uint64_t	lomagic = 0x01010101ULL | (0x01010101ULL << 32);

	return ((quad - lomagic) & (~quad & himagic));
}

static inline char	*seek_char_in_quad(uint64_t *quadp, unsigned char c)
{
	unsigned char	*cp;
	unsigned int	n;

	cp = (unsigned char *)(quadp);
	n = 0;
	while (n++ < sizeof(quadp))
	{
		if (*cp == c)
			return ((char *)(cp));
		else if (*cp == 0)
			return (NULL);
		cp++;
	}
	return (NULL);
}

/* Quad-optimized strchr implementation:
 * first, read one byte at a time until we are aligned on a quad boundary
 * then, iterate over 8 bytes (64 bits) at a time, checking with
 * a bitwise hack if there is a zero-byte in the cluster
 * bitwise XOR the quad by the "cccc" mask to replace the "c" bytes
 * with zeroes and use the same logic to look for "c".
 * Lastly, find out which byte the "c" or 0 was in via simple iteration.
*/
char	*ft_strchr(const char *s, int c)
{
	uint64_t	*quadp;
	uint64_t	qword;
	uint64_t	cmask;
	uint8_t		uchr;

	uchr = (unsigned char)(c);
	while (((uint64_t)(s) & (sizeof(uint64_t) - 1)) != 0)
	{
		if (*s == uchr)
			return ((char *)(s));
		else if (*s == 0)
			return (NULL);
		++ s;
	}
	cmask = (uint64_t)(uchr | uchr << (__CHAR_BIT__));
	cmask |= cmask << (__CHAR_BIT__ << 1);
	cmask |= cmask << (__CHAR_BIT__ << 2);
	quadp = (uint64_t *)(s);
	qword = *quadp;
	while (catch_bits(qword) == 0
		&& catch_bits(qword ^ cmask) == 0)
			qword = *(++quadp);
	return (seek_char_in_quad(quadp, uchr));
}
