/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:12:02 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/14 19:27:47 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	len_dst;
	size_t	i;

	i = 0;
	dst = malloc(count * size);
	if (dst == 0)
		return (NULL);
	len_dst = count * size;
	while (i < len_dst)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
