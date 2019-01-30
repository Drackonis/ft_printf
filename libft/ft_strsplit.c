/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:59:25 by rkergast          #+#    #+#             */
/*   Updated: 2018/11/28 18:42:16 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	**ft_split_parts(char **str, char const *s, char c)
{
	int	i;
	int	n;
	int	t;

	i = 0;
	n = 0;
	t = 0;
	while (s[i])
	{
		if (t == 1 && s[i] == c)
			t = 0;
		if (t == 0 && s[i] != c)
		{
			t = 1;
			n++;
		}
		i++;
	}
	if (n == 0)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	str[n] = NULL;
	return (str);
}

static char	**ft_split_len(char **str, char const *s, char c)
{
	int	i;
	int	n;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n = 0;
			while (s[i] != c && s[i])
			{
				n++;
				i++;
			}
			if (!(str[w] = (char *)malloc(sizeof(char) * (n + 1))))
				return (NULL);
			str[w][n] = '\0';
			w++;
		}
	}
	return (str);
}

static char	**ft_fill_str(char **str, char const *s, char c)
{
	int	i;
	int	t;
	int	w;

	i = 0;
	t = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
			{
				str[w][t] = s[i];
				i++;
				t++;
			}
			str[w][++t] = '\0';
			t = 0;
			w++;
		}
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	char	*c1;

	c1 = "";
	str = NULL;
	i = 0;
	j = 0;
	if (!(s == NULL || c == 0))
		while (s[i] != '\0')
			if (s[i++] != c)
				j++;
	if (j == 0 || s == NULL || c == 0 || s == c1)
	{
		if (!(str = (char **)malloc(sizeof(char *))))
			return (NULL);
		str[0] = NULL;
		return (str);
	}
	if ((str = ft_split_parts(str, s, c)))
		if ((str = ft_split_len(str, s, c)))
			if ((str = ft_fill_str(str, s, c)))
				return (str);
	return (NULL);
}
/*
**int    main()
**{
**	int	i = 0;
**	char **argv = ft_strsplit(NULL, 0);
**	printf("OK\n");
**	while (argv[i])
**	{
**		if (argv[i])
**			printf("%s\n", argv[i]);
**		i++;
**	}
**	return (0);
**}
*/
