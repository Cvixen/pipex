/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:39 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/17 16:47:40 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_exit(void)
{
	write(1, "Wrong number of arguments!\n", 28);
	exit(0);
}

void	ft_child(int *fd, char *cmd, char **envp)
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error();
	close(fd[0]);
	close(fd[1]);
	execute(cmd, envp);
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
		ft_child(fd, cmd, envp);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	int	i;

	i = 2;
	if (argc >= 5)
	{
		f1 = open(argv[1], O_RDONLY, 0777);
		if (f1 < 0)
			ft_error();
		f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (f2 < 0)
			ft_error();
		if ((dup2 (f1, STDIN_FILENO)) == -1)
			ft_error();
		while (i < argc - 2)
			ft_pipex(argv[i++], envp);
		if ((dup2 (f2, STDOUT_FILENO)) == -1)
			ft_error();
		close(f1);
		close(f2);
		execute(argv[i], envp);
	}
	ft_exit();
}
