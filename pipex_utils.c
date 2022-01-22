/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:43:04 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/22 14:09:44 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(1);
}

static void	ft_free(char **dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
}

char	*parsing(char **envp, char *line)
{
	char	*paths;
	char	*pathscmd;
	char	**mypaths;
	int		i;

	i = 0;
	while (envp[i] != NULL && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	if (envp[i] == NULL)
		ft_error();
	paths = envp[i];
	mypaths = ft_split(paths + 5, ':');
	i = 0;
	while (mypaths && mypaths[i++])
	{
		pathscmd = ft_strjoin(mypaths[i], line);
		if (access(pathscmd, 0) == 0)
		{
			ft_free(mypaths);
			return (pathscmd);
		}
	}
	ft_free(mypaths);
	return (NULL);
}

void	execute(char *str, char **envp)
{
	char	**cmd;
	char	*line;

	cmd = ft_split(str, ' ');
	line = ft_strjoin ("/", cmd[0]);
	if (execve(parsing(envp, line), cmd, envp) == -1)
		ft_error();
	free(line);
	exit(0);
}
