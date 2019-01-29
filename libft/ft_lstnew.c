/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:57:36 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/28 19:01:38 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n;
	void	*c;
	size_t	s;

	if (!(n = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(c = (void*)malloc(sizeof(void) * content_size)))
			return (NULL);
		s = content_size;
		ft_memcpy(c, content, content_size);
		n->content = c;
		n->content_size = s;
	}
	else
	{
		n->content = NULL;
		n->content_size = 0;
	}
	n->next = NULL;
	return (n);
}
