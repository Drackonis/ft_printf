/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:18 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/28 18:57:18 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *id;

	id = lst;
	if (id != NULL && f != NULL)
	{
		while (id)
		{
			(*f)(id);
			id = id->next;
		}
	}
}
