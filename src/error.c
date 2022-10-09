/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:40:07 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 19:50:12 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	perr_badmap(char *fname)
{
	const char	msg[] = CREDB "parser error.\n" CNIL;

	ft_putstr_fd(fname, 2);
	write (2, " : ", 3);
	write (2, msg, sizeof(msg) - 1);
	return (XC_ERROR);
}
