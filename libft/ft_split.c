/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:12:02 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 15:49:54 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

static void	ft_free_all(char **arr, int n)
{
	n = n - 1;
	while (n >= 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr);
}

static char	**ft_write(char **arr, char c, char const *s)
{
	int		start;
	int		len;
	int		n;

	len = 0;
	n = 0;
	while (*s && *s == c)
		s++;
	while (s[len])
	{
		start = len;
		while (s[len] && s[len] != c)
			len++;
		arr[n] = ft_substr(s, start, len - start);
		if (arr[n] == NULL)
		{
			ft_free_all(arr, n);
			return (NULL);
		}
		n++;
		while (s[len] && s[len] == c)
			len++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!arr)
		return (NULL);
	arr[ft_words(s, c)] = 0;
	return (ft_write(arr, c, s));
}
