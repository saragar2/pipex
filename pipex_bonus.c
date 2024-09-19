/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:59:45 by saragar2          #+#    #+#             */
/*   Updated: 2024/09/19 19:59:51 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	f_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		cont = (unsigned char)*s1 - (unsigned char)*s2;
	return (cont);
}

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
	dup2(g.pipefd[1], STDOUT_FILENO);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	execve(g.exec, g.com, envp);
	print_error("error executing first command");
}

void	cpidmid(t_pp g, char **argv, int i, char **envp)
{
	while (argv[i] && ((*argv[i] >= 9 && *argv[i] <= 13) || *argv[i] == 32))
		argv[i]++;
	if (*argv[i] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[i], ' ');
	g.exec = check_com(g.com[0], envp);
	dup2(g.prev_pipefd[0], STDIN_FILENO);
	dup2(g.pipefd[1], STDOUT_FILENO);
	close(g.prev_pipefd[0]);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	execve(g.exec, g.com, envp);
	print_error("Error executing intermediate command");
}

void	cpid2(t_pp g, int argc, char **argv, char **envp)
{
	int	i;

	i = argc - 2;
	while (argv[i] && ((*argv[i] >= 9 && *argv[i] <= 13) || *argv[i] == 32))
		argv[i]++;
	if (*argv[i] == '\0')
		print_error("Empty argument");
	g.com = ft_split(argv[i], ' ');
	g.exec = check_com(g.com[0], envp);
	g.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (g.fd_out < 0)
		print_error("error opening or creating fd_out");
	dup2(g.prev_pipefd[0], STDIN_FILENO);
	dup2(g.fd_out, STDOUT_FILENO);
	close(g.pipefd[0]);
	close(g.fd_out);
	execve(g.exec, g.com, envp);
	print_error("error executing second command");
}
