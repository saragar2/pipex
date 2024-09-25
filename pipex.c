/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:37:14 by saragar2          #+#    #+#             */
/*   Updated: 2024/08/28 14:37:16 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_com(char *com, char **envp)
{
	int		i;
	int		j;
	char	**routes;
	char	*new_com;

	i = 0;
	j = -1;
	if (ft_strchr(com, '/'))
		return (com);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == 0)
		return (com);
	envp[i] += 5;
	routes = ft_split(envp[i], ':');
	while (routes[++j])
	{
		new_com = ft_strjoin(routes[j], "/");
		new_com = ft_strjoin(new_com, com);
		if (access(new_com, X_OK) == 0)
			return (new_com);
	}
	return (com);
}

void	cpid1(t_pp g, char **argv, char **envp)
{
	while (argv[2] && ((*argv[2] >= 9 && *argv[2] < 13) || *argv[2] == 32))
		argv[2]++;
	if (*argv[2] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[2], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_in = open(argv[1], O_RDONLY);
	if (g.fd_in < 0)
		print_error("error opening fd_in");
	else if (g.pid[0] == 0)
	{
		dup2(g.pipefd[1], STDOUT_FILENO);
		dup2(g.fd_in, STDIN_FILENO);
		close(g.pipefd[0]);
		close(g.pipefd[1]);
		close(g.fd_in);
		execve(g.exec, g.com, envp);
		print_error("error executing first command");
	}
}

void	cpid2(t_pp g, int argc, char **argv, char **envp)
{
	while (argv[3] && ((*argv[3] >= 9 && *argv[3] <= 13) || *argv[3] == 32))
		argv[3]++;
	if (*argv[3] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[3], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (g.fd_out < 0)
		print_error("error opening or creating fd_out");
	else if (g.pid[1] == 0)
	{
		dup2(g.pipefd[0], STDIN_FILENO);
		dup2(g.fd_out, STDOUT_FILENO);
		close(g.pipefd[0]);
		close(g.pipefd[1]);
		close(g.fd_out);
		execve(g.exec, g.com, envp);
		print_error("error executing second command");
	}
}
