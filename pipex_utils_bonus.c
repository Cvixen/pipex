/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:59 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/23 14:56:19 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_many_command(int f2, char **argv, char **envp, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error();
	if (!pid)
	{
		if (dup2(f2, STDOUT_FILENO) == -1)
			ft_error();
		close(f2);
		execute(argv[i], envp);
	}
	waitpid(pid, NULL, 0);
}

void	ft_pipex(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 < 0)
		ft_error();
	if (!pid1)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_error();
		close(fd[1]);
		execute(cmd, envp);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	close(fd[0]);
	close(fd[1]);
}
