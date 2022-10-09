/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:44:00 by ikarjala          #+#    #+#             */
/*   Updated: 2022/03/23 20:54:33 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcut(t_list **alst, size_t start, size_t count,
	void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*tail;
	t_list	*temp;

	if (count == 0 || !alst)
		return (-1);
	head = ft_lstn(*alst, start);
	tail = head->next;
	if (start == 0)
		tail = head;
	while (count-- > 0 && tail)
	{
		temp = tail->next;
		del(tail->content, tail->content_size);
		free(tail);
		tail = temp;
	}
	head->next = tail;
	if (start == 0)
		*alst = tail;
	return (0);
}
