/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:37:09 by saragar2          #+#    #+#             */
/*   Updated: 2024/06/24 17:37:11 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pp
{
	int		pipefd[2];
	pid_t	pid[2];
	int		fd_in;
	int		fd_out;
	char	*exec;
	char	**com;
}				t_pp;

void 	print_error(char *arg);
char	*check_com(char *com, char **envp);
void	cpid1(t_pp g, char **argv, char **envp);
void	cpid2(t_pp g, char **argv, char **envp);

#endif
