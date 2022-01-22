/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:43:10 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/22 16:03:11 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(int *fd, char **argv, char **envp)
{
	int	f1;

	f1 = open(argv[1], O_RDONLY, 0777);
	if (f1 == -1)
		ft_error();
	if (dup2(f1, STDIN_FILENO) == -1)
		ft_error();
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error();
	close(fd[0]);
	close(f1);
	close(fd[1]);
	execute(argv[2], envp);
}

void	ft_parent(int *fd, char **argv, char **envp)
{
	int	f2;

	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f2 == -1)
		ft_error();
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	if (dup2(f2, STDOUT_FILENO) == -1)
		ft_error();
	close(fd[1]);
	close(fd[0]);
	close(f2);
	execute(argv[3], envp);
}

void	ft_pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 < 0)
		ft_error();
	if (!pid1)
		ft_child(fd, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		ft_error();
	if (!pid2)
		ft_parent(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		ft_pipex(argv, envp);
	else
		write(1, "Wrong number of arguments!\n", 28);
	return (0);
}
