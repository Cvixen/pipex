/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:42:13 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/14 19:58:40 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	if (!s)
		return (0);
	dst = ft_strdup(s);
	if (dst == 0)
		return (NULL);
	i = 0;
	while (dst[i])
	{
		dst[i] = (*f)(i, dst[i]);
		i++;
	}
	return (dst);
}
