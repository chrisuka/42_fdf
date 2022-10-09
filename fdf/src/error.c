/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:40:07 by ikarjala          #+#    #+#             */
/*   Updated: 2022/10/09 20:40:53 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	perr_badmap(char *fname)
{
	const char	del[] = " : ";
	const char	msg[] = CREDB "parser error.\n" CNIL;

	ft_putstr_fd(fname, 2);
	write (2, del, sizeof(del) - 1);
	write (2, msg, sizeof(msg) - 1);
	return (XC_ERROR);
}

int	perr_internal(void)
{
	const char	msg[] = CREDB "Internal error!"
		" Try downloading more RAM.\n" CNIL;

	write (2, msg, sizeof(msg) - 1);
	return (EINTERNAL);
}
