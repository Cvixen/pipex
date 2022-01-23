/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:39 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/23 19:11:27 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_child(int *fd, char *limited)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, limited, ft_strlen(line) - 1) == 0)
		{
			close(fd[0]);
			close(fd[1]);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		line = get_next_line(0);
	}
}

void	here_doc(char *limited)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 < 0)
		ft_error();
	if (!pid1)
		here_doc_child(fd, limited);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error();
	wait(0);
	close(fd[1]);
	close(fd[0]);
}

int	here_doc_branch(int argc, char **argv, int *f2)
{
	int	i;

	i = 3;
	*f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	if ((*f2) < 0)
		ft_error();
	here_doc(argv[2]);
	return (i);
}

int	many_command_branch(int argc, char **argv, int *f2)
{
	int	i;
	int	f1;

	i = 2;
	f1 = open(argv[1], O_RDONLY, 0777);
	if ((f1) < 0)
		ft_error();
	*f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if ((*f2) < 0)
		ft_error();
	if ((dup2((f1), STDIN_FILENO)) == -1)
		ft_error();
	close(f1);
	return (i);
}

int	main(int argc, char **argv, char **envp)
{	
	int	i;
	int	f2;

	i = 0;
	if (argc >= 5)
	{
		if (argc == 6 && (ft_strncmp(argv[1], "here_doc", 8)) == 0)
			i = here_doc_branch(argc, argv, &f2);
		else
			i = many_command_branch(argc, argv, &f2);
		while (i < argc - 2)
			ft_pipex(argv[i++], envp);
		do_many_command(f2, argv, envp, i);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments!\n", 1);
		exit(0);
	}
}
