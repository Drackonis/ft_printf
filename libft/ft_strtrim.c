/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:39 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/27 17:39:26 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == 0) && j > i)
		j--;
	if (!(str = ft_strnew(j - (i - 1))))
		return (NULL);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
/*
**int    main(int argc, char **argv)
**{
**       argc++;
**       char *str1 = argv[1];
**       str1 = ft_strtrim(str1);
**       printf("%s", str1);
**       return (0);
**}
*/
