/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:12:02 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/10 15:41:17 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest = malloc(sizeof(char));
		if (dest == 0)
			return (0);
	}
	else
	{
		if (ft_strlen(s) - start >= len)
			dest = malloc(sizeof(char) * (len + 1));
		else
			dest = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (dest == 0)
			return (0);
		while (s[start] && len--)
			dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}
