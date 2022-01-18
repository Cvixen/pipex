/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:12:02 by cvixen            #+#    #+#             */
/*   Updated: 2021/10/11 16:43:23 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_strlen(int n)
{
	int	k;

	k = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		k++;
	}	
	if (n < 0)
		k++;
	return (k);
}

static char	*exeption(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (0);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;

	if (n == -2147483648 || n == 0)
		return (exeption(n));
	i = digit_strlen(n);
	dst = malloc(sizeof(char) * i + 1);
	if (dst == 0)
		return (0);
	dst[i] = '\0';
	if (n < 0)
	{
		dst[0] = '-';
		n *= -1;
	}		
	while (n)
	{
		dst[--i] = n % 10 + '0';
		n = n / 10;
	}
	return (dst);
}
