/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:01 by ikarjala          #+#    #+#             */
/*   Updated: 2021/12/13 20:22:33 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	newnode = f(lst);
	if (!newnode)
		return (NULL);
	newnode->next = ft_lstmap(lst->next, f);
	if (!newnode->next && lst->next)
		ft_memdel((void **)newnode);
	return (newnode);
}
