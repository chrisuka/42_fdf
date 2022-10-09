/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:21:36 by ikarjala          #+#    #+#             */
/*   Updated: 2022/09/29 21:45:02 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, const char *del)
{
	size_t	wc;
	int		in_word_now;
	int		in_word_bef;

	if (!s)
		return (0);
	wc = 0;
	in_word_now = FT_FALSE;
	in_word_bef = FT_FALSE;
	while (*s != '\0')
	{
		in_word_now = !ft_strchr(del, *s);
		wc += (!in_word_bef && in_word_now);
		in_word_bef = in_word_now;
		s++;
	}
	return (wc);
}
