/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:12:02 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 19:43:06 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	i = 0;
	j = 0;
	k = 0;
	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (!(s1))
			return (ft_strdup(s2));
		return (ft_strdup(s2));
	}
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == 0)
		return (NULL);
	while (s1[i])
		dst[k++] = s1[i++];
	while (s2[j])
		dst[k++] = s2[j++];
	dst[k] = '\0';
	return ((char *)dst);
}
