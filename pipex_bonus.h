/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:42:52 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/22 12:45:33 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

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

#endif
