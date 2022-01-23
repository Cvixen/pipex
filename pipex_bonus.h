/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:52 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/23 19:09:38 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "pipex.h"

# define BUFFER_SIZE 1

char	*parsing(char **envp, char *line);
void	execute(char *str, char **envp);
void	ft_error(void);
void	here_doc(char *limited);
int		is_has_linebreak(char *str);
char	*trim_linebreak(char *remainder);
void	ft_exit(void);
char	*get_next_line(int fd);
void	here_doc_child(int *fd, char *limited);
void	do_many_command(int f2, char **argv, char **envp, int i);
int		many_command_branch(int argc, char **argv, int *f2);
int		here_doc_branch(int argc, char **argv, int *f2);
void	ft_pipex(char *cmd, char **envp);

#endif
