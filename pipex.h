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
	int		aux_argc;
	int		curr_arg;
	int		pipefd[2];
	int		prev_pipefd[2];
	pid_t	pid[3];
	int		fd_in;
	int		fd_out;
	char	*exec;
	char	**com;
}				t_pp;

void	print_error(char *arg);
void	for_mid(int argc, char **argv, t_pp g, char **envp);
void	cpid1(t_pp g, char **argv, char **envp);
void	cpid2(t_pp g, int argc, char **argv, char **envp);
void	cpidmid(t_pp g, char **argv, int i, char **envp);
int		f_strcmp(const char *s1, const char *s2);

#endif
