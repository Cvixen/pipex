/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:26:39 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/10 22:03:02 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src + j));
}
