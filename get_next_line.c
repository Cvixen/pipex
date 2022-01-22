/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:52:12 by cvixen            #+#    #+#             */
/*   Updated: 2021/11/09 15:14:30 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_has_linebreak(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*trim_linebreak(char *remainder)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	line = ft_strdup(remainder);
	if (line == 0)
		return (NULL);
	while (remainder[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
	j = 0;
	while (remainder[i + j])
	{
		remainder[j] = remainder[i + j];
		j++;
	}
	remainder[j] = '\0';
	return (line);
}

char	*read_line(char *remainder, int fd, int read_symbol)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!is_has_linebreak(remainder))
	{
		read_symbol = read(fd, buff, BUFFER_SIZE);
		if (read_symbol < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_symbol] = '\0';
		if (read_symbol == 0)
			break ;
		remainder = ft_strjoin(remainder, buff);
		if (remainder == 0)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (remainder);
}

void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = 0;
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	remainder = read_line(remainder, fd, 0);
	if (!remainder)
		return (0);
	if (is_has_linebreak(remainder))
	{
		line = trim_linebreak(remainder);
		if (line == 0)
		{
			free_remainder(&remainder);
			return (NULL);
		}
		if (*remainder == '\0')
			free_remainder(&remainder);
	}
	else
	{
		line = remainder;
		remainder = 0;
	}
	return (line);
}
