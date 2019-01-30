/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:18 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/21 15:33:08 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r;
	t_list	*tr;
	t_list	*tl;

	if (lst == NULL || f == NULL)
		return (NULL);
	tl = f(lst);
	if ((r = ft_lstnew(tl->content, tl->content_size)))
	{
		tr = r;
		lst = lst->next;
		while (lst)
		{
			tl = (*f)(lst);
			if (!(tr->next = ft_lstnew(tl->content, tl->content_size)))
				return (NULL);
			tr = tr->next;
			lst = lst->next;
		}
	}
	return (r);
}
